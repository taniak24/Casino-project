using namespace std;

void menu(int& choice)
{
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t Choose a game: \n\t\t\t\t\t\t" << endl;

    cout << "\t\t\t\t\t\t 1. War" << endl << endl;
    cout << "\t\t\t\t\t\t 2. Black jack" << endl << endl;
    cout << "\t\t\t\t\t\t 3. Roulette" << endl << endl;

    cout << "\t\t\t\t\t\t Enter your choice: \n\t\t\t\t\t\t";
    cin >> choice;

    switch(choice)
    {
    case 1:
        cout << "war";
        break;
    case 2:
        cout << "Black jack";
        break;
    case 3:
        cout << "Roulette";
        break;
    default:
        cin >> choice;

    }
}
