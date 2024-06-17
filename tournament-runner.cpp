#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
vector<int> teams;
vector<int> wteamsa;
vector<int> wteamsb;
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
    system("cls");
    int win = rand() % 2;
    if(win == 0)
    {
        cout<<"The winner of this tournament is "<<groupa[0]<<endl;
    }
    else
    {
        cout<<"The winner of this tournament is "<<groupb[0]<<endl;
    }
    cout<<"Click any key to exit"<<endl;
    getch();
    return 0;
}
int display()
{
    for (int i = 0; i < teams.size(); i++)
    {
        cout << teams[i] << endl;
    }
    cout << "click to clear and move to matchmaking" << endl;
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
    if (byer == 1)
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
    return 0;
}
int match_making(int total_teams)
{
    vector<int> nonbye_a;
    vector<int> nonbye_b;
    vector<int> bye_a;
    vector<int> bye_b;
    srand(time(0));
    int rounds = 1;
    int total_byes = byes.size();
    int groupa_byes = total_byes - total_byes / 2;
    int groupb_byes = total_byes - groupa_byes;
    wteamsa = groupa;
    wteamsb = groupb;
    while (groupa.size() > 1 && groupb.size() > 1)
    {
        system("cls");
        int debug = 0;
        cout << "Rounds " << rounds << endl;
        bye_a.clear();
        bye_b.clear();
        wteamsb.clear();
        wteamsa.clear();
        getch();
        if (rounds == 1)
        {
            system("cls");
            cout << "The macthes which are going to take place in round " << rounds << " are as given group wise\n"
                 << endl;
            cout << "The competing teams from goup A are as follows" << endl;
            if (groupa_byes == 0)
            {
                for (int i = 0; i < groupa.size(); i += 2)
                {
                    cout << groupa[i] << " VS " << groupa[i + 1] << endl;
                    nonbye_a.push_back(groupa[i]);
                    nonbye_a.push_back(groupa[i + 1]);
                    int win = rand() % 2;
                    if (win == 0)
                    {
                        wteamsa.push_back(groupa[i]);
                    }
                    else
                    {
                        wteamsa.push_back(groupa[i + 1]);
                    }
                }
            }
            else
            {

                for (int i = 1; i < groupa.size() - (groupa_byes - 1); i += 2)
                {
                    cout << groupa[i] << " VS " << groupa[i + 1] << endl;
                    nonbye_a.push_back(groupa[i]);
                    nonbye_a.push_back(groupa[i + 1]);
                    int win;
                    if (win == 0)
                    {
                        wteamsa.push_back(groupa[i]);
                    }
                    else
                    {
                        wteamsa.push_back(groupa[i + 1]);
                    }
                    debug = 1;
                }
                if (debug == 0)
                {
                    wteamsa = groupa;
                }
            }
            cout << "The competing teams from goup B are as follows" << endl;
            if (groupb_byes == 0)
            {
                for (int i = 0; i < groupb.size(); i += 2)
                {
                    cout << groupb[i] << " VS " << groupb[i + 1] << endl;
                    nonbye_b.push_back(groupb[i]);
                    nonbye_b.push_back(groupb[i + 1]);
                    int win = rand() % 2;
                    if (win == 0)
                    {
                        wteamsb.push_back(groupb[i]);
                    }
                    else
                    {
                        wteamsb.push_back(groupb[i + 1]);
                    }
                }
            }
            else
            {

                for (int i = groupb_byes - 1; i < groupb.size() - 1; i += 2)
                {
                    cout << groupb[i] << " VS " << groupb[i + 1] << endl;
                    nonbye_b.push_back(groupb[i]);
                    nonbye_b.push_back(groupb[i + 1]);
                    int win = rand() % 2;
                    if (win == 0)
                    {
                        wteamsb.push_back(groupb[i]);
                    }
                    else
                    {
                        wteamsb.push_back(groupb[i + 1]);
                    }
                }
            }
            // finding byes in group A
            int flag;
            for (int i = 0; i < groupa.size(); i++)
            {
                for (int j = 0; j < nonbye_a.size(); j++)
                {

                    if (groupa[i] == nonbye_a[j])
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if (flag == 0)
                {
                    bye_a.push_back(groupa[i]);
                }
            }
            // finding byes in group A
            for (int i = 0; i < groupb.size(); i++)
            {
                for (int j = 0; j < nonbye_b.size(); j++)
                {

                    if (groupb[i] == nonbye_b[j])
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if (flag == 0)
                {
                    bye_b.push_back(groupb[i]);
                }
            }

            // // TEAM A WINNER DISTRIBUTION
            if (debug == 1)
            {

                groupa.clear();
                groupa = wteamsa;
                groupa.insert(groupa.end(), bye_a.begin(), bye_a.end());
                sort(groupa.begin(), groupa.end());
            }
            // // TEAM B WINNER DISTRIBUTION
            groupb.clear();
            groupb = wteamsb;
            groupb.insert(groupb.end(), bye_b.begin(), bye_b.end());
            sort(groupb.begin(), groupb.end());
        }
        else
        {
            system("cls");
            cout << "the teams competing for this round from group A are :" << endl;
            for (int i = 0; i < groupa.size(); i += 2)
            {
                cout << groupa[i] << " VS " << groupa[i + 1] << endl;
                nonbye_a.push_back(groupa[i]);
                nonbye_a.push_back(groupa[i + 1]);
                int win = rand() % 2;
                if (win == 0)
                {
                    wteamsa.push_back(groupa[i]);
                }
                else
                {
                    wteamsa.push_back(groupa[i + 1]);
                }
            }
            cout << "the teams competing for this round from group B are :" << endl;
            for (int i = 0; i < groupb.size(); i += 2)
            {
                cout << groupb[i] << " VS " << groupb[i + 1] << endl;
                nonbye_b.push_back(groupb[i]);
                nonbye_b.push_back(groupb[i + 1]);
                int win = rand() % 2;
                if (win == 0)
                {
                    wteamsb.push_back(groupb[i]);
                }
                else
                {
                    wteamsb.push_back(groupb[i + 1]);
                }
            }
            // finding byes in group A
            int flag;
            for (int i = 0; i < groupa.size(); i++)
            {
                for (int j = 0; j < nonbye_a.size(); j++)
                {

                    if (groupa[i] == nonbye_a[j])
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if (flag == 0)
                {
                    bye_a.push_back(groupa[i]);
                }
            }
            // finding byes in group A
            for (int i = 0; i < groupb.size(); i++)
            {
                for (int j = 0; j < nonbye_b.size(); j++)
                {

                    if (groupb[i] == nonbye_b[j])
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if (flag == 0)
                {
                    bye_b.push_back(groupb[i]);
                }
            }

            // // TEAM A WINNER DISTRIBUTION
            groupa.clear();
            groupa = wteamsa;
            groupa.insert(groupa.end(), bye_a.begin(), bye_a.end());
            sort(groupa.begin(), groupa.end());
            // // TEAM B WINNER DISTRIBUTION
            groupb.clear();
            groupb = wteamsb;
            groupb.insert(groupb.end(), bye_b.begin(), bye_b.end());
            sort(groupb.begin(), groupb.end());
        }
        getch();
        rounds++;
    }
    return 0;
}
