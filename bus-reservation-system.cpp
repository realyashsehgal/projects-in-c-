#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;
#define underline "\033[4m\033"
fstream file;
int arr[40];
struct bus_data
{
    int bus_id;
    int seats = 20;
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
    file.open("seats.txt", ios::app);
    file << entry.seats << endl;
    file.close();
    return 0;
}
int Check_buses()
{
    file.open("bus data.txt", ios::in);
    string info;
    cout << "\033[4mBus ID\t\tDriver's Name\t\tStarting point\t\tEnding point\t\tAvaialble seats\033[0m" << endl
         << endl;

    while (getline(file, info))
    {
        for (int i = 0; i < info.size(); i++)
        {
            if (info[i] == '*')
            {
                cout << setw(20) << right;
            }
            else
            {
                cout << info[i];
            }
        }
        cout << endl
             << endl;
    }
    file.close();
    getch();
    return 0;
}
int reservation()
{
    file.open("bus data.txt", ios::in);
    string info;
    int x = 0;
    while (getline(file, info))
    {
        cout << x + 1 << ". ";
        for (int i = 0; i < info.size(); i++)
        {
            if (info[i] == '*')
            {
                break;
            }
            cout << info[i];
        }
        cout << endl;
        x++;
        // cout<<endl<<endl;
    }
    file.close();
    cout << "Please select the bus you wanto ride through S.NO(1,2,3,.....)" << endl;
    int bus_no;
    cin >> bus_no;
    int count = 1;
    file.open("seats.txt", ios::out | ios::in);
    // while(getline(file,info))
    // {
    //     if(count == bus_no)
    //     {
    //         int av_seats;
    //         av_seats = stoi(info);
    //         av_seats -= 1;
    //         file<<av_seats<<endl;
    //     }

    // }
    size_t pos;
    while (getline(file, info))
    {
        // pos = info.find('*');
        if (count == bus_no)
        {
            file.seekp(file.tellg() - info.length() - 2);

            int av_seats;
            av_seats = stoi(info);
            av_seats -= 1;
            file << av_seats << endl;
            file.close();
            return 0;
        }
        else
        {
            count++;
        }
    }
    file.close();
    getch();
    return 0;
}
int main()
{
    int choice;
    while (choice != 4)
    {
        cout << "***************************************************MENU***************************************************" << endl;
        cout << "1. Add new bus\n2. check available buses\n3. bus reservation\n4. exit" << endl;
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
            reservation();
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
