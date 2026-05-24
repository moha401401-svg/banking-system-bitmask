#pragma once
#include<bits/stdc++.h>
#include "../../clsScreen.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
class clsShowDeleteClient :private clsScreen
{
private:

public:
    static void DeleteClient() {
        if (!clsScreen::CheckPermissionRights(clsUser::ePermissions::DeleteClient)) { return; }
        _Title("\t\t\t\t\t\tDelete Client");

        cout << "Enter AccountNumber\n";
        string AccountNumber = clsInputValidate::Readstring();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Account number is not exist\n";
            AccountNumber = clsInputValidate::Readstring();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        client.print();
        char x;
        cout << "Are you sure you want delete it? (Y/N) -> ";
        cin >> x;
        if (x != 'y' && x != 'Y') { cout << "cancled!\n";return; }
        if (client.Delete()) { cout << "removed!\n";client.print(); }
        else { cout << "cannot delete!\n"; }
    }

};


