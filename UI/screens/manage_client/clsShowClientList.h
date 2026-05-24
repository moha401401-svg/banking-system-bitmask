#pragma once
#include<bits/stdc++.h>
#include "../../clsScreen.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
class clsShowClientList :private clsScreen
{
private:

public:
    static void ShowClients() {
        if (!clsScreen::CheckPermissionRights(clsUser::ePermissions::ShowClient)) { return; }
        vector<clsBankClient>vClients = clsBankClient::ShowAllClients();
        string title = "\t\t\t\t\t\t ClientList[";
        title += to_string(vClients.size());
        title += "]\n";
        _Title(title);

        cout << "| " << left << setw(15) << "First Name";
        cout << "| " << left << setw(15) << "last Name";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "phone";
        cout << "| " << left << setw(15) << "AccountNumber";
        cout << "| " << left << setw(10) << "PINcode";
        cout << "| " << left << setw(12) << "AccountBalance";
        cout << "\n======================================================================================================================\n";
        if (vClients.empty()) { return; }
        for (clsBankClient C : vClients) {
            cout << "| " << left << setw(15) << C.getfName();
            cout << "| " << left << setw(15) << C.getlName();
            cout << "| " << left << setw(20) << C.getEmail();
            cout << "| " << left << setw(12) << C.getPhone();
            cout << "| " << left << setw(15) << C.getAccountNumber();
            cout << "| " << left << setw(10) << C.getPINcode();
            cout << "| " << left << setw(12) << C.getAccountBalance();
            cout << endl;
        }
        cout << "======================================================================================================================\n";

    }


};
