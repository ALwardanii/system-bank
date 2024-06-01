#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;

class clsListCurrencies : protected clsScreen
{
private:
    static void PrintCurrencyRecordLine(clsCurrency Currency) {
        cout << setw(8) << left << "" << "| " << setw(28) << left << Currency.Country();
        cout << "| " << setw(17) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(15) << left << Currency.Rate();
    }
    
public:
    static void ShowCurrencysList() {

        clsScreen::HeaderBank("NOOAH BANk");

        vector <clsCurrency> vCurrency = clsCurrency::GetCurrencyList();
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout << "* Currencys List *" << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout << "Total Currencys : " << vCurrency.size() << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(28) << "Country Name";
        cout << "| " << left << setw(17) << "Currency Code";
        cout << "| " << left << setw(40) << "Currency Name";
        cout << "| " << left << setw(15) << "Rate";

        cout << "\n----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------\n\n";

        if (vCurrency.size() == 0)
            cout << "There are no Currencys";
        else
            for (clsCurrency& Currency : vCurrency)
            {
                PrintCurrencyRecordLine(Currency);
                cout << "\n";
            }

        cout << "----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------\n\n";
    }
};

