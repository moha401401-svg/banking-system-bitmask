#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsUser.h"
class clsShowDeleteUser :private clsScreen
{
private:

public:
    static void DeleteUser() {
        _Title("\t\t\t\t\t\tDelete User");
        cout << "Enter Username\n";
        string Username = clsInputValidate::Readstring();
        while (!clsUser::IsUserExist(Username)) {
            cout << "Username is not exist\n";
            Username = clsInputValidate::Readstring();
        }
        clsUser User = clsUser::Find(Username);
        User.print();
        char x;
        cout << "Are you sure you want delete it? (Y/N) -> ";
        cin >> x;
        if (x != 'y' && x != 'Y') { cout << "cancled!\n";return; }
        if (User.Delete()) { cout << "removed!\n";User.print(); }
        else { cout << "cannot delete!\n"; }
    }

};


