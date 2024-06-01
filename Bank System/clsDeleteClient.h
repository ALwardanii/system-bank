#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;
class clsDeleteClient : protected clsScreen
{
private:

public:
    static void DeleteClient()
    {

        if (!CheckAccessRights(clsUsers::enPermissions::pDeleteCLient))
        {
            return;// this will exit the function and it will not continue
        }
        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Delete Client");

        string AccountNumber = "";
        cout << "---------------------------\n";
        cout << "Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClietExist(AccountNumber)) 
        {
            cout << "Account Number is not Exist at Client List : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Client.Print();

        cout << "\nYou Are Sure Delete Account : ";
        char Answer = 'n';

        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nAccount Updated Successfully :-)\n";
                Client.Print();
            }
            else
            {
                cout << "\nAn error occurred deleting the account";
            }



        }
    }
};

