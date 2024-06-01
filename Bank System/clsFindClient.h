#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;
class clsFindClient : protected clsScreen
{
private:

public:
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUsers::enPermissions::pFindCLient))
        {
            return;// this will exit the function and it will not continue
        }
        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Show Find Client Screen");

        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClietExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        Client1.Print();

    }
};

