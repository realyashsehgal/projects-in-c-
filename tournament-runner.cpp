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
int display(int total_teams);
int byess(int total_teams);
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
    display(total_teams);
    system("cls");
    cout << "giving byes to the teams" << endl;
    byess(total_teams);
    system("cls");
    display(total_teams);
    getch();
    return 0;
}
int display(int total_teams)
{
    for (int i = 0; i < total_teams; i++)
    {
        cout << teams[i] << endl;
    }
    cout << "click to clear and exit" << endl;
    getch();
    return 0;
}
int byess(int total_teams)
{
    vector<int> temp;
    temp = teams;
    int power = 1;
    int byer;
    while (power < total_teams)
    {
        power *= 2;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    // cout<<"byes given will be "<< power - total_teams<<endl;
    // cout<<"click to exit"<<endl;
    byer = power - total_teams;
    shuffle(temp.begin(), temp.end(), e);
    for (int i = 0; i < byer; i++)
    {
        byes.push_back(temp[i]);
    }
    sort(byes.begin(), byes.end());
    cout << "displaying the byes" << endl;
    for (int i = 0; i < byer; i++)
    {
        cout << byes[i] << endl;
    }
    temp.clear();
    int flag;
    cout << "now new team without byes are" << endl;
    cout<<total_teams-byer<<endl;
    for (int i = 0; i < (total_teams - byer); i++)
    {
        for (int j = 0; j < byer; j++)
        {

            if (teams[i] == byes[j])
            {
                flag = 1;
            }
            else
            {
                continue;
            }
        }
        if (flag != 1)
        {
            temp.push_back(teams[i]);
        }
        flag = 0;
    }
    teams = temp;
    getch();
    return 0;
}
