#pragma once
#include<bits/stdc++.h>
using namespace std;
class clsPerson
{
protected:
    int _id;
    string _FirstName;
    string _LastName;
    string _phone;
    string _Email;
    static int c;

public:

    clsPerson() {};
    int NOofPersons() { return c; }

    clsPerson(string fName, string lName, string phone, string Email) :
        _FirstName(fName), _LastName(lName), _phone(phone), _Email(Email)
    {
        c++;_id = c;
    };

    void setfName(string fname) { _FirstName = fname; }
    string getfName() { return _FirstName; }

    void setlName(string lname) { _LastName = lname; }
    string getlName() { return _LastName; }

    void setPhone(string phone) { _phone = phone; }
    string getPhone() { return _phone; }

    void setEmail(string Email) { _Email = Email; }
    string getEmail() { return _Email; }

    string FullName() {
        return _FirstName + ' ' + _LastName;
    }


    int getID() { return _id; }

};
int clsPerson::c = 0;

