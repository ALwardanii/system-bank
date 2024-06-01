#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "clsSpaces.h"
#include "clsUsers.h"
#include "Global.h"

using namespace std;
class clsScreen : public clsSpaces
{
private:
	
	
protected: 
	static void HeaderBank(string NameBank) {
		clsSpaces::ManySpaces(44);
		cout <<"+===============================+\n";
		clsSpaces::ManySpaces(56);
		cout <<  NameBank << endl;
		clsSpaces::ManySpaces(44);
		cout << "+===============================+\n";
		clsSpaces::ManySpaces(45);
		cout <<  "Today Date : " << clsDate::DateToString(clsDate());
		cout << endl;
		clsSpaces::ManySpaces(50);
		cout <<  "User Name  : " << CurrentUser.UserName << endl;
		clsSpaces::ManySpaces(44);
		cout << "+===============================+\n";
	}
	static void HeaderBankProparty(string NameBank) {
		clsSpaces::ManySpaces(34);
		cout << "+===================================================+\n";
		clsSpaces::ManySpaces(57);
		cout << NameBank << endl;
		clsSpaces::ManySpaces(34);
		cout << "+===================================================+\n";
	}
	static bool CheckAccessRights(clsUsers::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccesPermission(Permission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}
	}
};

