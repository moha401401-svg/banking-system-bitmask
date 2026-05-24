#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsUser.h"
#include "../../../clsGlobal.h"
class clsLogin :private clsScreen
{
private:
    static void _RegisterTolog() {
        fstream file;
        file.open("login.log", ios::out | ios::app);
        string line;
        if (file.is_open()) {
            line = clsDate::DateToStringAll(clsDate());
            file << line << "#";
            line = clsUser::_ConverUserObjectToLine(CurrentUser);
            file << line << endl;
            file.close();

        }
    }
    static void _Login() {
        short x = 3;
        string Username = "", Password = "";
        do {
            cout << "Please, Enter the Username:\n";
            cin >> Username;
            cout << "Please, Enter the Password :\n";
            cin >> Password;
            CurrentUser = clsUser::Find(Username, Password);
            if (CurrentUser.IsEmpty()) { cout << "Wrong Username or Password\n"; cout << "You have " << --x << " trails\n"; }
            else { break; }
        } while (CurrentUser.IsEmpty() && x > 0);
        if (x == 0) { exit(0); }
        _RegisterTolog();
        system("cls");
        clsMainMenue::ShowMainMenue();

    }
public:


    static void ShowLogin() {
        _Title("\t\t\t\t\t\t Login");
        _Login();
    }

};

