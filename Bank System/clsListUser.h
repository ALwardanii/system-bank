#pragma once
#include <iostream>
#include "clsUsers.h"
#include "clsScreen.h"
using namespace std;
class clsListUser : public clsScreen
{
private:
    static void PrintUserRecordLine(clsUsers User) {
        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(14) << left << User.Phone;
        cout << "| " << setw(30) << left << User.Email;
        cout << "| " << setw(17) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permission;

    }
public:
    static void ShowUsersList() {

        clsScreen::HeaderBank("NOOAH BANk");
        
        vector <clsUsers> vUser = clsUsers::GetUsersList();
        clsSpaces::ManySpaces(40);
        cout <<  "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout <<  "* Users List *" << endl;
        clsSpaces::ManySpaces(40);
        cout <<  "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(40);
        cout <<  "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout <<  "Total Users : " << vUser.size() << endl;
        clsSpaces::ManySpaces(40);
        cout <<  "-----------------------------------------" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(14) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(17) << "Password";
        cout << "| " << left << setw(12) << "Permissions";

        cout << "\n----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------\n\n";

        if (vUser.size() == 0)
            cout << "There are no Users";
        else
            for (clsUsers& User : vUser)
            {
                PrintUserRecordLine(User);
                cout << "\n";
            }

        cout << "----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------\n\n";
    }

};

