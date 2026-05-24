#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
#include "clsShowDeposit.h"
#include "clsShowWithdraw.h"
#include "clsShowBalances.h"
#include "clsShowTransfer.h"
#include "clsShowLogTransfer.h"
class clsShowTransScreen :private clsScreen
{
private:
    enum eTrans {
        eDeposit = 1, eWithdraw = 2, eTotalBalnces = 3, eTransfer = 4
        , eLogTransfer = 5, eBackMainMenue = 6
    };
    static void _Deposit() {
        clsShowDeposit::Deposit();
    }
    static void _Withdraw() {
        clsShowWithdraw::Withdraw();
    }
    static void _TotalBalnces() {
        clsShowBalances::TotalBalances();
    }
    static void _Transfer() {
        clsShowTransfer::Transfer();
    }
    static void _LogTransfer() {
        clsShowLogTransfer::ShowLogTransferScreen();
    }
    static void _BackTranactionMenue() {
        cout << "Press any key to back Tranaction Menue\n";
        _getch();
        system("cls");
        ShowTransMenue();
    }

    static void  _PreformTransactionOption(eTrans t) {
        switch (t)
        {
        case eTrans::eDeposit:
            _Deposit();
            _BackTranactionMenue();
            break;

        case eTrans::eWithdraw:
            _Withdraw();
            _BackTranactionMenue();
            break;

        case eTrans::eTotalBalnces:
            _TotalBalnces();
            _BackTranactionMenue();
            break;

        case eTrans::eTransfer:
            _Transfer();
            _BackTranactionMenue();
            break;

        case eTrans::eLogTransfer:
            _LogTransfer();
            _BackTranactionMenue();
            break;


        case eTrans::eBackMainMenue:
            break;

        default:
            break;
        }

    }
public:

    static void ShowTransMenue() {
        if (!clsScreen::CheckPermissionRights(clsUser::ePermissions::ShowTrancaction)) { return; }
        _Title("\t\t\t\t\t\tTransaction Menue");

        cout << "\t[1] deposit\n";
        cout << "\t[2] withdraw\n";
        cout << "\t[3] show balance table\n";
        cout << "\t[4] Transfer\n";
        cout << "\t[5] log Transfer\n";
        cout << "\t[6] main menue\n";
        cout << "========================================================================\n";
        cout << "            choose what do you want to do [1 -> 6]\n";
        short x = clsInputValidate::ReadNumberBetween(1, 6, "Must be between 1 and 6\n");
        system("cls");
        return _PreformTransactionOption((eTrans)x);


    }





};


