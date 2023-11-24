class War
{
public:
    int player1;
    int player2;

    War(int p1, int p2)
    {
        player1 = p1;
        player2 = p2;
    }

    ///fill the vector cards
    void shuffle_cards(vector<Card>& card, vector<Card>& human_cards, vector<Card>& pc_cards);
    ///draw the vector cards
    void draw_cards(vector<Card>& human_cards, vector<Card>& pc_cards);

    ///Normal play functions
    int check_win(char c1, char c2);
    void update_win(int result, vector<Card>& human_take, vector<Card>& pc_take, vector<Card>& human_cards, vector<Card>& pc_cards);
    void draw_take_cards(vector<Card>& human_take, vector<Card>& pc_take, vector<Card>& human_cards, vector<Card>& pc_cards);

    ///WAR functions
    void draw_cards_after_war(vector<Card>& human_cards, vector<Card>& pc_cards);
    int check_win_war(char c1, char c2, vector<Card>& human_cards, vector<Card>& pc_cards);
    void update_war_win(int result, vector<Card>& human_take, vector<Card>& pc_take, vector <Card>& human_cards, vector <Card>& pc_cards);
};

void War::shuffle_cards(vector<Card>& card, vector<Card>& human_cards, vector<Card>& pc_cards)
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
    for(int i = 0; i<player1; i++)
    {
        human_cards.push_back(card[i]);
        pc_cards.push_back(card[i+player1]);
    }
}

void War::draw_cards(vector<Card>& human_cards, vector<Card>& pc_cards)
{
    ///human print cards
    for(int i = 0; i < human_cards.size(); i++)
    {
        human_cards[i].draw_back(5, 2+i*6); ///from class Card
    }

    ///pc print cards
    for(int i = 0; i < pc_cards.size(); i++)
    {
        pc_cards[i].draw_back(35, 2+i*6);
    }

    ///the cards you put in the middle
    human_cards[human_cards.size() - 1].draw(20, 70);
    pc_cards[pc_cards.size() - 1].draw(20, 80);
}

int War::check_win(char c1, char c2)
{
    ///convert char to int for ascii
    ///from 2-9 - 50-57
    ///J - 74
    ///Q - 81
    ///K - 75
    ///A - 65

    int code1 = int(c1);
    int code2 = int(c2);

    ///war
    if(code1 == code2)
    {
        return 0; ///TIE
    }

    ///check between 2 - 9
    if((code1 >= 50 && code1 <= 57) && (code2 >= 50 && code2 <= 57))
    {
        if(code1 > code2)
        {
            return 1; ///player 1 wins
        }
        else
        {
            return 2; ///player 2 wins
        }
    }

    ///check for A
    if(code1 == 65 || code2 == 65)
    {
        if(code1 == 65)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    ///check for K
    if(code1 == 75 || code2 == 75)
    {
        if(code1 == 75)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    ///check for Q
    if(code1 == 81 || code2 == 81)
    {
        if(code1 == 81)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    ///check for J
    if(code1 == 74 || code2 == 74)
    {
        if(code1 == 74)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    ///check for 10
    if(code1 == 48 || code2 == 48)
    {
        if(code1 == 48)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    return 0;
}

///the winner gets the folded cards
void War::update_win(int result, vector<Card>& human_take, vector<Card>& pc_take, vector<Card>& human_cards, vector<Card>& pc_cards)
{
    if(result == 1)
    {
        human_take.insert(human_take.begin(), human_cards[human_cards.size() - 1]);
        human_take.insert(human_take.begin(), pc_cards[pc_cards.size() - 1]);
    }
    else
    {
        pc_take.insert(pc_take.begin(), human_cards[human_cards.size() - 1]);
        pc_take.insert(pc_take.begin(), pc_cards[pc_cards.size() - 1]);
    }

    human_cards.pop_back();
    pc_cards.pop_back();

    return;
}

///draw the cards when you take them
void War::draw_take_cards(vector<Card>& human_take, vector<Card>& pc_take, vector<Card>& human_cards, vector<Card>& pc_cards)
{
    for(int i = 0; i < human_take.size(); i++)
    {
        human_take[i].draw(12, 2+i*6);
    }
    for(int i = 0; i < pc_take.size(); i++)
    {
        pc_take[i].draw(28, 2+i*6);
    }
}

///print the three cards after war
void War::draw_cards_after_war(vector<Card>& human_cards, vector<Card>& pc_cards)
{
    human_cards[human_cards.size() - 1].draw(20, 58);
    human_cards[human_cards.size() - 2].draw(20, 64);
    human_cards[human_cards.size() - 3].draw(20, 70);


    pc_cards[pc_cards.size() - 1].draw(20, 80);
    pc_cards[pc_cards.size() - 2].draw(20, 86);
    pc_cards[pc_cards.size() - 3].draw(20, 92);
}

void War::update_war_win(int result, vector<Card>& human_take, vector<Card>& pc_take, vector <Card>& human_cards, vector <Card>& pc_cards)
{
    if(result == 1)
    {
        human_take.insert(human_take.begin(), human_cards[human_cards.size() - 1]);
        human_take.insert(human_take.begin(), human_cards[human_cards.size() - 2]);
        human_take.insert(human_take.begin(), human_cards[human_cards.size() - 3]);

        human_take.insert(human_take.begin(), pc_cards[pc_cards.size() - 1]);
        human_take.insert(human_take.begin(), pc_cards[pc_cards.size() - 2]);
        human_take.insert(human_take.begin(), pc_cards[pc_cards.size() - 3]);
    }
    else
    {
        pc_take.insert(pc_take.begin(), human_cards[human_cards.size() - 1]);
        pc_take.insert(pc_take.begin(), human_cards[human_cards.size() - 2]);
        pc_take.insert(pc_take.begin(), human_cards[human_cards.size() - 3]);

        pc_take.insert(pc_take.begin(), pc_cards[pc_cards.size() - 1]);
        pc_take.insert(pc_take.begin(), pc_cards[pc_cards.size() - 2]);
        pc_take.insert(pc_take.begin(), pc_cards[pc_cards.size() - 3]);
    }

    /*
    for(int i = human_cards.size() - 1; i >= human_cards.size() - 3; i--)
    {
        human_cards.pop_back();
    }

    for(int j = pc_cards.size() - 1; j >= pc_cards.size() - 3; j--)
    {
        pc_cards.pop_back();
    }*/

    return;
}

