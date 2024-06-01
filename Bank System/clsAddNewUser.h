#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUsers.h"

using namespace std;
class clsAddNewUser : protected clsScreen
{
private:
    static void ReadUserInfo(clsUsers& User) {
        cout << "\n------------------------\n";
        cout << "User Details : ";
        cout << "\n----------------------------\n";
        cout << "First Name        : ";
        User.FirstName = clsInputValidate::ReadString();
        cout << "\nLast Name       : ";
        User.LastName = clsInputValidate::ReadString();
        cout << "\nEmail           : ";
        User.Email = clsInputValidate::ReadString();
        cout << "\nPhone           : ";
        User.Phone = clsInputValidate::ReadString();
        cout << "\nPassword        : ";
        User.Password = clsInputValidate::ReadString();
        cout << "Permission        : ";
        User.Permission = _ReadPermissionsToSet();
        cout << "\n----------------------------";

    }
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
    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUsers::enPermissions::pListCLient;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pAddNewCLient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pDeleteCLient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pUpdateCLient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pFindCLient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pManageUser;
        }
        cout << "\nLogin List Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::PLoginList;
        }

        return Permissions;
    }
public:
    static void AddNewUser() {

        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Add New User");

        string UserName = "";
        cout << "---------------------\n";
        cout << "Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (clsUsers::IsUserExist(UserName))
        {
            cout << "\nEnter Account Number Is Not Exist : ";
            UserName = clsInputValidate::ReadString();
        }
        clsUsers User = clsUsers::GetAddNewUser(UserName);
        ReadUserInfo(User);

        clsUsers::enSaveResults SaveResults;
        SaveResults = User.save();

        switch (SaveResults)
        {
        case clsUsers::svFaildEmprtyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;
        }
        case clsUsers::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintUser(User);
            break;
        }
        case clsUsers::svFaildExistObject:
        {

        }


        }

    }
};

