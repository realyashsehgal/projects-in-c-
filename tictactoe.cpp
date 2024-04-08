#include <iostream>
using namespace std;
char print(char arr[3][3])
{
    int i,j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
char check_win(char arr[3][3], int turn)
{
    int i;
    if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) && arr[0][0] != '*' ||
        (arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]) && arr[0][2] != '*')
    {
        if (turn % 2 == 0)
        {

            cout << "Player 1 won the game" << endl;
            return 1;
        }
        else
        {
            cout << "Player 2 won the game" << endl;
            return 2;
        }
    }
    // rows
    for (i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != '*')
        {
            if (turn % 2 == 0)
            {
                cout << "Player 1 won the game" << endl;
                return 1;
            }
            else
            {
                cout << "Player 2 won the game" << endl;
                return 2;
            }
        }
        else
        {
            continue;
        }
    }
    //   columns
    for (i = 0; i < 3; i++)
    {
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != '*')
        {
            if (turn % 2 == 0)
            {
                cout << "Player 1 won the game" << endl;
                return 1;
            }
            else
            {
                cout << "Player 2 won the game" << endl;
                return 2;
            }
        }
        else
        {
            continue;
        }
    }
    // draw
    bool board_full = true;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (arr[i][j] == '*')
            {
                board_full = false;
                break;
            }
        }
    }
    if (board_full == true)
    {
        cout << "It is  a draw" << endl;
    }
    return 0;
}
int main()
{
    char arr[3][3] = {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
    int turn, i, j;
    int choice;
    cout << "Lets play a game of tic tac toe two player game" << endl;
    cout << "Empty places in the board are displayed as '*'" << endl;
    int winner;
    turn = 1;
    do
    {
        print(arr);
        if (turn % 2 != 0) // player 1
        {
            cout << "Player 1 turn\n\n";
            cout << "Please select a postion from the board from the available options" << endl;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {

                    if (arr[i][j] == '*')
                    {
                        cout << "[" << i + 1 << "]"
                             << "[" << j + 1 << "]";
                    }
                }
                cout << ", ";
            }
            cout << "Please select your position as in x terms" << endl;
            cin >> i;
            cout << "Please select your position as in y terms" << endl;
            cin >> j;
            cout << "Your chosen postion " << i + 1 << j + 1;
            if (arr[i - 1][j - 1] == '*')
            {
                arr[i - 1][j - 1] = 'X';
                turn++;
            }
            else
            {
                cout << "\nPlease select a diffrent postion" << endl;
            }
            cout << endl;
        }
        else if (turn % 2 == 0)
        {
            cout << "Player 2 turn\n\n";
            cout << "Please select a postion from the board from the available options" << endl;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {

                    if (arr[i][j] == '*')
                    {
                        cout << "[" << i + 1 << "]"
                             << "[" << j + 1 << "]";
                    }
                }
                cout << ", ";
            }
            cout << "\nPlease select your position as in x terms" << endl;
            cin >> i;
            cout << "Please select your position as in y terms" << endl;
            cin >> j;
            cout << "Your chosen postion " << i << j;
            if (arr[i - 1][j - 1] == '*')
            {
                arr[i - 1][j - 1] = 'O';
                turn++;
            }
            else
            {
                cout << "\nPlease select a diffrent postion" << endl;
            }
            cout << endl;
        }
        else
        {
            continue;
        }
        winner = check_win(arr, turn);

        if (winner == 1)
        {
            print(arr);
            exit(0);
        }
        else if (winner == 2)
        {

           print(arr);
            exit(0);
        }
        else
        {
            continue;
        }
    } while (turn != 10);
    return 0;
}
