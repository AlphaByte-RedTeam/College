//
//  fungsi1.cpp
//  Pert1
//
//  Created by Maya Cendana on 28/09/20.
//  Copyright © 2020 Maya Cendana. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>
using namespace std;

int main()
{
    int num;
    double firstNum, secondNum;
    char ch = 'T';
    cout << fixed << showpoint << setprecision (2)
         << endl;
    cout << "Apakah " << ch
         << " adalah huruf kecil? "
         << islower(ch) << endl;
    cout << "Huruf besar dari a adalah "
         << static_cast<char>(toupper('a')) << endl;
    cout << "2.5 pangkat 2.0 = " << pow(2.5, 2.0)
        << endl << endl;
    cout << "Tuliskan 2 bilangan desimal: ";
    cin >> firstNum >> secondNum;
    cout << endl;
    cout << "Angka " << firstNum
         << " pangkat " << secondNum
         << " = " << pow(firstNum, secondNum) << endl;
    cout << "2.5 pangkat 2.0 = " << pow(2.5, 2.0) << endl;
    firstNum = firstNum + pow(2.5, 2.0);
    cout << "Angka pertama = " << firstNum << endl;
    num = -32;
    cout << "Nilai mutlak dari " << num
         << " = " << abs(num) << endl;
    cout << "Akar dari 16 = " << sqrt(16.00) << endl;
    return 0;
}
