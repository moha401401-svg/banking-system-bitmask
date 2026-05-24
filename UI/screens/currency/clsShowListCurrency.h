#pragma once
#include<bits/stdc++.h>
#include "../../clsScreen.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsCurrency.h"
class clsShowListCurrency : private clsScreen
{
private:

public:
    static void  ListCurrency() {
        vector<clsCurrency>vCurrency = clsCurrency::GetCurrenciesList();
        string title = "\t\t\t\t\t\t ClientList[";
        title += to_string(vCurrency.size());
        title += "]\n";
        _Title(title);

        cout << "| " << left << setw(30) << " Country";
        cout << "| " << left << setw(15) << "CurrencyCode";
        cout << "| " << left << setw(20) << "CurrencyName";
        cout << "| " << left << setw(12) << "Rate";
        cout << "\n==============================================================================================\n";
        if (vCurrency.empty()) { return; }
        for (clsCurrency& C : vCurrency) {
            cout << "| " << left << setw(30) << C.Country();
            cout << "| " << left << setw(15) << C.CurrencyCode();
            cout << "| " << left << setw(20) << C.CurrencyName();
            cout << "| " << left << setw(12) << C.Rate();
            cout << endl;
        }
        cout << "======================================================================================================================\n";

    }

};




