#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUser.h"
#include "clsAddNewUser.h"
#include "clsDeleteUser.h"
#include "clsUpdateUser.h"
#include "clsFIndUser.h"
using namespace std;

class clsManageUsers : protected clsScreen
{
public :
	static void ShowManageUserOption() 
	{
		if (!CheckAccessRights(clsUsers::enPermissions::pManageUser))
		{
			return;// this will exit the function and it will not continue
		}
		clsScreen::HeaderBank("NOOAH BANk");
		clsScreen::HeaderBankProparty("Manage Users");

		clsSpaces::ManySpaces(47);
		cout << "[1] List User.\n";
		clsSpaces::ManySpaces(47);
		cout << "[2] Add New User.\n";
		clsSpaces::ManySpaces(47);
		cout << "[3] Delete User.\n";
		clsSpaces::ManySpaces(47);
		cout << "[4] Update User.\n";
		clsSpaces::ManySpaces(47);
		cout << "[5] Find User.\n";
		clsSpaces::ManySpaces(47);
		cout << "[6] Main menue.\n";
		clsSpaces::ManySpaces(44);
		cout << "+===============================+\n";

		_PerformManageUserOption((enManageUsersOption)_ReadManageUsersOption());

	}
private:
	enum enManageUsersOption {
		eListUser = 1,eAddNewUser = 2, eDeleteUser = 3,eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};
	static short _ReadManageUsersOption() {
		clsSpaces::ManySpaces(48);
		cout << "Choose From [1 to 6] : ";
		short Choose = clsInputValidate::ReadShortNumberBetween(1, 6, "Error! Enter valid Value : ");
		return Choose;
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		system("cls");
		ShowManageUserOption();
	}
	static void _PerformManageUserOption(enManageUsersOption ManageUsersOption) {
		switch (ManageUsersOption)
		{
		case clsManageUsers::eListUser:
		{
			system("cls");
			_ListUser();
			_GoBackToMainMenue();
			break;
		}
		case clsManageUsers::eAddNewUser:
		{
			system("cls");
			_AddNewUser();
			_GoBackToMainMenue();
			break;
		}
		case clsManageUsers::eDeleteUser:
		{
			system("cls");
			_DeleteUser();
			_GoBackToMainMenue();
			break;
		}
		case clsManageUsers::eUpdateUser:
		{
			system("cls");
			_UpdateUser();
			_GoBackToMainMenue();
			break;
		}
		case clsManageUsers::eFindUser:
		{
			system("cls");
			_FindUser();
			_GoBackToMainMenue();
			break;
		}
		case clsManageUsers::eMainMenue:
		{
			
		}
		
		}
	}
	static void _ListUser() {
		clsListUser::ShowUsersList();
	}
	static void _AddNewUser() {
		clsAddNewUser::AddNewUser();
	}
	static void _DeleteUser() {
		clsDeleteUser::DeleteUser();
	}
	static void _UpdateUser() {
		clsUpdateUser::ShowUpdateDataUser();
	}
	static void _FindUser() {
		clsFindUser::FindUserScreen();
	}
	
};

