//
//  voidFunction_TanpaParameter.cpp
//  Pert1
//
//  Created by Maya Cendana on 28/09/20.
//  Copyright © 2020 Maya Cendana. All rights reserved.
//
#include <iostream>
using namespace std;

void HitungLuasSegitiga();

int main()
{
    int i, N;

    //PROGRAM UTAMA;
    cout << "Banyaknya segitiga? ";
    cin  >> N;

    for(i=1; i<=N; i++)
    {
        cout << "Segitiga yang ke-"
             << i << endl;
        HitungLuasSegitiga();
    }
}

void HitungLuasSegitiga()
{
    float alas, tinggi, L;

    cout << "Panjang alas segitiga? ";
    cin  >> alas;

    cout << "Tinggi segitiga? ";
    cin  >> tinggi;

    L = (alas*tinggi)/2.0;
    cout << "Luas segitiga = " << L
         << endl << endl;
}

