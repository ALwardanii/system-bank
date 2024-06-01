#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;
class clsReadClientInfo : protected clsScreen
{
private :
    static void _ReadClientInfo(clsBankClient& Client) {
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
    static void UpdateDataClient() {
        if (!CheckAccessRights(clsUsers::enPermissions::pUpdateCLient))
        {
            return;// this will exit the function and it will not continue
        }
        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Update Data Client");

        string AccountNumber = "";
        cout << "---------------------------\n";
        cout << "Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClietExist(AccountNumber)) {
            cout << "Account Number is not Exist at Client List : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Client.Print();
        cout << "--------- update Client Date --------\n";
        _ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client.save();

        switch (SaveResult)
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
        }
    }
};

