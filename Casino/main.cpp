#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>

#include "global.h"
#include "draw_char.h"
#include "card.h"
#include "tile.h"
#include "war.h"
#include "black_jack.h"
#include "menu.h"
#include "roulette.h"

using namespace std;

int main()
{
    srand(time(0));
    set_background();

    int choice;

    menu(choice);

    ///FOR WAR
    if(choice == 1)
    {
        system("cls");
        vector<Card> card;
        vector<Card> human_cards;
        vector<Card> pc_cards;

        ///for win
        vector<Card> human_take;
        vector<Card> pc_take;

        ///the card that you give when you tap SPACE
        char givec_h;
        char givec_pc;
        int result;

        char c1, c2; ///card 1 and card 2
        char cw1, cw2; ///war third card

        War war(26, 26);

        ///print player cards
        war.shuffle_cards(card, human_cards, pc_cards);
        war.draw_cards(human_cards, pc_cards);

        while(true)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                //set_background(); ///clear the screen but slower
                system("cls"); ///clear the screen smooth

                ///the cards
                c1 = get_card_type_char(human_cards[human_cards.size()-1].get_card_type());
                c2 = get_card_type_char(pc_cards[pc_cards.size()-1].get_card_type());
                result = war.check_win(c1, c2);
                //cout << result;

                if(result != 0)
                {
                    war.update_win(result, human_take, pc_take, human_cards, pc_cards);
                    war.draw_take_cards(human_take, pc_take, human_cards, pc_cards);
                    war.draw_cards(human_cards, pc_cards);
                }

                ///for war
                if(result == 0)
                {
                    war.update_war_win(result, human_take, pc_take, human_cards, pc_cards);
                    war.draw_take_cards(human_take, pc_take, human_cards, pc_cards);
                    war.draw_cards(human_cards, pc_cards);
                    war.draw_cards_after_war(human_cards, pc_cards);
                }

                ///the third cards when there is WAR
                cw1 = get_card_type_char(human_cards[human_cards.size()-3].get_card_type());
                cw2 = get_card_type_char(pc_cards[pc_cards.size()-3].get_card_type());
                result = war.check_win(cw1, cw2);
                //war.update_war_win(result, human_take, pc_take, human_cards, pc_cards);
                cout << result;

                Sleep(100);
            }
        }
        return 0;
    }

    ///FOR BLACK JACK
    if(choice == 2)
    {
        system("cls");
        vector<Card> card;//vector for war too
        vector<Card> player_cards;
        vector<Card> dealer_cards;
        int score1 = 0;
        int score_d = 0;

        bool check = true;
        //int points;
        //int type_c;

        ///BLACK JACK START
        Black_jack bj(2, 2);

        bj.shuffle_cards(card, player_cards, dealer_cards);
        bj.draw_deck(card);
        bj.draw_player_cards(player_cards);
        bj.draw_dealer_cards(dealer_cards);

        bj.count_player_cards(player_cards, score1);
        bj.count_player_cards(dealer_cards, score_d);

         while(true)
         {
            cout << endl;
            cout << "Player score: " << score1 << endl;
            cout << "Dealer score: " << score_d << endl;

            bj.draw_deck(card);
            bj.draw_player_cards(player_cards);
            bj.draw_dealer_cards(dealer_cards);

            bj.player_add(card, player_cards, check);

            if(score1 > 21 || check == false)
            {
                system("cls");
                bj.draw_deck(card);
                bj.draw_player_cards(player_cards);
                bj.draw_dealer_cards(dealer_cards);
                break;
            }
            system("cls");

         }

         while(true)
         {
            cout << "Player score: " << score1 << endl;
            cout << "Dealer score: " << score_d << endl;

            bj.draw_deck(card);
            bj.draw_player_cards(player_cards);
            bj.draw_dealer_cards(dealer_cards);

            bj.dealer_add(card, dealer_cards, score_d);

            if(score_d >= 17)
            {
                system("cls");
                bj.draw_deck(card);
                bj.draw_player_cards(player_cards);
                bj.draw_dealer_cards(dealer_cards);
                Sleep(5000);
                break;
            }
            Sleep(500);
            system("cls");
         }


        return 0;

    }

    ///FOR ROULETTE
    if(choice == 3)
    {
        system("cls");
        vector<pair<string, int>> players;
        int players_count;
        string name;
        int money;
        int number;

        if(!DEV)
        {
            do
            {
                system("cls");
                cout << endl << endl << endl << endl << endl;
                cout << "\t\t\t\t How many players(max 7): ";
                cin >> players_count;
            }
            while(players_count > 7);

            for(int i = 0; i < players_count; i++)
            {
                cout << "\t\t\t\t Enter player name: ";
                cin >> name;
                cout << "\t\t\t\t Enter player money: ";
                cin >> money;
                players.push_back(make_pair(name, money));
            }

        }
        else
        {
            players.push_back(make_pair("Tania", 200));
            players.push_back(make_pair("Sonya", 400));
        }

        Roulette rlt(players);
        ///objects

        ///print the table
        /*
        rlt.print_inside_bets();
        rlt.print_outside_bets();*/

        rlt.choose_bets();
        rlt.choose_inside_outside();


        ///print the table again to refresh the bets
        rlt.print_inside_bets();
        rlt.print_outside_bets();
        rlt.print_nums();
        rlt.generate_rand_number();

        ///for remove
        /*
        rlt.remove_player("Tania");
        rlt.print_info();
        rlt.print_bets();*/

    }

}
