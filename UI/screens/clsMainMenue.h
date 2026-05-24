#pragma once
#include<bits/stdc++.h>
#include "../clsScreen.h"
#include "../../core/clsUtil.h"
#include "../../core/clsInputValidate.h"
#include <conio.h>
#include "manage_client/clsShowClientList.h"
#include "manage_client/clsShowAddClient.h"
#include "manage_client/clsShowDeleteClient.h"
#include "manage_client/clsShowUpdateClient.h"
#include "manage_client/clsShowFindClient.h"
#include "Transactions/clsShowTransScreen.h"
#include "manage_user/clsShowUserMenue.h"
#include "Auth/clsLog.h"
#include "Currency/clsShowCurrencyMenue.h"
#include "../../clsGlobal.h"


using namespace std;
class clsMainMenue : protected clsScreen {
protected:
    enum eMainMenueOption {
        eAddClient = 1, eShowClient = 2, eUpdateClient = 3, eDeleteClient = 4
        , eFindClient = 5, eShowTrancaction = 6, eShowManageUsers = 7, elog = 8, eCurrency = 9, eExit = 10

    };
    static void _AddClient() {
        clsShowAddClient::ShowAddClient();
    }
    static void _ShowClient() {
        clsShowClientList::ShowClients();

    }
    static  void _UpdateClient() {
        clsShowUpdateClient::UpdateClient();
    }
    static void _DeleteClient() {
        clsShowDeleteClient::DeleteClient();
    }
    static void _FindClient() {
        clsShowFindClient::ShowClientCard();
    }
    static  void _ShowTrancaction() {
        clsShowTransScreen::ShowTransMenue();
    }
    static  void _ShowManageUsers() {
        clsShowUserMenue::ShowUserMenue();
    }
    static  void _ShowLogRegister() {
        clsLog::ShowLogScreen();
    }
    static void _ShowCurrencyMenue() {
        clsShowCurrencyMenue::ShowCurrencyMenue();
    }
    static void _Exit() {
        CurrentUser = clsUser::Find("", "");
    }
    static  void _ReturnToMainMenue() {

        cout << "Press any key to back main menue\n";
        _getch();
        system("cls");
        ShowMainMenue();
    }

    static void _PerformMainMenueOption(eMainMenueOption x) {
        switch (x)
        {
        case eMainMenueOption::eAddClient:
            _AddClient();
            _ReturnToMainMenue();
            break;
        case eMainMenueOption::eShowClient:
            _ShowClient();
            _ReturnToMainMenue();
            break;
        case eMainMenueOption::eUpdateClient:
            _UpdateClient();
            _ReturnToMainMenue();
            break;
        case eMainMenueOption::eDeleteClient:
            _DeleteClient();
            _ReturnToMainMenue();
            break;

        case eMainMenueOption::eFindClient:
            _FindClient();
            _ReturnToMainMenue();
            break;

        case eMainMenueOption::eShowTrancaction:
            _ShowTrancaction();
            _ReturnToMainMenue();
            break;

        case eMainMenueOption::eShowManageUsers:
            _ShowManageUsers();
            _ReturnToMainMenue();
            break;

        case eMainMenueOption::elog:
            _ShowLogRegister();
            _ReturnToMainMenue();
            break;

        case eMainMenueOption::eCurrency:
            _ShowCurrencyMenue();
            _ReturnToMainMenue();
            break;

        case eMainMenueOption::eExit:
            _Exit();
            break;

        default:
            break;
        }
    }

public:
    static void ShowMainMenue() {
        _Title("\t\t\t\t\t\tMain Menue ");
        cout << left << "\t[1] Add new client\n";
        cout << left << "\t[2] Show client list\n";
        cout << left << "\t[3] Update client info\n";
        cout << left << "\t[4] Delete client\n";
        cout << left << "\t[5] Find client\n";
        cout << left << "\t[6] Trancactions\n";
        cout << left << "\t[7] Manage users\n";
        cout << left << "\t[8] Login register\n";
        cout << left << "\t[9] Currency\n";
        cout << left << "\t[10] Logout\n";
        cout << "====================================================================================\n";
        cout << "            choose what do you want to do [1 -> 10]\n";
        short x = clsInputValidate::ReadNumberBetween<short>(1, 10, "Please, Enter Number Between 1 and 10");
        system("cls");
        _PerformMainMenueOption((eMainMenueOption)x);


    }

};

