#pragma once
#include <iostream>
#include <iomanip>
#include "clsUsers.h"
#include "clsScreen.h"
using namespace std;
class clsTransferLog : public clsScreen
{
private:
	
	static void PrintTransferLoginRecordLine(clsUsers::stTransferLog Record) {
		cout << setw(8) << left << "" << "| " << setw(24) << left << Record.DataTime;
		cout << "| " << setw(17) << left << Record.SourceAccount;
		cout << "| " << setw(17) << left << Record.DestinationAccount;
		cout << "| " << setw(17) << left << Record.Amount;
		cout << "| " << setw(17) << left << Record.SourceBalance;
		cout << "| " << setw(17) << left << Record.DestinationBalance;
		cout << "| " << setw(17) << left << Record.UserName;

	}
public:
	static void ShowTransferLog()
	{
        clsScreen::HeaderBank("NOOAH BAnk");

        vector <clsUsers::stTransferLog> vTransferLogRecords = clsUsers::GetTransferLoginList();
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout << "* Transfer Login Users List *" << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        clsSpaces::ManySpaces(52);
        cout << "Total Record : " << vTransferLogRecords.size() << endl;
        clsSpaces::ManySpaces(40);
        cout << "-----------------------------------------" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(24) << "Data / Time";
        cout << "| " << left << setw(17) << "S.Account";
        cout << "| " << left << setw(17) << "D.Account";
        cout << "| " << left << setw(17) << "Amount";
        cout << "| " << left << setw(17) << "S.Balance";
        cout << "| " << left << setw(17) << "D.Balance";
        cout << "| " << left << setw(9) << "User Name\n";

        cout << "\n----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------\n\n";

        if (vTransferLogRecords.size() == 0)
            cout << "There are no Record";
        else
            for (clsUsers::stTransferLog& TransferLogLine : vTransferLogRecords)
            {
                PrintTransferLoginRecordLine(TransferLogLine);
                cout << "\n";
            }

        cout << "----------------------------------------";
        cout << "----------------------------------------";
        cout << "----------------------------------------\n\n";
    
	}
};

