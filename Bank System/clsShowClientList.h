#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsShowClientList : protected clsScreen
{
private:
    static void PrintUserRecordLine(clsBankClient Client) {
        cout << setw(8) << left << "" << "| " << setw(12) << left << Client.FirstName;
        cout << "| " << setw(15) << left << Client.LastName;
        cout << "| " << setw(25) << left << Client.FullName();
        cout << "| " << setw(14) << left << Client.Phone;
        cout << "| " << setw(30) << left << Client.Email;
        cout << "| " << setw(17) << left << Client.Pincode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
public:
    static void ShowClientsList() {
        if (!CheckAccessRights(clsUsers::enPermissions::pListCLient))
        {
            return;// this will exit the function and it will not continue
        }
        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Show Users List");

        vector <clsBankClient> vClient = clsBankClient::GetClientList();

        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout << "* Users List *" << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout << "Total Users : " << vClient.size() << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(12) << "First Name";
        cout << "| " << left << setw(15) << "last Name";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(14) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(17) << "Pincode";
        cout << "| " << left << setw(12) << "Account Balance";

        cout << "\n----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------------------------------------\n\n";

        if (vClient.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else
            for (clsBankClient& Client : vClient)
            {

                PrintUserRecordLine(Client);
                cout << "\n";
            }

        cout << "----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------------------------------------\n\n";
    }
};

