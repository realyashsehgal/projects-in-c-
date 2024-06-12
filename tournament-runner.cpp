#include <iostream>
#include <conio.h>
#include <vector>
#include <unistd.h>
using namespace std;
vector<int> GroupA;
vector<int> GroupB;
vector<int> Wteams;
int match_maker(int teamsA);
int display(int teamsA);
int main()
{
    int tourney_winner = -1;
    int teams;
    cout << "***********************************************************TOURNAMENT***********************************************************\n\n\n"
         << endl;
    cout << "PLease enter the number of teams you want to make fight for victory\n\n"
         << endl;
    cin >> teams;
    cout << "The grouping of the teams is done as follows\n"
         << endl;
    cout << "Group A will have the first " << teams / 2 << " and the Group B will have the other " << teams / 2 << endl;
    int teamsA = teams / 2;
    int teamsB = teams;
    // creating groupa
    for (int i = 1; i <= teamsA; i++)
    {
        GroupA.push_back(i);
    }
    // creating groupb
    for (int i = teamsA + 1; i <= teamsB; i++)
    {
        GroupB.push_back(i);
    }
    while (tourney_winner == -1)
    {
        match_maker(teamsA);
        system("cls");
        display(teamsA);
        teamsA/=2;
        getch();
    }
    getch();
    return 0;
}

int display(int teamsA)
{
    cout << "GROUP  A" << endl;
    for (int i = 0; i < teamsA; i++)
    {
        cout << GroupA[i] << endl;
    }
    cout << "\n\nGROUP  B" << endl;
    for (int i = 0; i < teamsA; i++)
    {
        cout << GroupB[i] << endl;
    }
    getch();
    return 0;
}

int match_maker(int teamsA)
{
    int itr;
    while (itr <= teamsA)
    {
        // group a fight
        srand(time(0));
        int win_team = rand() % 2;
        cout << win_team << endl;
        if (win_team == 0)
        {
            Wteams.push_back(GroupA[itr]);
        }
        if (win_team == 1)
        {
            Wteams.push_back(GroupA[itr + 1]);
        }
        itr += 2;
        sleep(1);
    }
    GroupA = Wteams;
    getch();
    return 0;
}
