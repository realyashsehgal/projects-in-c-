#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> teams;
vector<int> wteams;
vector<int> byes;
vector<int> groupa;
vector<int> groupb;
int display();
int byess(int total_teams);
int match_making(int total_teams);
int main()
{
    int total_teams;
    cout << "****************tournament********************" << endl;
    cout << "Please enter the number of teams participating (should be even and positive)" << endl;
    cin >> total_teams;
    for (int i = 1; i <= total_teams; i++)
    {
        teams.push_back(i);
    }
    display();
    system("cls");
    cout << "giving byes to the teams" << endl;
    byess(total_teams);
    system("cls");
    match_making(total_teams);
    getch();
    return 0;
}
int display()
{
    for (int i = 0; i < teams.size(); i++)
    {
        cout << teams[i] << endl;
    }
    cout << "click to clear and exit" << endl;
    getch();
    return 0;
}
int byess(int total_teams)
{
    for (int i = 0; i < teams.size() / 2; i++)
    {
        groupa.push_back(teams[i]);
    }
    for (int i = teams.size() / 2; i < teams.size(); i++)
    {
        groupb.push_back(teams[i]);
    }
    int power = 1;
    int byer;
    while (power < total_teams)
    {
        power *= 2;
    }
    byer = power - total_teams;
    if (byer == 0)
    {
        return 0;
    }
    if(byer == 1)
    {
        byes.push_back(groupa[0]);
        return 0;
    }
    if (byer % 2 == 0)
    {
        byes.push_back(groupa[0]);
        int rear = groupa.size() - 1;
        int target = byer / 2;
        while (byer > target + 1 && rear >= 0)
        {
            byes.push_back(groupa[rear]);
            rear -= 1;
            byer -= 1;
        }
        byer = power - total_teams;
        target = byer / 2;
        rear = groupb.size() - 1;
        int front = 0;
        byes.push_back(groupb[rear]);
        while (byer > target + 1 && front < groupb.size())
        {
            byes.push_back(groupb[front]);
            byer -= 1;
            front += 1;
        }
    }
    else
    {
        int rear = groupa.size() - 1;
        int target = byer / 2;
        byes.push_back(groupa[0]);
        while (byer > target + 1 && rear >= 0)
        {
            byes.push_back(groupa[rear]);
            rear -= 1;
            byer -= 1;
        }
        byer = power - total_teams;
        target = byer / 2;
        rear = groupb.size() - 1;
        int front = 0;
        byes.push_back(groupb[rear]);
        while (byer > target + 2 && front < groupb.size())
        {
            byes.push_back(groupb[front]);
            byer -= 1;
            front += 1;
        }
    }
    sort(byes.begin(), byes.end());
    cout << "byes of groups " << endl;
    for (int i = 0; i < byes.size(); i++)
    {
        cout << byes[i] << endl;
    }
    getch();
    return 0;
}
int match_making(int total_teams)
{
    int rounds = 1;
    int total_byes = byes.size();
    int groupa_byes = total_byes - total_byes / 2;
    int groupb_byes = total_byes - groupa_byes;
    wteams = teams;
    if (byes.size() != 0)
    {
        // while(wteams.size() > 1)
        // {
        cout << "The macthes which are going to take place in round " << rounds << " are as given group wise" << endl;
        cout << "The competing teams from goup A are as follows" << endl;
        for (int i = 1; i < groupa.size() - (groupa_byes -1) ; i += 2)
        {
            cout << groupa[i] << " VS " << groupa[i + 1] << endl;
        }
        cout << "The competing teams from goup B are as follows" << endl;
        if(groupb_byes == 0 )
        {
        for (int i = 0; i < groupb.size() ; i += 2)
        {
            cout << groupb[i] << " VS " << groupb[i + 1] << endl;
        }
        }
        for (int i = groupb_byes - 1; i < groupb.size() - 1; i += 2)
        {
            cout << groupb[i] << " VS " << groupb[i + 1] << endl;
        }

        //     rounds --;
        // }
    }
    getch();
    return 0;
}
