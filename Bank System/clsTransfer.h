#pragma once
#include <iostream>
#include <fstream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "Global.h"
#include "clsScreen.h"
using namespace std;

class clsTransfer : public clsScreen
{
private:
	static void _PrintDataClient(clsBankClient Client) {
		cout << "\n---------------------\n";
		cout << "Bank Credit";
		cout << "\n---------------------";
		cout << "\nFull Name     : " << Client.FullName();
		cout << "\nAccout Number :  " << Client.AccountNumber();
		cout << "\nBalance       : " << Client.AccountBalance;
		cout << "\n---------------------\n";
	}
	static string _ReadAccountNumber() {
		cout << "\nPlease enter the account number transferred : ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClietExist(AccountNumber))
		{
			cout << "\nthis account number does not exist, please try again : ";
			string AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}
	static double _ReadAmount(clsBankClient Client)
	{
		cout << "\nWhat is the value you want me to transfer to the account : ";
		double Balance = clsInputValidate::ReadDoubleNumber();
		if (Client.AccountBalance < Balance)
		{
			cout << "\nThe account does not bear this amount, please enter another amount : ";
			double Balance = clsInputValidate::ReadDoubleNumber();
		}

		return Balance;
	}
	
public:
	static void ShowTransferScreen()
	{
		clsScreen::HeaderBank("NOOAH BANK");
		clsScreen::HeaderBankProparty("Transfer");

		
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintDataClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintDataClient(DestinationClient);

		double Amount = _ReadAmount(SourceClient);
		cout << "\nAre you sure to make this account transfer (y or n) ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer completed successfully >)";
			}
			else
			{
				cout << "\nTransfer completed faild <)";
			}
			
			
			
		}
			
		_PrintDataClient(SourceClient);
		_PrintDataClient(DestinationClient);

		

	}
};

