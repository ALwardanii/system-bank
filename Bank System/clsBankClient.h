#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "clsInputValidate.h"

class clsBankClient : public clsPerson
{

private:
    enum enMode {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;
    string _AccountNumber;
    string _Pincode;
    float _AccountBalance = 0;
    bool _MarkForDelete = false;


    static clsBankClient _ConvertLinetoClinetObject(string Line, string Seperator = "#//#") {
        vector <string> vString;
        vString = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vString.at(0), vString.at(1),
            vString.at(2), vString.at(3), vString.at(4), vString.at(5), stod(vString.at(6)));
    }
    string _ConvertCLientObjectToLine(clsBankClient Client, string Seperator = "#//#") {
        string Line;

        Line += Client.FirstName + Seperator;
        Line += Client.LastName + Seperator;
        Line += Client.Email + Seperator;
        Line += Client.Phone + Seperator;
        Line += Client.AccountNumber() + Seperator;
        Line += Client.Pincode + Seperator;
        Line += to_string(Client.AccountBalance);

        return Line;

    }
    static vector<clsBankClient>  _LoadClientDataFromFile() {

        vector<clsBankClient> vClient;

        fstream MyFile;

        MyFile.open("ClientData.txt", ios::in);

        if (MyFile.is_open()) {

            string Line;

            while (getline(MyFile, Line)) {

                clsBankClient Client = _ConvertLinetoClinetObject(Line);

                vClient.push_back(Client);
            }

            MyFile.close();

        }
        return vClient;
    }

    static clsBankClient _GetEmptyCLient() {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }


    void _SaveClientDataToFile(vector <clsBankClient> vClient) {

        fstream MyFile;
        MyFile.open("ClientData.txt", ios::out); //write mode now

        string Line;
        if (MyFile.is_open()) {
            for (clsBankClient& Client : vClient) {
                if (Client.MarkForDelete() == false)
                {
                    Line = _ConvertCLientObjectToLine(Client);
                    MyFile << Line << endl;
                }



            }


            MyFile.close();
        }



    }

    void _SaveLineDataToFile(string Line) {

        fstream MyFile;
        MyFile.open("ClientData.txt", ios::app); //write mode now


        if (MyFile.is_open()) {

            MyFile << Line << endl;

            MyFile.close();
        }



    }

    void _Update() {

        vector<clsBankClient> _vClient;
        _vClient = _LoadClientDataFromFile();

        for (clsBankClient& Client : _vClient) {
            if (Client.AccountNumber() == AccountNumber()) {
                Client = *this;
                break;
            }
        }
        _SaveClientDataToFile(_vClient);


    }

    void _AddNew() {
        return _SaveLineDataToFile(_ConvertCLientObjectToLine(*this));
    }

    string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient,
        string UserName, string Seperator = "#//#")
    {
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::DateToString(clsDate()) + Seperator;
        TransferLogRecord += AccountNumber() + Seperator;
        TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(AccountBalance) + Seperator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferLogRecord += UserName;
        return TransferLogRecord;
    }
    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {

        string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

public:

    clsBankClient(enMode  mode, string FirstName, string LastName, string Email, string Phone
        , string AccountNumber, string Pincode, float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone) {
        _Mode = mode;
        _AccountNumber = AccountNumber;
        _Pincode = Pincode;
        _AccountBalance = AccountBalance;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPincode(string Pincode) {
        _Pincode = Pincode;
    }
    string GetPincode() {
        return _Pincode;
    }

    __declspec(property(get = GetPincode, put = SetPincode)) string Pincode;


    void SetAccountBalance(float AccountBalance) {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance() {
        return _AccountBalance;
    }

    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    bool MarkForDelete() {
        return _MarkForDelete;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    static clsBankClient Find(string AccountNumber) {
        

        fstream MyFile;
        MyFile.open("ClientData.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {
                clsBankClient Client = _ConvertLinetoClinetObject(Line);

                if (Client.AccountNumber() == AccountNumber) {
                    MyFile.close();
                    return Client;

                }


            }

            MyFile.close();
        }

        return _GetEmptyCLient();

    }
    static clsBankClient Find(string AccountNumber, string Pincode) {
        vector<string> vLines;

        fstream MyFile;
        MyFile.open("ClientDate.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {
                clsBankClient Client = _ConvertLinetoClinetObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.Pincode == Pincode) {
                    return Client;
                    MyFile.close();
                }

                vLines.push_back(Line);
            }

            MyFile.close();
        }

        return _GetEmptyCLient();

    }

    static bool IsClietExist(string AccountNumber) {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());

    }

    static clsBankClient GetAddNewClient(string AccountNumber) {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    enum enSaveResults { svFaildEmprtyObject = 0, svSucceeded = 1, svFaildExistObject = 2 };
    enSaveResults save() {
        switch (_Mode)
        {
        case clsBankClient::EmptyMode:
        {
            return enSaveResults::svFaildEmprtyObject;
        }
        case clsBankClient::UpdateMode:
        {

            _Update();
            return enSaveResults::svSucceeded;

            break;
        }
        case clsBankClient::AddNewMode:
        {

            while (clsBankClient::IsClietExist(AccountNumber()))
            {
                return enSaveResults::svFaildExistObject;
            }
            _AddNew();
            return enSaveResults::svSucceeded;

            break;
        }
        }
    }



    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }

        }

        _SaveClientDataToFile(_vClients);

        *this = _GetEmptyCLient();

        return true;

    }

    void ReadClientInfo(clsBankClient& Client) {
        cout << "------------------------";
        cout << "Card Details : \n";
        cout << "\n----------------------------\n";
        cout << "First Name      : ";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "\nLast Name       : ";
        Client.LastName = clsInputValidate::ReadString();
        cout << "\nEmail           : ";
        Client.Email = clsInputValidate::ReadString();
        cout << "\nPhone           : ";
        Client.Phone = clsInputValidate::ReadString();
        cout << "\nAccount Number  : ";
        Client.AccountNumber() = clsInputValidate::ReadString();
        cout << "\nPincode         : ";
        Client.Pincode = clsInputValidate::ReadString();
        cout << "Account Balance : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
        cout << "\n----------------------------";

    }





    void Print() {
        cout << "Card Details : \n";
        cout << "----------------------------\n";
        cout << "First Name      : " << FirstName;
        cout << "\nLast Name       : " << LastName;
        cout << "\nEmail           : " << Email;
        cout << "\nPhone           : " << Phone;
        cout << "\nAccount Number  : " << AccountNumber();
        cout << "\nPincode         : " << Pincode;
        cout << "\nAccount Balance : " << AccountBalance;
        cout << "\n----------------------------";
    }

    static vector<clsBankClient> GetClientList() {
        return _LoadClientDataFromFile();
    }

    static double GetTotalBalances() {
        vector<clsBankClient> vClient = clsBankClient::GetClientList();

        double TotalBalance{};

        for (clsBankClient Client : vClient) {
            TotalBalance += Client.AccountBalance;
        }

        return TotalBalance;
    }

    static void PrintClientRecordLine(clsBankClient Client) {
        cout << "| " << Client.AccountNumber() << setw(15);
        cout << "| " << Client.FirstName << setw(9);
        cout << "| " << Client.LastName << setw(9);
        cout << "| " << Client.Email << setw(7);
        cout << "| " << Client.Pincode << setw(7);
        cout << "| " << Client.Phone << setw(7);
        cout << "| " << Client.AccountBalance;

    }

    static void PrintClientRecordLineBalances(clsBankClient Client) {
        cout << "| " << Client.AccountNumber() << setw(25);
        cout << "| " << Client.FirstName + " " + Client.LastName << setw(14);
        cout << "| " << Client.AccountBalance;

    }

    static void TotalBalances() {

        vector <clsBankClient> vClient = GetClientList();

        cout << setw(80) << "------------------------------------------" << endl;
        cout << setw(65) << "* Client List *" << endl;
        cout << setw(80) << "------------------------------------------" << endl;
        cout << setw(80) << "------------------------------------------" << endl;
        cout << setw(65) << "Total Client : " << vClient.size() << endl;
        cout << setw(80) << "------------------------------------------" << endl;
        cout << "\n\n" << "| " << "Account Number" << setw(15);
        cout << "| " << "Name Client" << setw(15);
        cout << "| " << "Account Balance" << endl;

        cout << "----------------------------------------";
        cout << "---------------------------------\n";



        if (vClient.size() == 0)
            cout << "There are no clients";
        else
            for (clsBankClient& Client : vClient)
            {

                PrintClientRecordLineBalances(Client);
                cout << "\n";
            }

        cout << "----------------------------------------";
        cout << "---------------------------------\n";

        double TotalBalance = clsBankClient::GetTotalBalances();
        cout << setw(35) << "Total Balance = " << TotalBalance;

    }

    void Deposit(double Amount) {
        _AccountBalance += Amount;
        save();
    }
    bool Withdraw(double Amount) {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            save();
        }

    }

    bool Transfer(double Amount, clsBankClient& TransferredClient, string UserName)
    {
        if (Amount > AccountBalance)
        {
            return false;
        }
        Withdraw(Amount);
        TransferredClient.Deposit(Amount);
        _RegisterTransferLog(Amount, TransferredClient,UserName);
        return true;

    }
};

