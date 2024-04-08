#include <iostream>
#include <conio.h>
#include <fstream>
#include <strings.h>
using namespace std;
string id;
string pass;
fstream file;
int registration();
int login();
int main()
{
    int choice = 0;

    // registration

    while (choice != 3)
    {
        cout << "----------------------------------------menu----------------------------------------" << endl;
        cout << "1. Registration\n2. Login\n3. Exit" << endl;
        cin >> choice;
        cin.ignore(1000, '\n');
        switch (choice)
        {
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
    return 0;
}
int registration()
{
    file.open("datastorage.txt", ios::app);
    cout << "Please enter your username" << endl;
    getline(cin, id);
    cout << "Please enter your password" << endl;
    getline(cin, pass);
    file << id + pass << endl;
    file.close();

    return 0;
}
int login()
{
    file.open("datastorage.txt", ios::in);
    string line;
    string newline;
    cout << "Please enter a username inorder to login" << endl;
    cin >> id;
    cout << "Please enter your password" << endl;
    cin >> pass;
    newline = id + pass;
    while (getline(file, line))
    {

        if (line == newline)
        {
            cout << "succesfully logged in with user id " << id << endl;
            getch();
            exit(0);
        }
        else
        {

            continue;
        }
    }

    return 0;
}
