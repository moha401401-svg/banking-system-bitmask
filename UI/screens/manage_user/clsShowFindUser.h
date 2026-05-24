#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsUser.h"
class clsShowFindUser :private clsScreen
{
private:

public:
    static void ShowUserCard() {
        _Title("\t\t\t\t\t\tFind User");
        cout << "Enter Username\n";
        string Username = clsInputValidate::Readstring();
        while (!clsUser::IsUserExist(Username)) {
            cout << "Username is not exist\n";
            Username = clsInputValidate::Readstring();
        }
        clsUser User = clsUser::Find(Username);
        User.print();
    }

};

