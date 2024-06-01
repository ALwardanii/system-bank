#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsers.h"

using namespace std;
class clsDeleteUser : protected clsScreen
{
private:
    static void _PrintUser(clsUsers User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permission;
        cout << "\n___________________\n";

    }
public:

    static void DeleteUser() {

        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Delete User");

        string UserName = "";
        cout << "---------------------------\n";
        cout << "Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUsers::IsUserExist(UserName)) {
            cout << "User Name is not Exist at User List : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUsers User = clsUsers::Find(UserName);

        _PrintUser(User);

        cout << "\nYou Are Sure Delete Account : ";
        char Answer = 'n';

        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (User.Delete())
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nAn error occurred deleting the account";
            }



        }
    }
};

