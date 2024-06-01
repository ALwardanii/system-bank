#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "clsShowClientList.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsReadClientInfo.h"
#include "clsFindClient.h"
#include "clsTransactionsMenueOption.h"
#include "clsManageUsers.h"
#include "clsLoginRegister.h"
#include "clsCurrencyExchange.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOption{enShowClientList = 1 , enAddNewClient = 2 , enDeleteClient = 3 , enUpdateClientInfo = 4
	,enFindClient = 5 , enTransactions = 6 , enManageUsers = 7 , enLoginList = 8 , enCurrencyExchange =9 ,enLogout = 10};

	static short _ReadMainMenueOption() {
		clsSpaces::ManySpaces(48);
		cout <<  "Choose From [1 to 10] : ";
		short Choose = clsInputValidate::ReadShortNumberBetween(1, 10, "Error! Enter valid Value : ");
		
		return Choose;
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		system("cls");
		ShowMainMeneu();
	}
	static void _ShowClientList()
	{
		clsShowClientList::ShowClientsList();
	}
	static void _AddNewClient()
	{
		clsAddNewClient::AddNewCLient();
	}
	static void _DeleteClient() 
	{
		clsDeleteClient::DeleteClient();
	}
	static void _UpdateClientInfo() 
	{
		clsReadClientInfo::UpdateDataClient();
	}
	static void _FindClient() 
	{
		clsFindClient::ShowFindClientScreen();
	}
	static void _Transactions() 
	{
		clsTransactionsMenueOption::ShowTransactionsMenueOption();
	}
	static void _ManageUsers() 
	{
		clsManageUsers::ShowManageUserOption();
	}
	static void _LoginList() 
	{
		clsLoginRegister::ShowLoginList();
	}
	static void _CurrencyExchange()
	{
		clsCurrencyExchange::ShowCurrencyExchangeMenue();
	}
	static void _Logout() {
		CurrentUser = clsUsers::Find("", "");

	}

	static void _PerformMainMenueOption(enMainMenueOption MainMenueOption) {
		switch (MainMenueOption)
		{
		case clsMainScreen::enShowClientList:
		{
			system("cls");
			_ShowClientList();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enAddNewClient:
		{
			system("cls");
			_AddNewClient();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enDeleteClient:
		{
			system("cls");
			_DeleteClient();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enUpdateClientInfo:
		{
			system("cls");
			_UpdateClientInfo();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enFindClient:
		{
			system("cls");
			_FindClient();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enTransactions:
		{
			system("cls");
			_Transactions();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enManageUsers:
		{
			system("cls");
			_ManageUsers();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enLoginList:
		{
			system("cls");
			_LoginList();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enCurrencyExchange:
		{
			system("cls");
			_CurrencyExchange();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enLogout:
		{
			system("cls");
			_Logout();
			break;
		}
		
		}
	}
public: 
	static void ShowMainMeneu() {
		clsScreen::HeaderBank("NOOAH BANk");
		clsSpaces::ManySpaces(42);
		cout <<  "+===================================+" << endl;
		clsSpaces::ManySpaces(56);
		cout <<  "Main Menue" << endl;
		clsSpaces::ManySpaces(42);
		cout << "+===================================+" << endl;
		clsSpaces::ManySpaces(44);
		cout <<  "(1) Show CLient List.\n";
		clsSpaces::ManySpaces(44);
		cout << "(2) Add New CLient.\n";
		clsSpaces::ManySpaces(44);
		cout <<  "(3) Delete CLient.\n";
		clsSpaces::ManySpaces(44);
		cout <<  "(4) Update Client Info. \n";
		clsSpaces::ManySpaces(44);
		cout <<  "(5) Find Client.\n";
		clsSpaces::ManySpaces(44);
		cout <<  "(6) Transactions.\n";
		clsSpaces::ManySpaces(44);
		cout <<  "(7) Manage Users.\n";
		clsSpaces::ManySpaces(44);
		cout << "(8) Login Records List.\n";
		clsSpaces::ManySpaces(44);
		cout << "(9) CurrencyExchange.\n";
		clsSpaces::ManySpaces(44);
		cout <<  "(10) Logout.\n";
		clsSpaces::ManySpaces(42);
		cout <<  "+===================================+" << endl;
		

		return _PerformMainMenueOption((enMainMenueOption)_ReadMainMenueOption());
	}
};

