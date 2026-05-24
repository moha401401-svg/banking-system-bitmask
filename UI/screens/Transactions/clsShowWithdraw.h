#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
class clsShowWithdraw :private clsScreen
{

public:
    static  void Withdraw() {
        _Title("\t\t\t\t\t\tWithdraw Screen");
        cout << "Enter AccountNumber\n";
        string AccountNumber = clsInputValidate::Readstring();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Account number is not exist\n";
            AccountNumber = clsInputValidate::Readstring();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        double b = client.getAccountBalance();
        cout << "Your Balance is =>" << b << "\n";
        char x;
        cout << "Are you sure you want to Withdraw? (Y/N) -> ";
        cin >> x;
        if (x != 'y' && x != 'Y') { cout << "cancled!\n";return; }
        cout << "Enter the Amount:\n";
        double A; cin >> A;
        while (A > b) {
            cout << "just can withdtaw until(" << b << ")\n";
            cout << "Enter the Amount:\n";
            cin >> A;
        }
        b -= A;
        client.setAccountBalance(b);
        cout << "Your Balance became =>" << b << "\n";
    }

};

