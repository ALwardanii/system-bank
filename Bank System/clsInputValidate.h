#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
private:

protected:

public:
	
	static bool IsNumberBetween(int NumberTarget, int NumberStart, int NumberEnd) {
		if (NumberTarget >= NumberStart && NumberTarget <= NumberEnd) 
			return true;
		else 
			return false;
		
	}
	
	static bool IsDataBetween(clsDate Now, clsDate From, clsDate To) {


		if (Now.GetYear() == From.GetYear() && Now.GetYear() == To.GetYear() && Now.GetMonth() > From.GetMonth()
			&& Now.GetMonth() < To.GetMonth()) {
			return true;
		}
		if (Now.GetYear() == From.GetYear() && Now.GetYear() == To.GetYear() && Now.GetMonth() < From.GetMonth()
			&& Now.GetMonth() > To.GetMonth()) {
			return true;
		}
		if (Now.GetMonth() == From.GetMonth() && Now.GetMonth() == To.GetMonth()) {
			if (Now.GetDay() > From.GetDay() && Now.GetDay() < To.GetDay()) {
				return true;
			}
		}
		if (Now.GetMonth() == From.GetMonth() && Now.GetMonth() == To.GetMonth()) {
			if (Now.GetDay() < From.GetDay() && Now.GetDay() > To.GetDay()) {
				return true;
			}
		}

		return false;

	}
	static int ReadIntNumber(string Message = "Invalid Number, Enter a valid one:") {
		int Number;
		
		cin >> Number;
		while (cin.fail())
		{
			// user didn't input a number    
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}
		return Number;
	}
	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number = 0;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static double ReadDoubleNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number = 0;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n") {
		int Number = ReadIntNumber();

		while (!(IsNumberBetween(Number, From, To))) {
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}



		return Number;

	}
	static double ReadDoubleNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n") {
		double Number = ReadIntNumber();

		while (!(IsNumberBetween(Number, From, To))) {
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n") {
		short Number = ReadIntNumber();

		while (!(IsNumberBetween(Number, From, To))) {
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}
	static bool IsValidDate(clsDate Date) {

		return clsDate::IsValidDate(Date);
	}

	static string ReadString() {
		string S;
		getline(cin >> ws, S);
		return S;
	}

};


