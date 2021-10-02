//
//  fungsiNilaiTengah.cpp
//  Pert1
//
//  Created by Maya Cendana on 28/09/20.
//  Copyright © 2020 Maya Cendana. All rights reserved.
//

#include<iostream>
using namespace std;

//DEKLARASI GLOBAL
typedef struct{
    float x;
    float y;
} Titik;

Titik TitikTengah(Titik P1, Titik P2);

int main()
{
    //menerima input dari user
    Titik P1, P2;
    Titik Pt;

    cout << "Titik P1: " << endl;
    cout << "X = ";
    cin  >> P1.x;
    cout << "Y = ";
    cin  >> P1.y;

    cout << "Titik P2: " << endl;
    cout << "X = ";
    cin  >> P2.x;
    cout << "Y = ";
    cin  >> P2.y;

    Pt = TitikTengah(P1,P2);
    //P1 dan P2: parameter aktual

    cout << "Titik tengah: "
         << "(" << Pt.x << "," << Pt.y << ")"
         << endl;
}

Titik TitikTengah(Titik P1, Titik P2)
//P1 dan P2: parameter formal
{
    Titik Pt;
    //mengembalikan nilai berupa hasil titik tengah
    Pt.x = (P1.x + P2.x)/2;
    Pt.y = (P1.y + P2.y)/2;
    return Pt;
}
