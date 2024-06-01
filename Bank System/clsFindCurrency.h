#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindCurrency : protected clsScreen
{
private:
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
    static short _ReadNumberOption()
    {
        cout << "\nFind By [1] Code or [2] Country : ";
        short Choose = clsInputValidate::ReadShortNumberBetween(1, 2, "Value Entered faild , Enter [1] or [2] : ");

        return Choose;
    }
    static void ExecutingOptions(short Choose)
    {
        if (Choose == 1)
        {
            cout << "\nEnter Currency Code : ";
            string CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            if (!Currency.IsEmpty()) {
                cout << "\nCurrency  Found >),";
                _PrintCurrency(Currency);
            }
            else
            {
                cout << "\nCurrency Not Found <),";
            }
        }
        else
        {
            cout << "\nEnter Country : ";
            string country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(country);
            if (!Currency.IsEmpty()) {
                cout << "\nCurrency  Found >),";
                _PrintCurrency(Currency);
            }
            else
            {
                cout << "\nCurrency Not Found <),";
            }
        }
    }
public:
    static void ShowFindCurrency()
    {
        clsScreen::HeaderBank("NOOAH BANk");
        clsScreen::HeaderBankProparty("Find Currency");
        
        short Choose = _ReadNumberOption();

        ExecutingOptions(Choose);

    }
};

