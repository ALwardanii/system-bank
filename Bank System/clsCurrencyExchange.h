#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrencies.h"
#include "clsFindCurrency.h"
#include "clsUpdateRate.h"
#include "clsCurrencyCalculator.h"
using namespace std;
class clsCurrencyExchange : protected clsScreen
{
private:
	enum enOptionMenue{eListCurrencies = 1 , eFindCurrency = 2 , eUpdateRate = 3 , eCurrencyCalculator = 4
	, MainMenue = 5};
	
	static short _ReadNumberMenue()
	{
		clsScreen::ManySpaces(52);
		cout << "Enter Number [1 to 5] : ";
		short Choose = clsInputValidate::ReadShortNumberBetween(1, 5, "Value faild , Enter Number [1 to 5] :");

		return Choose;
	}
	static void _GoBackToCurrenciesMenue()
	{
		cout << "\n\nPress any key to go back to Currencies Menue...";
		system("pause>0");
		system("cls");
		ShowCurrencyExchangeMenue();
	}
	static void _ListCurrencies()
	{
		clsListCurrencies::ShowCurrencysList();
	}
	static void _FindCurrency()
	{
		clsFindCurrency::ShowFindCurrency();
	}
	static void _UpdateRate()
	{
		clsUpdateRate::ShowUpdateRate();
	}
	static void _CurrencyCalculator()
	{
		clsCurrencyCalculator::ShowCurrencyCalculator();
	}
	static void _PerformCurrencyExchangeMenue(enOptionMenue OptionMenue)
	{
		switch (OptionMenue)
		{
		case clsCurrencyExchange::eListCurrencies:
		{
			system("cls");
			_ListCurrencies();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchange::eFindCurrency:
		{
			system("cls");
			_FindCurrency();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchange::eUpdateRate:
		{
			system("cls");
			_UpdateRate();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchange::eCurrencyCalculator:
		{
			system("cls");
			_CurrencyCalculator();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchange::MainMenue:
		{
			system("cls");
			_GoBackToCurrenciesMenue();
			break;
		}
		
		}
	}

public:
	static void ShowCurrencyExchangeMenue()
	{
		clsScreen::HeaderBank("NOOAH BANK");
		clsScreen::HeaderBankProparty("Show Currency Exchange Menue");
		clsScreen::ManySpaces(48);
		cout << "(1) List Currencies" << endl;
		clsScreen::ManySpaces(48);
		cout << "(2) Find Currency" << endl;
		clsScreen::ManySpaces(48);
		cout << "(3) Update Rate" << endl;
		clsScreen::ManySpaces(48);
		cout << "(4) Currency Calculator" << endl;
		clsScreen::ManySpaces(48);
		cout << "(5) Main Menue" << endl;
		clsSpaces::ManySpaces(44);
		cout << "+===================================+" << endl;
		_PerformCurrencyExchangeMenue((enOptionMenue)_ReadNumberMenue());

	}
};

