using namespace std;

class Roulette
{
public:
    vector<pair<string, int>> players;
    vector<int> bets;
    vector<int> nums;
    vector<char> symbols;
    int row_pos = 10;
    int col_pos = 10;

    ///outside down
    int row_pos_outside = 25; ///same row for all
    int col_pos_even = 20;
    int col_pos_odd = 50;
    int col_pos_red = 30;
    int col_pos_black = 40;
    int col_pos_one = 10;
    int col_pos_eight = 60;

    ///outside 12s
    int col_pos_outside = 70; ///same col for all outside bets
    int row_pos_first = 10;
    int row_pos_second = 15;
    int row_pos_third = 20;

    COLORS color_tile_backgr = GREEN;
    COLORS color_tile_fonts = WHITE;

    Roulette(vector<pair<string, int>> p)
    {
        for(int i =0; i < p.size(); i++)
        {
            players.push_back(p[i]);
        }
    }

    ///LOGIC
    void print_info();

    ///what money do you want to bet
    void choose_bets();
    void print_bets();

    ///choose if you want to bet on inside or outside bet
    void choose_inside_outside();

    ///choose inside bet
    void choose_inside_bet(int player_index);
    void print_nums();

    ///choose outside bet
    void choose_outside_bet(int player_index);
    void print_symbols();

    void remove_player(string name);
    void check_money();
    ///INSIDE BETS
    void draw_inside_bets(int number, char let[7]);
    void print_inside_bets();
    ///OUTSIDE BETS DOWN
    void draw_outside_bets_down();
    ///OUTSIDE BETS 12S
    void draw_outside_bets_12();
    ///PRINT ALL OUTSIDE BETS
    void print_outside_bets();
    ///THE ROULETTE
    void generate_rand_number();
    void draw_roulette();

};

///name and money
void Roulette::print_info()
{
    for(int i = 0; i < players.size(); i++)
    {
        cout << "\t\t\t\t" << "Player " << players[i].first << " has " << players[i].second << " money. " << endl;
    }
}

///CHOOSE THE MONEY YOU WANT TO BET
void Roulette::choose_bets()
{
    int money;

    bets.clear();

    if(!DEV)
    {
        for(int i = 0; i < players.size(); i++)
        {
            cout << "\t\t\t\t" << players[i].first << " choose what money do you bet: ";
            cin >> money;
            bets.push_back(money);
        }
    }
    else
    {
        bets.push_back(20);
        bets.push_back(50);
    }
}

void Roulette::print_bets()
{
    for(int i = 0; i < bets.size(); i++)
    {
        cout << "\t\t\t\t" << players[i].first << " bets " << bets[i] << endl << endl;
    }
}

///CHOOSE WHAT YOU BET ON THE TABLE
void Roulette::choose_inside_outside()
{
    char choice;

    nums.clear();

    for(int i = 0; i < players.size(); i++)
    {
        cout << "\t\t\t\t" << players[i].first << " you want to bet on inside or outside (type 'i' and 'o'): ";
        cin >> choice;
        if(choice == 'i')
        {
            choose_inside_bet(i);
        }
        if(choice == 'o')
        {
            choose_outside_bet(i);
        }
    }
}

void Roulette::choose_inside_bet(int player_index)
{
    int number;

    if(!DEV)
    {
        cout << "\t\t\t\t" << players[player_index].first << " choose a number to bet on: ";
        cin >> number;
        nums.push_back(number);
    }
    else
    {
        nums.push_back(7);
    }
}

void Roulette::choose_outside_bet(int player_index)
{
    int number_out;

    if(!DEV)
    {
        cout << "\t\t\t\t 37 - 1 to 18" << endl;
        cout << "\t\t\t\t 38 - EVEN" << endl;
        cout << "\t\t\t\t 39 - RED" << endl;
        cout << "\t\t\t\t 40 - BLACK" << endl;
        cout << "\t\t\t\t 41 - ODD" << endl;
        cout << "\t\t\t\t 42 - 19 to 36" << endl;
        cout << "\t\t\t\t 43 - 3rd12" << endl;
        cout << "\t\t\t\t 44 - 2nd12" << endl;
        cout << "\t\t\t\t 45 - 1st12" << endl;
        cout << endl;
        cout << "\t\t\t\t" << players[player_index].first << " choose a number to bet on (from 37 to 45): ";
        cin >> number_out;
        nums.push_back(number_out);
        system("cls");
    }
    else
    {
        nums.push_back(41);
    }
}

void Roulette::print_nums()
{
    for(int i = 0; i < nums.size(); i++)
    {
        cout << "\t\t\t\t" << players[i].first << " bets on " << nums[i] << endl << endl;
    }
}

void Roulette::remove_player(string name)
{
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i].first == name)
        {
            players.erase(players.begin() + i);
            bets.erase(bets.begin() + i);
            nums.erase(nums.begin() + i);
        }
    }
}

void Roulette::check_money()
{
    string name;
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i].second <= 0)
        {
            remove_player(players[i].first);
        }
    }
}

///DRAW INSIDE
void Roulette::draw_inside_bets(int number, char let[7])
{
    int rows = 5;
    int cols = 5;

    char temp = ' ';

    char table[rows][cols] =
    {
        "-----",
        "|&&&|",
        "|@#&|",
        "|&&&|",
        "-----"
    };

    ///replace & with letters in table tile and delete the &
    for(int i = 0; i < 7; i++)
    {
        if(table[1][1] == '&')
        {
            table[1][1] = let[i];
        }
        else if(table[1][2] == '&')
        {
            table[1][2] = let[i];
        }
        else if(table[1][3] == '&')
        {
            table[1][3] = let[i];
        }
        else if(table[2][3] == '&')
        {
            table[2][3] = let[i];
        }
        else if(table[3][1] == '&')
        {
            table[3][1] = let[i];
        }
        else if(table[3][2] == '&')
        {
            table[3][2] = let[i];
        }
        else if(table[3][3] == '&')
        {
            table[3][3] = let[i];
        }
    }

    ///check the tile
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            temp = table[i][j];
            ///check if the number is one digit or two
            if(table[i][j] == '#' || table[i][j] == '@')
            {
                if(number < 10)
                {
                    if(table[i][j] == '#')
                    {
                        temp = number + '0';
                    }
                    if(table[i][j] == '@')
                    {
                        temp = ' ';
                    }
                }
                else
                {
                    if(table[i][j] == '#')
                    {
                        temp = number%10 + '0';
                    }
                    if(table[i][j] == '@')
                    {
                        temp = number/10 + '0';
                    }
                }
            }
            draw_char(temp, i+row_pos, j+col_pos, color_tile_fonts, color_tile_backgr);
        }
     }
}

void Roulette::print_inside_bets()
{
    system("cls");
    //char letters[7] = {'*','*','*','*','*','*','*'};
    char letters[7] = {' ',' ',' ',' ',' ',' ',' '};
    string name;
    int br = 0;

    for(int i = 1; i < 37; i++)
    {
        ///Null the letters
        for(int k =0; k < 7; k++)
        {
            letters[k] = ' ';
        }
        br = 0;
        ///the numbers you bet on
        for(int j = 0; j < nums.size(); j++)
        {
            if(i == nums[j])
            {
                cout << "i: " << i << endl;
                name = players[j].first;
                letters[br] = name[0]; ///take the first letter of the name
                br++;
            }
        }

        ///change the color
        if(i % 2 == 0)
        {
            color_tile_backgr = RED;
        }
        else
        {
            color_tile_backgr = BLACK;
        }

        ///for check
        /*for(int k =0; k < 7; k++)
        {
            letters[k] = ' ';
        }*/

        draw_inside_bets(i, letters);
        col_pos+=5;
        ///print the board on 3 rows
        if(i == 12)
        {
            row_pos = 15;
            col_pos = 10;
        }
        else if(i == 24)
        {
            row_pos = 20;
            col_pos = 10;
        }
    }
}

///DRAW OUTSIDE
void Roulette::draw_outside_bets_down()
{

    ///TODO - SEE IN DISCORD THE LOGIC OF THE FUNCTION
    ///size for even and odd
    int rows = 5;
    int cols = 10;

    char temp_e = ' ';
    char temp_o = ' ';
    char temp_r = ' ';
    char temp_b = ' ';
    char temp_1 = ' ';
    char temp_19 = ' ';

    char even[rows][cols] =
    {
        "----------",
        "|&&&&&&&&|",
        "|&&EVEN&&|",
        "|&&(38)&&|",
        "----------"
    };
    char odd[rows][cols] =
    {
        "----------",
        "|&&&&&&&&|",
        "|&&ODD&&&|",
        "|&&(41)&&|",
        "----------"
    };
    char red[rows][cols] =
    {
        "----------",
        "|&&&&&&&&|",
        "|&&RED&&&|",
        "|&&(39)&&|",
        "----------"
    };
    char black[rows][cols] =
    {
        "----------",
        "|&&&&&&&&|",
        "|&BLACK&&|",
        "|&&(40)&&|",
        "----------"
    };
    char one_to_eighteen[rows][cols] =
    {
        "----------",
        "|&&&&&&&&|",
        "|&1to18&&|",
        "|&&(37)&&|",
        "----------"
    };
    char nineth_to_thsix[rows][cols] =
    {
        "----------",
        "|&&&&&&&&|",
        "|&19to36&|",
        "|&&(42)&&|",
        "----------"
    };


    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            temp_e = even[i][j];
            temp_o = odd[i][j];

            temp_r = red[i][j];
            temp_b = black[i][j];

            temp_1 = one_to_eighteen[i][j];
            temp_19 = nineth_to_thsix[i][j];

            if(even[i][j] == '&')
            {
                temp_e = ' ';
            }
            if(odd[i][j] == '&')
            {
                temp_o = ' ';
            }
            if(red[i][j] == '&')
            {
                temp_r = ' ';
            }
            if(black[i][j] == '&')
            {
                temp_b = ' ';
            }
            if(one_to_eighteen[i][j] == '&')
            {
                temp_1 = ' ';
            }
            if(nineth_to_thsix[i][j] == '&')
            {
                temp_19 = ' ';
            }
            draw_char(temp_e, i+row_pos_outside, j+col_pos_even, WHITE, LIGHT_GREEN);
            draw_char(temp_o, i+row_pos_outside, j+col_pos_odd, WHITE, LIGHT_GREEN);
            draw_char(temp_r, i+row_pos_outside, j+col_pos_red, WHITE, RED);
            draw_char(temp_b, i+row_pos_outside, j+col_pos_black, WHITE, BLACK);
            draw_char(temp_1, i+row_pos_outside, j+col_pos_one, WHITE, LIGHT_GREEN);
            draw_char(temp_19, i+row_pos_outside, j+col_pos_eight, WHITE, LIGHT_GREEN);
        }
    }

}

void Roulette::draw_outside_bets_12()
{
    int rows = 5;
    int cols = 9;

    char temp_f = ' ';
    char temp_s = ' ';
    char temp_t = ' ';

    char first[rows][cols] =
    {
        "---------",
        "|&&&&&&&|",
        "|&1st12&|",
        "|&(45)&&|",
        "---------"
    };
    char second[rows][cols] =
    {
        "---------",
        "|&&&&&&&|",
        "|&2nd12&|",
        "|&(44)&&|",
        "---------"
    };
    char third[rows][cols] =
    {
        "---------",
        "|&&&&&&&|",
        "|&3rd12&|",
        "|&(43)&&|",
        "---------"
    };

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            temp_f = first[i][j];
            temp_s = second[i][j];
            temp_t = third[i][j];

            if(first[i][j] == '&')
            {
                temp_f = ' ';
            }
            if(second[i][j] == '&')
            {
                temp_s = ' ';
            }
            if(third[i][j] == '&')
            {
                temp_t = ' ';
            }
            draw_char(temp_f, i+row_pos_first, j+col_pos_outside, WHITE, LIGHT_GREEN);
            draw_char(temp_s, i+row_pos_second, j+col_pos_outside, WHITE, LIGHT_GREEN);
            draw_char(temp_t, i+row_pos_third, j+col_pos_outside, WHITE, LIGHT_GREEN);
        }
    }

}

void Roulette::print_outside_bets()
{
    draw_outside_bets_down();
    draw_outside_bets_12();
}

void Roulette::generate_rand_number()
{
    int money_win;
    int rand_n = rand()%45;

    for(int n = 0; n < nums.size(); n++)
    {
        cout << "Rand number: " << rand_n << endl;
        if(rand_n == nums[n])
        {
            cout << "MATCHED" << endl;
            ///if the number is matched the bet is *15
            ///if the outside bet is matched is *2
        }
    }
}




