#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;
class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#") {
		vector <string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData.at(0), vCurrencyData.at(1),
			vCurrencyData.at(2), stod(vCurrencyData.at(3)));
	}

	string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#") {
		string Line;

		Line += Currency.Country() + Seperator;
		Line += Currency.CurrencyCode() + Seperator;
		Line += Currency.CurrencyName() + Seperator;
		Line += to_string(Currency.Rate());

		return Line;

	}

	static vector<clsCurrency>  _LoadCurrencyDataFromFile() {

		vector<clsCurrency> vCurrency;

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrency.push_back(Currency);
			}

			MyFile.close();

		}
		return vCurrency;
	}

	void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency) {

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out); //write mode now

		string Line;
		if (MyFile.is_open()) {
			for (clsCurrency& Currency : vCurrency) {
				Line = _ConvertCurrencyObjectToLine(Currency);
				MyFile << Line << endl;

			}


			MyFile.close();
		}



	}

	void _Update() {

		vector<clsCurrency> _vCurrency;
		_vCurrency = _LoadCurrencyDataFromFile();

		for (clsCurrency& Currency : _vCurrency) {
			if (Currency.CurrencyCode() == CurrencyCode()) {
				Currency = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrency);


	}


	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName,
		float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country() {
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	float Rate()
	{
		return _Rate;
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	static clsCurrency FindByCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode) {
					MyFile.close();
					return Currency;

				}


			}

			MyFile.close();
		}

		return _GetEmptyObject();

	}

	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country) {
					MyFile.close();
					return Currency;

				}


			}

			MyFile.close();
		}

		return _GetEmptyObject();

	}

	static bool IsCurrencyExistByCode(string CurrencyCode) {

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());

	}
	static bool IsCurrencyExistByCountry(string Country) {

		clsCurrency Currency = clsCurrency::FindByCountry(Country);
		return (!Currency.IsEmpty());

	}

	static vector<clsCurrency> GetCurrencyList() {
		return _LoadCurrencyDataFromFile();
	}
	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrencyDataFromFile();

	}
	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());

	}

};