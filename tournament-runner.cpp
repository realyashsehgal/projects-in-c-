#include <iostream>
#include <conio.h>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
vector<int> teams;
vector<int> wteams;
vector<int> byes;
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
    // match_making(total_teams);
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
    vector<int> groupa;
    vector<int> groupb;
    vector<int> temp;
    temp = teams;
    int power = 1;
    int byer;
    while (power < total_teams)
    {
        power *= 2;
    }
    byer = power - total_teams;
    for (int i = 0; i < teams.size() / 2; i++)
    {
        groupa.push_back(teams[i]);
    }
    for (int i = teams.size() / 2; i < teams.size(); i++)
    {
        groupb.push_back(teams[i]);
    }
    int rear;
    if (byer % 2 == 0)
    {
        byes.push_back(groupa[0]);
        int rear = groupa.size() - 1;
        int target = byer / 2; 
        while (byer > target +1 && rear >= 0)
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
        while (byer > target+1 && front < groupb.size())
        {
            byes.push_back(groupb[front]);
            byer -= 1;
            front += 1;
        }
    }
    else
    {
        byes.push_back(groupa[0]);
        int rear = groupa.size() - 1;
        int target = byer / 2; 
        while (byer > target+1  && rear >= 0)
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
        while (byer > target+2 && front < groupb.size())
        {
            byes.push_back(groupb[front]);
            byer -= 1;
            front += 1;
        }
    }
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
    int itr = 0;
    cout << "Secondly now the non byes teams will compete" << endl;
    while (itr < teams.size())
    {
        cout << teams[itr] << " VS " << teams[itr + 1] << endl;
        itr += 2;
    }
    itr = 0;
    cout << "Firstly match will be held between the teams which were given byes" << endl;
    while (itr < byes.size())
    {
        cout << byes[itr] << " VS " << byes[itr + 1] << endl;
        itr += 2;
    }
    getch();
    return 0;
}
