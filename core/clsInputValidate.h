#pragma once
#include <bits/stdc++.h>
#include "clsUtil.h"
#include "clsDate.h"
#include "clsString.h"
class clsInputValidate
{
private:

public:


  template<typename T>
  static bool IsNumberBetween(T num, T begin, T end) {
    return ((num >= begin) && (num <= end));
  }



  static bool IsDateBetween(clsDate d, clsDate d1, clsDate d2) {
    if (clsDate::IsDate1AfterDate2(d1, d2)) {
      return clsDate::IsDate1AfterDate2(d, d2) && clsDate::IsDate1AfterDate2(d1, d);
    }
    else {
      return clsDate::IsDate1AfterDate2(d, d1) && clsDate::IsDate1AfterDate2(d2, d);
    }

  }


  template<typename T>
  static T ReadNumber(const string& error) {
    T x;

    while (!(cin >> x))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << error << endl;
    }
    return x;
  }

  static string Readstring() {
    string x;
    cin >> x;

    return x;
  }
  template<typename T>
  static T ReadNumberBetween(const T& begin, const T& end, const string& error)
  {
    T x;

    while (true)
    {
      if (!(cin >> x))
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << error << endl;
        continue;
      }

      if (x < begin || x > end)
      {
        cout << error << endl;
        continue;
      }

      return x;
    }
  }

  static bool IsValidDate(clsDate d1) {
    return clsDate::IsValidDate(d1);
  }








};


