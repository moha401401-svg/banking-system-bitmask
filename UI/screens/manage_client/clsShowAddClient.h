#pragma once
#include<bits/stdc++.h>
#include "../../clsScreen.h"
#include "../../../core/clsUtil.h"
#include "../../../core/clsInputValidate.h"
#include "../../../models/clsBankClient.h"
class clsShowAddClient : private clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& client) {
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
    static void ShowAddClient() {
        if (!clsScreen::CheckPermissionRights(clsUser::ePermissions::AddClient)) { return; }
        _Title("\t\t\t\t\t\tAdd New Client");


        string AccountNumber = "";

        do {
            cout << "Enter AccountNumber:\n";
            AccountNumber = clsInputValidate::Readstring();
            if ((clsBankClient::IsClientExist(AccountNumber))) {
                cout << "This Account Number is already exist\n";
            }
            else { break; }
        } while (true);
        clsBankClient client = clsBankClient::AddNewClientObject(AccountNumber);
        _ReadClientInfo(client);
        clsBankClient::enSaveResult save;
        save = client.Save();
        switch (save)
        {
        case clsBankClient::enSaveResult::svFaild:
            cout << "Failed!\n";
            break;

        case clsBankClient::enSaveResult::svAccountNumberIsExist:
            cout << "Sorry, This Account Number is already exist\n";
            break;

        case clsBankClient::enSaveResult::svSucceeded:
            cout << "succeeded!\n";
            client.print();
            break;

        default:
            break;
        }



    }

};


