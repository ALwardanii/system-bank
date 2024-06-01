#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtill.h"
class clsUsers : public clsPerson
{

private:
	enum enMode {
		EmptyMode = 0,
		UpdateMode = 1,
		AddNewMode = 2
	};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission = -1;

	

	bool _MarkForDelete = false;
	static clsUsers _ConvertLinetoUserObject(string Line, string Seperator = "#//#") {
		vector <string> vString;
		vString = clsString::Split(Line, Seperator);

		return clsUsers(enMode::UpdateMode, vString.at(0), vString.at(1),
			vString.at(2), vString.at(3), vString.at(4), clsUtill::DecryptText(vString[5]), stod(vString.at(6)));
	}
	string _ConvertUserObjectToLine(clsUsers User, string Seperator = "#//#") {
		string UserRecord ="";

		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += clsUtill::EncryptText(User.Password) + Seperator;
		UserRecord += to_string(User.Permission);

		return UserRecord;

	}
	struct stLoginRegistarRecord ;
	static stLoginRegistarRecord  _ConvertLoginRegisterLineToRecord(string line ,string seperator = "#//#") {
		stLoginRegistarRecord LoginRegisterRecord;

		vector<string> LoginRegisterDataLine = clsString::Split(line,seperator);

		LoginRegisterRecord.DataTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtill::DecryptText(LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);


		return LoginRegisterRecord;
	}
	struct stTransferLog;
	static stTransferLog  _ConvertTransferLogLineToRecord(string line, string seperator = "#//#") {
		stTransferLog TransferLogRecord;

		vector<string> vTransferLogDataLine = clsString::Split(line, seperator);

		TransferLogRecord.DataTime = vTransferLogDataLine[0];
		TransferLogRecord.SourceAccount = vTransferLogDataLine[1];
		TransferLogRecord.DestinationAccount = vTransferLogDataLine[2];
		TransferLogRecord.Amount = stoi(vTransferLogDataLine[3]);
		TransferLogRecord.SourceBalance = stoi(vTransferLogDataLine[4]);
		TransferLogRecord.DestinationBalance = stoi(vTransferLogDataLine[5]);
		TransferLogRecord.UserName = vTransferLogDataLine[6];
		


		return TransferLogRecord;
	}
	static clsUsers _GetEmptyUser() {
		return clsUsers(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector<clsUsers>  _LoadUsersDataFromFile() {

		vector<clsUsers> vUser;

		fstream MyFile;

		MyFile.open("UserData.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsUsers User = _ConvertLinetoUserObject(Line);

				vUser.push_back(User);
			}

			MyFile.close();

		}
		return vUser;
	}
	void _SaveUsersDataToFile(vector <clsUsers> vUser) {

		fstream MyFile;
		MyFile.open("UserData.txt", ios::out); //write mode now

		string Line;
		if (MyFile.is_open()) {
			for (clsUsers& User : vUser) {
				if (User.MarkForDelete() == false)
				{
					Line = _ConvertUserObjectToLine(User);
					MyFile << Line << endl;
				}



			}


			MyFile.close();
		}



	}
	void _SaveLineDataToFile(string Line) {

		fstream MyFile;
		MyFile.open("UserData.txt", ios::out | ios::app); //write mode now


		if (MyFile.is_open()) {

			MyFile << Line << endl;

			MyFile.close();
		}



	}
	void _Update() {

		vector<clsUsers> _vUser;
		_vUser = _LoadUsersDataFromFile();

		for (clsUsers& User : _vUser) {
			if (User.UserName == UserName) {
				User = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vUser);


	}
	void _AddNew() {
		return _SaveLineDataToFile(_ConvertUserObjectToLine(*this));
	}

	string _PrepareRecordLogin(string seperator = "#//#") {
		string Record = "";
		Record += clsDate::DateToString(clsDate()) + seperator;
		Record += UserName + seperator;
		Record += clsUtill::EncryptText(Password) + seperator;
		Record += to_string(Permission);

		return Record;

	}
public:
	enum enPermissions {
		pAll= -1 , pListCLient = 1, pAddNewCLient = 2, pDeleteCLient = 4, pUpdateCLient = 8
	,pFindCLient = 16 , pTranactions = 32 , pManageUser = 64 , PLoginList = 128 };


	struct stLoginRegistarRecord
	{
		string DataTime;
		string UserName;
		string Password;
		int Permissions;
	};


	struct stTransferLog {
		string DataTime;
		string SourceAccount;
		string DestinationAccount;
		int Amount;
		int SourceBalance;
		int DestinationBalance;
		string UserName;
	};

	clsUsers(enMode  mode, string FirstName, string LastName, string Email, string Phone
		, string UserName, string Password, int Permission)
		: clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = mode;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;
	}
	string FullName() {
		return FirstName + LastName;
	}
	void SetUserName(string UserName) {
		_UserName = UserName;
	}
	string GetUserName() {
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	void SetPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	void SetPermission(int Permission) {
		_Permission = Permission;
	}
	int GetPermission() {
		return _Permission;
	}

	__declspec(property(get = GetPermission, put = SetPermission)) int Permission;

	bool MarkForDelete() {
		return _MarkForDelete;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	static clsUsers Find(string UserName) {
		

		fstream MyFile;
		MyFile.open("UserData.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsUsers User = _ConvertLinetoUserObject(Line);

				if (User.UserName == UserName) {
					MyFile.close();
					return User;

				}


			}

			MyFile.close();
		}

		return _GetEmptyUser();

	}
	static clsUsers Find(string UserName, string Password) {


		fstream MyFile;
		MyFile.open("UserData.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) 
			{
				clsUsers User = _ConvertLinetoUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}


			}

			MyFile.close();
		}

		return _GetEmptyUser();

	}
	static bool IsUserExist(string UserName) {

		clsUsers User1 = clsUsers::Find(UserName);
		return (!User1.IsEmpty());

	}
	static clsUsers GetAddNewUser(string AccountNumber) {
		return clsUsers(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	enum enSaveResults { svFaildEmprtyObject = 0, svSucceeded = 1, svFaildExistObject = 2 };
	enSaveResults save() {
		switch (_Mode)
		{
		case clsUsers::EmptyMode:
		{
			return enSaveResults::svFaildEmprtyObject;
		}
		case clsUsers::UpdateMode:
		{

			_Update();
			return enSaveResults::svSucceeded;

			break;
		}
		case clsUsers::AddNewMode:
		{

			while (clsUsers::IsUserExist(UserName))
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
		vector <clsUsers> _vUser;
		_vUser = _LoadUsersDataFromFile();

		for (clsUsers& User : _vUser)
		{
			if (User.UserName == _UserName)
			{
				User._MarkForDelete = true;
				break;
			}

		}

		_SaveUsersDataToFile(_vUser);

		*this = _GetEmptyUser();

		return true;

	}

	static clsUsers GetAddNewUserObject(string UserName)
	{
		return clsUsers(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUsers> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccesPermission(enPermissions Permission) {
		
		if (this->Permission == enPermissions::pAll)
			return true;

		if ((Permission & this->Permission) == Permission)
			return true;
		else
			return false;
	}
	void RegisterLogIn()
	{

		string DataRecord = _PrepareRecordLogin();

		fstream MyFile;
		MyFile.open("LoginData.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << DataRecord << endl;

			MyFile.close();
		}

	}

	static vector<stLoginRegistarRecord> GetLoginList() {
		vector<stLoginRegistarRecord> vLoginRegisterRecord;

		fstream MyFile;
		MyFile.open("LoginData.txt", ios::in);

		if (MyFile.is_open()) 
		{
			string Line;
			
			stLoginRegistarRecord LoginRegisterRecord;
			while (getline(MyFile,Line))
			{
				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
				vLoginRegisterRecord.push_back(LoginRegisterRecord);
			}

			MyFile.close();
		}


		return vLoginRegisterRecord;
	}
	static vector<stTransferLog> GetTransferLoginList() {
		vector<stTransferLog> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			stTransferLog TransferLogRecord;
			while (getline(MyFile, Line))
			{
				TransferLogRecord = _ConvertTransferLogLineToRecord(Line);
				vTransferLogRecord.push_back(TransferLogRecord);
			}

			MyFile.close();
		}


		return vTransferLogRecord;
	}
};

