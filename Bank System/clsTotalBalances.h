#pragma once
#include <iostream>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
using namespace std;

class clsTotalBalances : protected clsScreen
{
public:
    static void ShowTotalBalances() {

        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Show Total Balances");
        vector <clsBankClient> vClient = clsBankClient::GetClientList();

        cout << setw(80) << "------------------------------------------" << endl;
        cout << setw(65) << "* Client List *" << endl;
        cout << setw(80) << "------------------------------------------" << endl;
        cout << setw(80) << "------------------------------------------" << endl;
        cout << setw(65) << "Total Client : " << vClient.size() << endl;
        cout << setw(80) << "------------------------------------------" << endl;
        cout << "\n\n" << "| " << "Account Number" << setw(15);
        cout << "| " << "Name Client" << setw(15);
        cout << "| " << "Account Balance" << endl;

        cout << "----------------------------------------";
        cout << "---------------------------------\n";



        if (vClient.size() == 0)
            cout << "There are no clients";
        else
            for (clsBankClient& Client : vClient)
            {

                _PrintClientRecordLineBalances(Client);
                cout << "\n";
            }

        cout << "----------------------------------------";
        cout << "---------------------------------\n";

        double TotalBalance = clsBankClient::GetTotalBalances();
        cout << setw(35) << "Total Balance = " << TotalBalance;

    }
private:
    static void _PrintClientRecordLineBalances(clsBankClient Client) {
        cout << "| " << Client.AccountNumber() << setw(25);
        cout << "| " << Client.FirstName + " " + Client.LastName << setw(14);
        cout << "| " << Client.AccountBalance;

    }
};

