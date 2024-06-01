#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateRate : protected clsScreen
{
private:
	static float _ReadRate()
	{
		cout << "\n Enter New Rate : ";
		float NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;
	}
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
    static string _ReadCurrencyCode()
    {
        string CurrencyCode = "";
        cout << "\n---------------------------\n";
        cout << "Enter Currency Code : ";
        CurrencyCode  = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode)) {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        return CurrencyCode;
    }
    static char _AreYouSure()
    {
        cout << "\nAre you sure you want to update this Rate y/n? ";
        char Answer;
        cin >> Answer;

        return Answer;
    }
    static void _ExecutingAnswer(char Answer , clsCurrency Currency)
    {
        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency.UpdateRate(_ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
        }
    }
public:
    static void ShowUpdateRate()
    {
        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Update Rate Data Currency");

        string CurrencyCode = _ReadCurrencyCode();

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);  
        _PrintCurrency(Currency);
        
        _ExecutingAnswer(_AreYouSure(), Currency);

    }
};

