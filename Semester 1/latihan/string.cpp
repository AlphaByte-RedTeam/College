//
//  String.cpp
//  Pert1
//
//  Created by Maya Cendana on 21/09/20.
//  Copyright © 2020 Maya Cendana. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string namaDepan;
    string namaBelakang;
    int umur;
    double berat;
    cout << "Tuliskan nama depan, nama belakang, umur, "
         << "dan berat badan, dipisahkan oleh spasi: " << endl;
    cin >> namaDepan >> namaBelakang;
    cin >> umur >> berat;
    cout << "Nama: " << namaDepan << " " << namaBelakang << endl;
    cout << "Umur: " << umur << endl;
    cout << "Berat: " << berat << endl;
    
    return 0;
}
