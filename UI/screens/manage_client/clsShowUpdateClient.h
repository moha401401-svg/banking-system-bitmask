#pragma once
#include<bits/stdc++.h>
#include "../../clsScreen.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
class clsShowUpdateClient :private clsScreen
{
private:
    static  void _ReadClientInfo(clsBankClient& client) {
        cout << "Enter First Name:\n";
        client.setfName(clsInputValidate::Readstring());
        cout << "Enter last Name:\n";
        client.setlName(clsInputValidate::Readstring());
        cout << "Enter Email :\n";
        client.setEmail(clsInputValidate::Readstring());
        cout << "Enter phone:\n";
        client.setPhone(clsInputValidate::Readstring());
        cout << "Enter PINcode:\n";
        client.setPINcode(clsInputValidate::Readstring());
        cout << "Enter AccountBalance:\n";
        client.setAccountBalance(clsInputValidate::ReadNumber<float>("Error"));
    }
public:

    static  void UpdateClient() {
        if (!clsScreen::CheckPermissionRights(clsUser::ePermissions::UpdateClient)) { return; }
        _Title("\t\t\t\t\t\tUpdate Client");

        cout << "Enter AccountNumber\n";
        string AccountNumber = clsInputValidate::Readstring();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Account number is not exist\n";
            AccountNumber = clsInputValidate::Readstring();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        client.print();
        cout << "\t\t\t\t\t\tUpdate Client Info\n";
        cout << "\n======================================================================================================================\n";
        _ReadClientInfo(client);

        clsBankClient::enSaveResult save;
        save = client.Save();
        switch (save)
        {
        case clsBankClient::enSaveResult::svFaild:
            cout << "Failed!\n";
            break;

        case clsBankClient::enSaveResult::svSucceeded:
            cout << "Succeeded!\n";
            client.print();
            break;

        default:
            break;
        }
    }

};

