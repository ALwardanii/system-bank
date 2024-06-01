#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsString.h"
using namespace std;
class clsCurrencyCalculator
{
private :
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}
	static clsCurrency _GetCurrency(string Message)
	{
		cout << Message;
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode))
		{
			cout << Message;
			string CurrencyCode = clsInputValidate::ReadString();
			break;
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;

	}
	static float _ReadAmount()
	{
		cout << "\n Enter Amount to Exchange : ";
		float Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}
	static void _ExecutingExchange(clsCurrency CurrencyTO, clsCurrency CurrencyFrom , float Amount)
	{
		cout << "Convert to : ";
		_PrintCurrency(CurrencyTO);

		float AmountInUSD = CurrencyTO.ConvertToUSD(Amount);

		cout << Amount << " " << CurrencyTO.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (CurrencyFrom.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";
		_PrintCurrency(CurrencyFrom);

		float AmountInCurrrency2 = CurrencyTO.ConvertToOtherCurrency(Amount, CurrencyFrom);

		cout << Amount << " " << CurrencyTO.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << CurrencyFrom.CurrencyCode();

	}
	

	
public:
	static void ShowCurrencyCalculator()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");

			clsCurrency  CurrencyTO = _GetCurrency("\n Enter Currency to Code : ");
			clsCurrency  CurrencyFrom = _GetCurrency("\n Enter Currency From Code : ");
			float Amount = _ReadAmount();
			_ExecutingExchange(CurrencyTO, CurrencyFrom, Amount);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;

		}
	}
};

