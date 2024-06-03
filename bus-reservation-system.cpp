#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include<vector>
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
    if (!file.is_open())
    {
        cout << "Unable to open bus data file." << endl;
        return 1;
    }

    string info;
    int bus_count = 0;
    while (getline(file, info))
    {
        cout << bus_count + 1 << ". ";
        for (char c : info)
        {
            if (c == '*') break;
            cout << c;
        }
        cout << endl;
        bus_count++;
    }
    file.close();

    cout << "Please select the bus you want to ride by S.NO (1,2,3,...)" << endl;
    int bus_no;
    cin >> bus_no;
    bus_no -= 1;

    if (bus_no < 0 || bus_no >= bus_count)
    {
        cout << "Invalid bus number." << endl;
        return 0;
    }
    fstream seats_file("seats.txt", ios::in);
    if (!seats_file.is_open())
    {
        cout << "Unable to open seats file." << endl;
        return 1;
    }

    vector<int> seats;
    string line;
    while (getline(seats_file, line))
    {
        seats.push_back(stoi(line));
    }
    seats_file.close();

    if (bus_no < seats.size() && seats[bus_no] > 0)
    {
        seats[bus_no] -= 1;
        cout << "Reservation successful. Seats remaining: " << seats[bus_no] << endl;
    }
    else
    {
        cout << "No available seats or invalid bus selection." << endl;
        return 0;
    }
    seats_file.open("seats.txt", ios::out | ios::trunc);
    if (!seats_file.is_open())
    {
        cout << "Unable to open seats file for writing." << endl;
        return 1;
    }

    for (int seat : seats)
    {
        seats_file << seat << endl;
    }

    seats_file.close();
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
