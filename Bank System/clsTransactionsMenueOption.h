#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDeposit.h"
#include "clsWithdraw.h"
#include "clsTotalBalances.h"
#include "clsTransfer.h"
#include "clsTransferLog.h"
using namespace std;

class clsTransactionsMenueOption : protected clsScreen
{

private :
	enum enTransactionsOption{eDeposit = 1, eWithdrow = 2 , eShowTotalBalance = 3 ,  eTransfer = 4 , eTransferLog = 5
		,eShowMainMenue = 6 };

	static int _ReadTransactionsOption() {
		clsSpaces::ManySpaces(48);
		cout << "Enter Number [1 to 6] : ";
		int Choose = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Vaild Number 1 to 6 : ");
		
		return Choose;

	}
	static void _ShowDepositScreen() {
		clsDeposit::ShowDepositScreen();
	}
	static void _ShowWithdrowScreen() {
		clsWithdraw::ShowWithdrawScreen();
	}
	static void _ShowTotalBalanceScreen() {
		clsTotalBalances::ShowTotalBalances();
	}
	static void _ShowTransferScreen() {
		clsTransfer::ShowTransferScreen();
	}
	static void _ShowTransferLogScreen() {
		clsTransferLog::ShowTransferLog();
	}
	static void _ShowMainMenueScreen() {
		
	}
	


	static void _PeformTransactionMenueOption(enTransactionsOption TransactionsOption) {
		switch (TransactionsOption)
		{
		case clsTransactionsMenueOption::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			break;
		}
		case clsTransactionsMenueOption::eWithdrow:
		{
			system("cls");
			_ShowWithdrowScreen();
			break;
		}
		case clsTransactionsMenueOption::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			break;
		}
		case clsTransactionsMenueOption::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			break;
		}
		case clsTransactionsMenueOption::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			break;
		}
		case clsTransactionsMenueOption::eShowMainMenue:
		{
			system("cls");
			_ShowMainMenueScreen();
			break;
		}
		
		}
	}

public :
	static void ShowTransactionsMenueOption() {
		if (!CheckAccessRights(clsUsers::enPermissions::pTranactions))
		{
			return;// this will exit the function and it will not continue
		}
		clsScreen::HeaderBank("NOOAH BANk");
		clsScreen::HeaderBankProparty("Transactions");

		clsSpaces::ManySpaces(42);
		cout << "+===================================+" << endl;
		clsSpaces::ManySpaces(45);
		cout << "(1) Deposit " << endl;
		clsSpaces::ManySpaces(45);
		cout << "(2) Withdrow " << endl;
		clsSpaces::ManySpaces(45);
		cout << "(3) SHow Total Balance " << endl;
		clsSpaces::ManySpaces(45);
		cout << "(4) Transfer " << endl;
		clsSpaces::ManySpaces(45);
		cout << "(5) Transfer Log " << endl;
		clsSpaces::ManySpaces(45);
		cout << "(6) Show Main Menue " << endl;
		clsSpaces::ManySpaces(42);
		cout << "+===================================+" << endl;
		

		_PeformTransactionMenueOption((enTransactionsOption)_ReadTransactionsOption());
	}

};

