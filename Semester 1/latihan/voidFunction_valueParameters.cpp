//
//  voidFunction_valueParameters.cpp
//  Pert1
//
//  Created by Maya Cendana on 28/09/20.
//  Copyright © 2020 Maya Cendana. All rights reserved.
//

#include <iostream>
using namespace std;

void HitungLuasSegitiga(float a, float t);

//ALGORITMA
int main()
{
    int i, N;
    float a, t;

    //PROGRAM UTAMA;
    cout << "Banyaknya segitiga? ";
    cin  >> N;

    for(i=1; i<=N; i++)
    {
        cout << "Segitiga yang ke- " << i << endl;
        cout << "Panjang alas segitiga? ";
        cin  >> a;

        cout << "Tinggi segitiga? ";
        cin  >> t;

        HitungLuasSegitiga(a, t);
    }
}

void HitungLuasSegitiga(float alas, float tinggi)
{
    float L;
    L = (alas*tinggi)/2.0;
    cout << "Luas segitiga = " << L << endl;
}


