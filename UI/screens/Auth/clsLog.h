#pragma once
#include<bits/stdc++.h>
#include "../../../models/clsUser.h"
#include "../../clsScreen.h"
#include "../../../clsGlobal.h"
#include "../../../core/clsString.h"
class clsLog : private clsScreen
{
private:
    static vector<pair<string, clsUser>> _Decode() {
        fstream file;
        file.open("login.log", ios::in);
        if (file.is_open()) {
            string line;
            vector<pair<string, clsUser>>vTimeUser;
            while (getline(file, line)) {
                if (line.empty()) { continue; }
                vector<string>s = clsString::BeforeAfterSeperator(line, "#");
                if (s.size() < 2 || s[0].empty() || s[1].empty()) { continue; }
                clsUser user = clsUser::_ConvertLinetoUserObject(s[1]);
                vTimeUser.push_back({ s[0],user });

            }
            file.close();
            return vTimeUser;
        }
        return {};
    }

public:
    static void ShowLogScreen() {
        if (!clsScreen::CheckPermissionRights(clsUser::ePermissions::ShowLog)) { return; }
        vector<pair<string, clsUser>> vTimeUser = _Decode();
        string title = "\t\t\t\t\t\t Log Screen[";
        title += to_string(vTimeUser.size());
        title += "]\n";
        _Title(title);
        cout << "| " << left << setw(30) << "Date";
        cout << "| " << left << setw(15) << "Username";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(20) << "Email";
        cout << "\n======================================================================================================================\n";
        if (vTimeUser.empty()) { return; }
        for (auto& C : vTimeUser) {
            cout << "| " << left << setw(30) << C.first;
            cout << "| " << left << setw(15) << C.second.GetUserName();
            cout << "| " << left << setw(15) << C.second.GetPassword();
            cout << "| " << left << setw(20) << C.second.FullName();
            cout << "| " << left << setw(20) << C.second.getEmail();
            cout << endl;
        }
        cout << "======================================================================================================================\n";

    }

};


