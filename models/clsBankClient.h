#pragma once
#include<bits/stdc++.h>
#include"clsPerson.h"
#include"../core/clsString.h"
using namespace std;
class clsBankClient :public clsPerson
{
protected:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 3, DeleteMode = 4 };

    enMode _mode;
    string _AccountNumber;
    string _PINcode;
    float _AccountBalance;
    static void _LoadClientsFromFile(vector<clsBankClient>& vClients) {
        fstream file;
        file.open("clients.txt", ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line))
            {
                clsBankClient client = clsBankClient::_ConvertLineToClientObject(line);
                if (!client.IsEmpty()) {
                    vClients.push_back(client);
                }

            }
            file.close();



        }

    }
    static void _SaveClientsT0File(vector<clsBankClient>& vClients) {
        fstream file;
        file.open("clients.txt", ios::out);
        if (file.is_open()) {

            for (clsBankClient C : vClients) {
                string line = _ConvertClientToLine(C);
                file << line << '\n';
            }
            file.close();

        }
    }
    static void _SaveOneClientT0File(string Line) {
        fstream file;
        file.open("clients.txt", ios::out | ios::app);
        if (file.is_open()) {
            file << Line << '\n';
            file.close();
        }



    }
    static  string _ConvertClientToLine(clsBankClient client) {
        string line = "", sep = "#//#";
        line += client.getfName() + sep;
        line += client.getlName() + sep;
        line += client.getEmail() + sep;
        line += client.getPhone() + sep;
        line += client.getAccountNumber() + sep;
        line += client.getPINcode() + sep;
        line += (to_string(client.getAccountBalance()));
        return line;
    }
    static clsBankClient _ConvertLineToClientObject(string Line) {
        vector<string>ss = clsString::Split(Line, "#//#");
        if (ss.size() == 7) {

            return clsBankClient(enMode::UpdateMode, ss[0], ss[1], ss[2], ss[3], ss[4], ss[5], stof(ss[6]));

        }
        return _GetEmptyClientObject();

    }
    static clsBankClient _GetEmptyClientObject() {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    void _update() {
        vector<clsBankClient>vClients;
        _LoadClientsFromFile(vClients);
        for (clsBankClient& C : vClients) {
            if (C.getAccountNumber() == _AccountNumber) { C = *this; }
        }
        _SaveClientsT0File(vClients);
    }
    void _AddClient() {
        string line = _ConvertClientToLine(*this);
        _SaveOneClientT0File(line);
    }



public:
    clsBankClient(enMode mode, string fName, string lName, string Email, string phone
        , string AccountNumber, string PINcode, float AccountBalance) :
        clsPerson(fName, lName, phone, Email),
        _mode(mode), _AccountNumber(AccountNumber), _PINcode(PINcode), _AccountBalance(AccountBalance) {
    };

    string getAccountNumber() { return _AccountNumber; }

    bool IsEmpty() {
        return _mode == enMode::EmptyMode;
    }


    void setPINcode(string PINcode) { _PINcode = PINcode; _update(); }
    string getPINcode() { return _PINcode; }


    void setAccountBalance(float AccountBalance) { _AccountBalance = AccountBalance; _update(); }
    float getAccountBalance() { return _AccountBalance; }


    void print() {
        cout << "\nClient Card: ";
        cout << "\n======================================================================================================================";
        cout << "\nFirstName -> " << _FirstName << '\n';
        cout << "\nLastName -> " << _LastName << '\n';
        cout << "\nFullName -> " << FullName() << '\n';
        cout << "\nEmail -> " << _Email << '\n';
        cout << "\nphone -> " << _phone << '\n';
        cout << "\nAccountNumber -> " << _AccountNumber << '\n';
        cout << "\nPINcode -> " << _PINcode << '\n';
        cout << "\nAccountBalance -> " << _AccountBalance << '\n';
        cout << "\n======================================================================================================================\n";
    }
    static clsBankClient  Find(string AccountNumber) {
        fstream file;
        file.open("clients.txt", ios::in);
        if (file.is_open()) {
            string line;

            while (getline(file, line))
            {
                clsBankClient client = _ConvertLineToClientObject(line);
                if (client.getAccountNumber() == AccountNumber) {
                    file.close();
                    return client;
                }
            }
        }
        file.close();
        return _GetEmptyClientObject();

    }

    static clsBankClient  Find(string AccountNumber, string PINcode) {
        fstream file;
        file.open("clients.txt", ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line))
            {
                clsBankClient client = _ConvertLineToClientObject(line);
                if (client.getAccountNumber() == AccountNumber && client.getPINcode() == PINcode) {
                    file.close();
                    return client;
                }
            }
        }
        file.close();
        cout << "Client is not exists\n";
        return _GetEmptyClientObject();

    }
    static bool  IsClientExist(string AccountNumber) {
        clsBankClient client = clsBankClient::Find(AccountNumber);
        return !client.IsEmpty();


    }
    static clsBankClient AddNewClientObject(string AccountNumber) {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }
    enum enSaveResult { svFaild = 0, svSucceeded = 1, svAccountNumberIsExist = 2 };
    enSaveResult Save() {
        switch (_mode) {
        case enMode::EmptyMode:
            return enSaveResult::svFaild;
            break;

        case enMode::UpdateMode:
            _update();
            return enSaveResult::svSucceeded;
            break;

        case enMode::AddNewMode:
            if (clsBankClient::IsClientExist(_AccountNumber)) {
                return enSaveResult::svAccountNumberIsExist;
            }
            else {
                _AddClient();
                _mode = enMode::UpdateMode;
                return enSaveResult::svSucceeded;
            }

            break;

        default:
            return enSaveResult::svFaild;

        }
    }
    bool Delete() {
        vector<clsBankClient>vClients;
        _LoadClientsFromFile(vClients);
        int x = vClients.size();
        for (size_t i = 0; i < x; i++)
        {
            if (vClients[i].getAccountNumber() == (*this).getAccountNumber()) {
                vClients.erase(vClients.begin() + i);
                break;
            }
        }
        if (vClients.size() >= x) { return false; }
        _SaveClientsT0File(vClients);
        *this = _GetEmptyClientObject();
        return true;


    }
    static  vector<clsBankClient>ShowAllClients() {
        vector<clsBankClient>vClients;
        _LoadClientsFromFile(vClients);
        return vClients;

    }
};