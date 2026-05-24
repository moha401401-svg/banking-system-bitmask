#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsUser.h"
class clsShowUserList :private clsScreen
{
private:

public:
    static void ShowUsers() {
        vector<clsUser>vUsers = clsUser::_LoadUsersDataFromFile();
        string title = "\t\t\t\t\t\t UserList[";
        title += to_string(vUsers.size());
        title += "]\n";
        _Title(title);
        cout << "| " << left << setw(15) << "First Name";
        cout << "| " << left << setw(15) << "last Name";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "phone";
        cout << "| " << left << setw(15) << "USername";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n======================================================================================================================\n";
        if (vUsers.empty()) { return; }
        for (clsUser C : vUsers) {
            cout << "| " << left << setw(15) << C.getfName();
            cout << "| " << left << setw(15) << C.getlName();
            cout << "| " << left << setw(20) << C.getEmail();
            cout << "| " << left << setw(12) << C.getPhone();
            cout << "| " << left << setw(15) << C.GetUserName();
            cout << "| " << left << setw(10) << C.GetPassword();
            cout << "| " << left << setw(12) << C.GetPermissions();
            cout << endl;
        }
        cout << "======================================================================================================================\n";

    }
};


