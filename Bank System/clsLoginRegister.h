#pragma once
#include <iostream>
#include "clsUsers.h"
#include "clsDate.h"
#include "clsScreen.h"
#include <vector>
#include<iomanip>
using namespace std;
class clsLoginRegister : public clsScreen
{
private:
	static void PrintLoginRegisterRecordLine(clsUsers::stLoginRegistarRecord Record) {
		cout << setw(8) << left << "" << "| " << setw(24) << left << Record.DataTime;
		cout << "| " << setw(17) << left << Record.UserName;
		cout << "| " << setw(17) << left << Record.Password;
		cout << "| " << setw(12) << left << Record.Permissions;

	}


public :
	static void ShowLoginList() {
        if (!CheckAccessRights(clsUsers::enPermissions::PLoginList))
        {
            return;// this will exit the function and it will not continue
        }
        clsScreen::HeaderBank("NOOAH BANk");

        vector <clsUsers::stLoginRegistarRecord> vLoginRegisterRecords = clsUsers::GetLoginList();
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout << "* Login Users List *" << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout << "Total Record : " << vLoginRegisterRecords.size() << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(24) << "Data / Time";
        cout << "| " << left << setw(17) << "User Name";
        cout << "| " << left << setw(17) << "Password";
        cout << "| " << left << setw(9) << "Permissions";

        cout << "\n----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------\n\n";

        if (vLoginRegisterRecords.size() == 0)
            cout << "There are no Record";
        else
            for (clsUsers::stLoginRegistarRecord & LoginDataLine : vLoginRegisterRecords)
            {
                PrintLoginRegisterRecordLine(LoginDataLine);
                cout << "\n";
            }

        cout << "----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------\n\n";
	}
};

