#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsUser.h"
#include "clsShowAddUser.h"
#include "clsShowUserList.h"
#include "clsShowFindUser.h"
#include "clsShowDeleteUser.h"
#include "clsShowUpdateUser.h"
#include <conio.h>
class clsShowUserMenue :private clsScreen
{
private:
    enum eUser { eUserList = 1, eAddUser = 2, eFindUser = 3, eUpdateUser = 4, eDeleteUser = 5, eBackMainMenue = 6 };
    static void _AddUser() {
        clsShowAddUser::ShowAddUser();
    }
    static void _UpdateUser() {
        clsShowUpdateUser::UpdateUser();
    }
    static void _DeleteUser() {
        clsShowDeleteUser::DeleteUser();
    }
    static void _FindUser() {
        clsShowFindUser::ShowUserCard();
    }
    static void _UserList() {
        clsShowUserList::ShowUsers();
    }






    static void _BackUserMenue() {

        cout << "Press any key to back user menue\n";
        _getch();
        system("cls");
        ShowUserMenue();
    }


    static void  _PerformUserOption(eUser u) {
        switch (u)
        {
        case eUser::eAddUser:
            _AddUser();
            _BackUserMenue();
            break;

        case eUser::eUpdateUser:
            _UpdateUser();
            _BackUserMenue();
            break;

        case eUser::eDeleteUser:
            _DeleteUser();
            _BackUserMenue();
            break;

        case eUser::eFindUser:
            _FindUser();
            _BackUserMenue();
            break;
        case eUser::eUserList:
            _UserList();
            _BackUserMenue();
            break;

        case eUser::eBackMainMenue:
            break;

        default:
            break;
        }
    }
public:
    static void ShowUserMenue() {
        if (!clsScreen::CheckPermissionRights(clsUser::ePermissions::ShowManageUsers)) { return; }
        _Title("\t\t\t\t\t\tManage User Menue");

        cout << "\t[1] List users\n";
        cout << "\t[2] add user\n";
        cout << "\t[3] select user\n";
        cout << "\t[4] update user\n";
        cout << "\t[5] delete user\n";
        cout << "\t[6] main menue\n";
        cout << "========================================================================\n";
        cout << "            choose what do you want to do [1 -> 6]\n";
        short x = clsInputValidate::ReadNumberBetween(1, 6, "Must be between 1 and 6");
        system("cls");
        _PerformUserOption((eUser)x);
    }
};

