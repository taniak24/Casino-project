class Black_jack
{
public:
    int player1;
    int dealer;

    Black_jack(int p1, int d)
    {
        player1 = p1;
        dealer = d;
    }

    ///fill the vector cards
    void shuffle_cards(vector<Card>& card, vector<Card>& player_cards, vector<Card>& dealer_cards);
    ///draw the deck
    void draw_deck(vector<Card>& card);
    ///draw the player cards
    void draw_player_cards(vector<Card>& player_cards);
    void draw_dealer_cards(vector<Card>& dealer_cards);
    ///the values and the sum of the cards
    int counter(char c);
    void count_player_cards(vector<Card>& player_cards, int&score1);
    void count_dealer_cards(vector<Card>& dealer_cards, int& score_d);
    ///OPTIONS:
    ///hitting
    /*
    bool choice();*/
    void player_add(vector<Card>& card, vector<Card>& player_cards, bool& check);
    void dealer_add(vector<Card>& card, vector<Card>& dealer_cards, int points);

};

void Black_jack::shuffle_cards(vector<Card>& card, vector<Card>& player_cards, vector<Card>& dealer_cards)
{
    for(int i = 2; i <= 14; i++) ///Card type
    {
        for(int j = 0; j <= 3; j++) ///Card color
        {
            card.push_back(Card(Card_type(i), Card_color(j)));
        }
    }

    ///shuffle the cards
    random_shuffle(card.begin(), card.end());

    ///fill human cards
    for(int i = card.size()-1; i >= card.size() - player1; i--)
    {
        player_cards.push_back(card[i]);
        //dealer_cards.push_back(card[i+player1]);
        //if there is an error uncomment and delete from 49 to 52
    }
    card.pop_back();
    card.pop_back();

    ///fill dealer cards
    for(int j = card.size()-1; j >= card.size() - dealer; j--)
    {
        dealer_cards.push_back(card[j+dealer]);
    }
    card.pop_back();
    card.pop_back();

}

void Black_jack::draw_deck(vector<Card>& card)
{
    int j = 0;

    ///show all cards
    if(DEV)
    {
        for(int i = 0; i < card.size(); i++)
        {
            if(i < card.size()/2)
            {
                card[i].draw(5, 2+i*6);
            }
            else
            {
                card[i].draw(11, 2+j*6);
                j++;
            }
        }
        return;
    }
    else
    {
        for(int i = 0; i < card.size(); i++)
        {
            card[i].draw_back(15, 53);
        }
    }
    ///else show hidden deck
}

void Black_jack::draw_player_cards(vector<Card>& player_cards)
{
    ///human print cards
    for(int i = 0; i < player_cards.size(); i++)
    {
        player_cards[i].draw(25, 35+i*6);
    }
}

void Black_jack::draw_dealer_cards(vector<Card>& dealer_cards)
{
    ///dealer print cards
    for(int i = 0; i < dealer_cards.size(); i++)
    {
        if(i == 0)
        {
            dealer_cards[i].draw_back(15, 35+i*6); ///draw back function
        }
        else if(i == 1)
        {
            dealer_cards[i].draw(15, 35+i*6);
        }
    }
}

int Black_jack::counter(char c)
{
    cout << c;
    int card_value;
    int ace;
    switch(c)
    {
        case '2':
            card_value = 2;
            break;
        case '3':
            card_value = 3;
            break;
        case '4':
            card_value = 4;
            break;
        case '5':
            card_value = 5;
            break;
        case '6':
            card_value = 6;
            break;
        case '7':
            card_value = 7;
            break;
        case '8':
            card_value = 8;
            break;
        case '9':
            card_value = 9;
            break;
        case 'A':
            card_value = 11; ///ASK IF 1 OR 11 (with cin<<)
            /*
            cout << "You want the Ace to be 1 or 11 points? ";
            cin >> ace;
            while(ace != 1 && ace != 11)
            {
                cout << "1 or 11 points, please! ";
                cin >> ace;
            }
            if(ace == 1)
            {
                card_value = 1;
            }
            if(ace == 11)
            {
                card_value = 11;
            }*/
            break;
        default:
            card_value = 10;
    }

    return card_value;
}

void Black_jack::count_player_cards(vector<Card>& player_cards, int& score1)
{
    char c;

    for(int i = 0; i < player_cards.size(); i++)
    {
        c = get_card_type_char(player_cards[i].get_card_type());
        score1+=counter(c);
    }
}

void Black_jack::count_dealer_cards(vector<Card>& dealer_cards, int& score_d)
{
    char c;

    for(int i = 0; i < dealer_cards.size(); i++)
    {
        c = get_card_type_char(dealer_cards[i].get_card_type());
        score_d+=counter(c);
    }
}

/*
bool Black_jack::choice()
{
    string answer_str;
    bool choice = false;

    cout << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t Add more cards? (Type 'yes or 'no')" << endl;
    cout << "\t\t\t\t\t\t";
    cin >> answer_str;

    if(answer_str == "yes")
    {
        choice = true;
    }

    return choice;
}*/

/*
void Black_jack::player_add(vector<Card>& player_cards, vector<Card>& card, int& score1)
{
    bool player_bust = false;
    bool black_jack = false;

    char c;

    int score_add = 0; ///set the old result to 0 and then refresh

    player_cards.push_back(card[card.size()-1]);
    card.pop_back();

    for(int i = 0; i < player_cards.size(); i++)
    {
        player_cards[i].draw(25, 35  +i*6);
        c = get_card_type_char(player_cards[i].get_card_type());
        score_add+=counter(c);
    }

    ///TODO - DELETE TO 237
        /*
        if(score_add == 21)
        {
            dealer_add();
        }
        if(score_add > 21)
        {
            dealer_add();
        }
        /*
        if(player_bust)
        {
            for(int i = 0; i < player_cards.size(); i++)
            {
                player_cards[i].draw_back(25, 35+i*6);
            }

    }

    score1 = score_add;

}*/

void Black_jack::player_add(vector<Card>& card, vector<Card>& player_cards, bool& check)
{
    string answer;

    cout << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t Add more cards? (Type 'yes or 'no')" << endl;
    cout << "\t\t\t\t\t\t";
    cin >> answer;

    if(answer == "yes")
    {
        player_cards.insert(player_cards.end(), card[card.size()-1]);
        card.pop_back();
        check = true;
    }
    else
    {
        check = false;
        return;
    }
}

void Black_jack::dealer_add(vector<Card>& card, vector<Card>& dealer_cards, int points)
{
    cout << "Dealer's turn";

    if(points < 17)
    {
        dealer_cards.insert(dealer_cards.end(), card[card.size() - 1]);
        card.pop_back();
    }
    else
    {
        cout << "the points are more than 17";
    }
}



