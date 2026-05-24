#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsUser.h"
class clsShowAddUser :private clsScreen
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
        cout << "Enter Password:\n";
        User.SetPassword(clsInputValidate::Readstring());
        cout << "Enter Permissions:\n";
        User.SetPermissions(clsInputValidate::ReadNumber<int>("Error in set permissions\n"));

    }

public:
    static void ShowAddUser() {
        _Title("\t\t\t\t\t\tAdd New User");


        string Username = "";

        do {
            cout << "Enter Username :\n";
            Username = clsInputValidate::Readstring();
            if ((clsUser::IsUserExist(Username))) {
                cout << "This Account Number is already exist\n";
            }
            else { break; }
        } while (true);
        clsUser User = clsUser::GetAddNewUserObject(Username);
        _ReadUserInfo(User);
        clsUser::enSaveResults save;
        save = User.Save();
        switch (save)
        {
        case clsUser::enSaveResults::svFaildEmptyObject:
            cout << "Failed!\n";
            break;

        case clsUser::enSaveResults::svFaildUserExists:
            cout << "Sorry, This Account Number is already exist\n";
            break;

        case clsUser::enSaveResults::svSucceeded:
            cout << "succeeded!\n";
            User.print();
            break;

        default:
            break;
        }



    }

};

