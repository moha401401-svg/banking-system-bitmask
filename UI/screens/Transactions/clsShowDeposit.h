#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
class clsShowDeposit :private clsScreen
{
private:

public:
    static  void Deposit() {
        _Title("\t\t\t\t\t\tDepsit Screen");
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
        cout << "Are you sure you want to Deposit? (Y/N) -> ";
        cin >> x;
        if (x != 'y' && x != 'Y') { cout << "cancled!\n";return; }
        cout << "Enter the Amount:\n";

        double A; cin >> A;
        while (A <= 0) {
            cout << "Please, Enter a postive amount\n";
            cin >> A;
        }
        b += A;
        client.setAccountBalance(b);
        cout << "Your Balance became =>" << b << "\n";
    }

};


