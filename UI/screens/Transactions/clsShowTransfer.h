#pragma once
#include<bits/stdc++.h>
#include "../clsMainMenue.h"
#include "../../../core/clsDate.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
#include "../../../clsGlobal.h"
class clsShowTransfer : private clsScreen
{
private:
    static void _LogTransfer(clsBankClient client1, clsBankClient client2, double A) {
        fstream file;
        file.open("transfer.log", ios::out | ios::app);
        stringstream s;
        string sep = "#//#";
        if (file.is_open()) {
            string line;
            s << clsDate::DateToStringAll(clsDate()) << sep << client1.getAccountNumber()
                << sep << client2.getAccountNumber() << sep << A << sep << client1.getAccountBalance()
                << sep << client2.getAccountBalance() << sep << CurrentUser.GetUserName() << '\n';
            line = s.str();
            file << line;
            file.close();
        }

    }
public:
    static void Transfer() {
        _Title("\t\t\t\t\t\tTransfer Screen");
        cout << "Enter AccountNumber to transfer from:\n";
        string AccountNumber1 = clsInputValidate::Readstring();
        while (!clsBankClient::IsClientExist(AccountNumber1)) {
            cout << "Account number is not exist\n";
            AccountNumber1 = clsInputValidate::Readstring();
        }
        clsBankClient client1 = clsBankClient::Find(AccountNumber1);
        client1.print();
        cout << "Enter Account Number to transfer to:\n";
        string AccountNumber2 = clsInputValidate::Readstring();
        while (!clsBankClient::IsClientExist(AccountNumber2) || AccountNumber1 == AccountNumber2) {
            if (AccountNumber1 == AccountNumber2) { cout << "can not transfer to yourself!\n"; }
            else { cout << "Account number is not exist\n"; }
            AccountNumber2 = clsInputValidate::Readstring();
        }

        clsBankClient client2 = clsBankClient::Find(AccountNumber2);
        client2.print();
        char x;
        cout << "Are you sure you want to Transfer? (Y/N) -> ";
        cin >> x;
        if (x != 'y' && x != 'Y') { cout << "cancled!\n";return; }

        double b1 = client1.getAccountBalance(), b2 = client2.getAccountBalance();


        cout << "Enter the Amount:\n";
        double A; cin >> A;
        while (A > b1) {
            cout << "just can transfer until(" << b1 << ")\n";
            cout << "Enter the Amount:\n";
            cin >> A;
        }
        cout << "Succeeded!\n";
        b1 -= A;
        b2 += A;
        client1.setAccountBalance(b1);
        client2.setAccountBalance(b2);
        _LogTransfer(client1, client2, A);
        client1.print();
        client2.print();

    }

};

