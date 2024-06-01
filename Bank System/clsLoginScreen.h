#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUsers.h"
#include <iomanip>
#include <fstream>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  void _Login()
    {
        bool LoginFaild = false;
        int  FaildLoginCounter = 3;
        string Username, Password;
        do
        {
           
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password! -(\n\n";
                cout << "You now have " << FaildLoginCounter << " attempt" << endl;
                
            }
            FaildLoginCounter--;
            clsSpaces::ManySpaces(44);
            cout << "+===============================+\n";
            clsSpaces::ManySpaces(47);
            cout << "Enter Username :  ";
            cin >> Username;
            clsSpaces::ManySpaces(44);
            cout << "+===============================+\n";
            clsSpaces::ManySpaces(47);
            cout << "Enter Password :  ";
            cin >> Password;

            clsSpaces::ManySpaces(44);
            cout << "+===============================+\n";
            CurrentUser = clsUsers::Find(Username,Password);
            
            LoginFaild = CurrentUser.IsEmpty();
            if (FaildLoginCounter == 0) {
                return;
            }

        } while (LoginFaild);
        system("cls");
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMeneu();
        
    }

public:


    static void ShowLoginScreen()
    {
        
        clsScreen::HeaderBank("NOOAH BANK");
        clsScreen::HeaderBankProparty("Login");
        
        _Login();
        system("cls");
    }

};


