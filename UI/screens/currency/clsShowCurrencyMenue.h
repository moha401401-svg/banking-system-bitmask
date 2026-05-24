#pragma once
#include<bits/stdc++.h>
#include "../../clsScreen.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsCurrency.h"
#include "clsShowListCurrency.h"
#include "clsShowFindCurrency.h"
#include "clsShowUpdateRate.h"
#include "clsShowCurrencyCalc.h"
#include <conio.h>
class clsShowCurrencyMenue : private clsScreen
{
private:

    enum eCurrency {
        eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalc = 4
        , eBackMainMenue = 5
    };
    static void _ListCurrency() {
        clsShowListCurrency::ListCurrency();
    }
    static void _FindCurrency() {
        clsShowFindCurrency::ShowFindCurrency();
    }
    static void _UpdateRate() {
        clsShowUpdateRate::ShowUpdateCurrencyRateScreen();
    }
    static void _CurrencyCalc() {
        clsShowCurrencyCalc::ShowCurrencyCalculatorScreen();
    }

    static void _BackCurrencyMenue() {
        cout << "Press any key to back Currency Menue\n";
        _getch();
        system("cls");
        ShowCurrencyMenue();
    }

    static void  _PreformCurrencyOption(eCurrency t) {
        switch (t)
        {
        case eCurrency::eListCurrency:
            _ListCurrency();
            _BackCurrencyMenue();
            break;

        case eCurrency::eFindCurrency:
            _FindCurrency();
            _BackCurrencyMenue();
            break;

        case eCurrency::eUpdateRate:
            _UpdateRate();
            _BackCurrencyMenue();
            break;

        case eCurrency::eCurrencyCalc:
            _CurrencyCalc();
            _BackCurrencyMenue();
            break;


        case eCurrency::eBackMainMenue:
            break;

        default:
            break;
        }

    }
public:

    static void ShowCurrencyMenue() {
        if (!clsScreen::CheckPermissionRights(clsUser::ePermissions::Currency)) { return; }
        _Title("\t\t\t\t\t\t Currency Menue");

        cout << "\t[1] List Currencies\n";
        cout << "\t[2] Find Currency\n";
        cout << "\t[3] Update Rate\n";
        cout << "\t[4] Currency Calcolator\n";
        cout << "\t[5] main menue\n";
        cout << "========================================================================\n";
        cout << "            choose what do you want to do [1 -> 5]\n";
        short x = clsInputValidate::ReadNumberBetween(1, 6, "Must be between 1 and 5\n");
        system("cls");
        return _PreformCurrencyOption((eCurrency)x);
    }
};
