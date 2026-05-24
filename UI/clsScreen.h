#pragma once
#include<bits/stdc++.h>
#include "../clsGlobal.h"
#include "../models/clsUser.h"
#include "../core/clsDate.h"
using namespace std;
class clsScreen
{
protected:
    static bool CheckPermissionRights(clsUser::ePermissions Permission) {
        if (!CurrentUser.CheckPermission(Permission)) {
            cout << "======================================================================================================================\n";
            cout << " |You do not have a access for that|\nplease, contact to your manager...\n" << "\n";
            cout << "======================================================================================================================\n\n";
            return false;
        }
        return true;
    }

    static void  _Title(const string Name) {
        clsDate date = clsDate::GetSystemDate();
        cout << '\n';
        cout << "user: " << CurrentUser.GetUserName() << endl;
        cout << "Date: " << clsDate::DateToString(date);

        cout << "\n======================================================================================================================\n";
        cout << Name << "\n";
        cout << "======================================================================================================================\n\n";

    }
};

