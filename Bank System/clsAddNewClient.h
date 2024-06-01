#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;
class clsAddNewClient : protected clsScreen
{
private:
    static void ReadClientInfo(clsBankClient& Client) {
        cout << "\n------------------------\n";
        cout << "Client Details : ";
        cout << "\n----------------------------\n";
        cout << "First Name      : ";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "\nLast Name       : ";
        Client.LastName = clsInputValidate::ReadString();
        cout << "\nEmail           : ";
        Client.Email = clsInputValidate::ReadString();
        cout << "\nPhone           : ";
        Client.Phone = clsInputValidate::ReadString();
        cout << "\nAccount Number  : ";
        Client.AccountNumber() = clsInputValidate::ReadString();
        cout << "\nPincode         : ";
        Client.Pincode = clsInputValidate::ReadString();
        cout << "Account Balance : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
        cout << "\n----------------------------";

    }
public:
    static void AddNewCLient() {
        if (!CheckAccessRights(clsUsers::enPermissions::pAddNewCLient))
        {
            return;// this will exit the function and it will not continue
        }

        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Add New Client");

        string AccountNumber = "";
        cout << "---------------------\n";
        cout << "Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClietExist(AccountNumber))
        {
            cout << "\nEnter Account Number Is Not Exist : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::GetAddNewClient(AccountNumber);
        ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResults;
        SaveResults = Client.save();

        switch (SaveResults)
        {
        case clsBankClient::svFaildEmprtyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;
        }
        case clsBankClient::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            Client.Print();
            break;
        }
        case clsBankClient::svFaildExistObject:
        {

        }


        }

    }
};

