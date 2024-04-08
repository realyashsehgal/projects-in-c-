#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
using namespace std;
fstream files;
class Myfiles
{
public:
    string user;
    string pass;

public:
    void registration()
    {
        files.open("register.txt", ios::app);
        cout << "Please enter your username" << endl;
        cin >> user;
        cout << "Please enter your password" << endl;
        cin >> pass;
        files << user << "*" << pass << endl;
        files.close();
    }
    int login(int flag)
    {
        files.open("register.txt", ios::in);
        string data;
        string line;
        cout << "Please enter your username " << endl;
        cin >> user;
        cout << "Please enter your password" << endl;
        cin >> pass;
        data = user + "*" + pass;
        while (getline(files, line))
        {
            if (line == data)
            {
                cout << "You have succesfully logged in as " << user << endl;
                cout << "Press any key to exit" << endl;
                getch();
                exit(0);
                files.close();
                flag = 1;
            }
        }
        return flag;
    }
    void changePassword()
    {
        string username, newPassword;
        cout << "Enter username: ";
        cin >> username;

        files.open("register.txt", ios::in | ios::out); // Open file for reading and writing

        if (!files.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        string line;
        size_t pos;
        while (getline(files, line))
        {
            pos = line.find('*');
            if (line.substr(0, pos) == username)
            {
                cout << "Enter new password: ";
                cin >> newPassword;
                files.seekp(files.tellg() - line.length() - 1);
                files << username << "*" << newPassword;
                cout << "Password changed successfully!" << endl;
                files.close();
                return;
            }
        }

        cout << "Username not found!" << endl;
        files.close();
    }
};
int main()
{
    int choice, flag;
    Myfiles myobj;
    while (choice != 4)
    {
        cout << "---------------------------------------------MENU-----------------------------------------------" << endl;
        cout << "1.REGISTER\n2.Login\n3.forget password\n4.exit\n"
             << endl;
        cout << "Please select one option" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            myobj.registration();
            break;
        case 2:
            flag = myobj.login(flag);
            if (flag != 1)
            {
                cout << "Invalid login id and password" << endl;
            }
            break;
        case 3:
            myobj.changePassword();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}
