#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;
class clsDeposit : public clsScreen
{
public:
	static void ShowDepositScreen() {
        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Show Deposit Screen");

        string AccountNumber;
        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClietExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        Client1.Print();

        cout << "\nPlease enter deposit Number : ";
        double Amount = clsInputValidate::ReadDoubleNumber();

        cout << "\nAre you sure to perform this operation ? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);
            cout << "\nAccount Deposited Successfuly";
            cout << "\n New Balance : " << Client1.AccountBalance;
        }
        else
        {
            cout << "\n Operion Failed !";
        }

	}
private:

};

