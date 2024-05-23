#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include<iomanip>
using namespace std;
#define underline "\033[4m\033"
fstream file;
struct bus_data
{
    int bus_id;
    string bus_driver;
    string start;
    string end;
};
int Add_bus()
{
    bus_data entry;
    cout << "Please enter the bus id(NUMERIC ENTRY ONLY)" << endl;
    cin >> entry.bus_id;
    cout << "Please enter the name of the bus driver" << endl;
    cin >> entry.bus_driver;
    cout << "Please enter the station where the bus starts from" << endl;
    cin >> entry.start;
    cout << "Please enter the station where the bus journey will end" << endl;
    cin >> entry.end;
    file.open("bus data.txt", ios::app);
    file << entry.bus_id << "*" << entry.bus_driver << "*" << entry.start << "*" << entry.end << endl;
    file.close();
    return 0;
}
int Check_buses()
{
    file.open("bus data.txt", ios::in);
    string info;
    cout<<"\033[4mBus ID\t\tDriver's Name\t\tStarting point\t\tEnding point\033[0m"<<endl<<endl;;
    // string array[] = {"S.no","dirver name","starting point" , "end"};
    // printf("%4s,")]
    
    while(getline(file,info))
    {
        for(int i = 0 ; i < info.size(); i++)
        {
            if(info[i] == '*')
            {
                cout<<setw(20)<<right;
            }
            else
            {
                cout<<info[i];
            }
        }
        cout<<endl<<endl;
    }
    file.close();
    getch();
    return 0;
}
/*
BUS id = 2312
BUS DRIVER = tbniuafgah
BUS 
*/
int main()
{
    int choice;
    while (choice != 4)
    {
        cout << "***************************************************MENU***************************************************" << endl;
        cout << "1. Add new bus\n2. check available buses\n3. bus reservation" << endl;
        cout << "\n\nPlease enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            Add_bus();
            system("cls");
            break;
        case 2:
            system("cls");
            Check_buses();
            system("cls");
            break;
        case 3:
            system("cls");
            break;
        case 4:
            exit(0);
            system("cls");
            break;
        default:
            cout << "\nINVALID INPUT" << endl;
            break;
        }
    }
    getch();
    return 0;
}
