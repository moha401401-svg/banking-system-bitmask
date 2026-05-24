#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsUser.h"
class clsShowUpdateUser :private clsScreen
{
private:
    static  void _ReadUserInfo(clsUser& User) {
        cout << "Enter First Name:\n";
        User.setfName(clsInputValidate::Readstring());
        cout << "Enter last Name:\n";
        User.setlName(clsInputValidate::Readstring());
        cout << "Enter Email :\n";
        User.setEmail(clsInputValidate::Readstring());
        cout << "Enter phone:\n";
        User.setPhone(clsInputValidate::Readstring());
        cout << "Enter PINcode:\n";
        User.SetPassword(clsInputValidate::Readstring());
        cout << "Enter Permissions:\n";
        User.SetPermissions(clsInputValidate::ReadNumber<int>("Error in set permissions\n"));

    }
public:
    static  void UpdateUser() {
        _Title("\t\t\t\t\t\tUpdate User");
        cout << "Enter Username\n";
        string Username = clsInputValidate::Readstring();
        while (!clsUser::IsUserExist(Username)) {
            cout << "Username is not exist\n";
            Username = clsInputValidate::Readstring();
        }
        clsUser User = clsUser::Find(Username);
        User.print();
        cout << "\t\t\t\t\t\tUpdate User Info\n";
        cout << "\n======================================================================================================================\n";
        _ReadUserInfo(User);

        clsUser::enSaveResults save;
        save = User.Save();
        switch (save)
        {
        case clsUser::enSaveResults::svFaildUserExists:
            cout << "Failed!\n";
            break;

        case clsUser::enSaveResults::svSucceeded:
            cout << "Succeeded!\n";
            User.print();
            break;

        default:
            break;
        }
    }


};


