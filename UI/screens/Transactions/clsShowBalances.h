#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
class clsShowBalances :private clsScreen
{

public:
    static void TotalBalances() {
        vector<clsBankClient>vClients = clsBankClient::ShowAllClients();
        string s = "\t\t\t\t\t\t Balance List[";
        s += to_string(vClients.size());
        s += "]\n";
        _Title(s);
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(15) << "AccountNumber";
        cout << "| " << left << setw(12) << "AccountBalance";
        cout << "\n======================================================================================================================\n";
        if (vClients.empty()) { return; }
        long double b = 0;
        for (clsBankClient C : vClients) {
            cout << "| " << left << setw(20) << C.FullName();
            cout << "| " << left << setw(15) << C.getAccountNumber();
            cout << "| " << left << setw(12) << C.getAccountBalance();
            cout << endl;
            b += C.getAccountBalance();
        }
        cout << "======================================================================================================================\n";
        cout << "Total Balances -> " << b;
        cout << "\n(";clsUtil::FromNumbersToWords(b);cout << ")\n";

    }

};


