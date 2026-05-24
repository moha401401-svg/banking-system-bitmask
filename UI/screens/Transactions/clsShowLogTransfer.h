#pragma once
#include<bits/stdc++.h>
#include "../../../models/clsUser.h"
#include "../../clsScreen.h"
#include "../../../clsGlobal.h"
#include "../../../core/clsString.h"
class clsShowLogTransfer : private clsScreen
{
private:
    struct _logTrans {
        string Date;
        string FirstAccountNumber;
        string SecondAccountNumber;
        double Amount;
        double FirstAccountBalance;
        double SecondAccountBalance;
        string Username;
    };
    static  vector<_logTrans>  _Decode() {
        fstream file;
        file.open("transfer.log", ios::in);
        if (file.is_open()) {
            vector<_logTrans>vLogs;
            vector<string>log;
            string line;

            while (getline(file, line)) {
                _logTrans a;
                log = clsString::Split(line, "#//#");
                if (log.size() < 7) { continue; }
                a.Date = log[0];
                a.FirstAccountNumber = log[1];
                a.SecondAccountNumber = log[2];
                a.Amount = stod(log[3]);
                a.FirstAccountBalance = stod(log[4]);
                a.SecondAccountBalance = stod(log[5]);
                a.Username = log[6];
                vLogs.push_back(a);


            }
            file.close();
            return vLogs;
        }
        return {};
    }
public:
    static void ShowLogTransferScreen() {
        vector<_logTrans> vLogs = _Decode();
        string title = "\t\t\t\t\t\t Log Transfer Screen[";
        title += to_string(vLogs.size());
        title += "]\n";
        _Title(title);
        cout << "| " << left << setw(25) << "Date";
        cout << "| " << left << setw(11) << "AN1";
        cout << "| " << left << setw(11) << "AN2";
        cout << "| " << left << setw(12) << "Ammount";
        cout << "| " << left << setw(10) << "AB1";
        cout << "| " << left << setw(10) << "AB2";
        cout << "| " << left << setw(20) << "username";
        cout << "\n======================================================================================================================\n";
        if (vLogs.empty()) { return; }
        for (auto& C : vLogs) {
            cout << "| " << left << setw(25) << C.Date;
            cout << "| " << left << setw(11) << C.FirstAccountNumber;
            cout << "| " << left << setw(11) << C.SecondAccountNumber;
            cout << "| " << left << setw(12) << C.Amount;
            cout << "| " << left << setw(10) << C.FirstAccountBalance;
            cout << "| " << left << setw(10) << C.SecondAccountBalance;
            cout << "| " << left << setw(20) << C.Username;
            cout << endl;
        }
        cout << "======================================================================================================================\n";

    }


};


