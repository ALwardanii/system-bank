#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;
class clsWithdraw : public clsScreen
{
public:
    static void ShowWithdrawScreen() {
        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Show Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClietExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        Client1.Print();

        cout << "\nPlease enter Withdraw Number : ";
        double Amount = clsInputValidate::ReadDoubleNumber();

        cout << "\nAre you sure to perform this operation ? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount)) {
                cout << "\nAccount Withdrawed Successfuly";
                cout << "\n New Balance : " << Client1.AccountBalance;
            }
            else {
                cout << "\nCannot Withdeaw, INsuffecient Balance!";
                cout << "\nAmount To Withdeaw is : " << Amount;
                cout << "\nYour Balnce : " << Client1.AccountBalance;
            }
            
        }
        else
        {
            cout << "\n Operion Failed !";
        }

    }
private:
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }
};

