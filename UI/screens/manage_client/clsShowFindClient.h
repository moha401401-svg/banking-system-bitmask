#pragma once
#include<bits/stdc++.h>
#include "../../clsScreen.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
class clsShowFindClient :private clsScreen
{
private:

public:
    static void ShowClientCard() {
        if (!clsScreen::CheckPermissionRights(clsUser::ePermissions::FindClient)) { return; }
        _Title("\t\t\t\t\t\tFind Client");

        cout << "Enter AccountNumber\n";
        string AccountNumber = clsInputValidate::Readstring();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Account number is not exist\n";
            AccountNumber = clsInputValidate::Readstring();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        client.print();
    }



};
