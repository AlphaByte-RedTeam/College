/*PROGRAM MENGHITUNG LUAS
SEGITIGA MENGGUNAKAN LOOPING*/

//32200091_Andrew Virya Victorio

#include<iostream>
using namespace std;

void luasSegitiga(){  //Deklarasi Procedure//
    float a,t,luas;

    cout << "Masukkan nilai alas segitiga = ";
    cin >> a;

    cout << "Masukkan nilai tinggi segitiga = ";   //--> Body of the Function//
    cin >> t;
    cout << "\n";

    luas = 0.5*a*t; 

    cout << "Luas segitiga adalah " << luas << "\n";
}

int main(){ //MAIN PROGRAM//
    
    int jumlah;

    cout << "Selamat datang di program penghitung luas segitiga!\n";
    cout << "=================================================== \n";
    cout << "Berapa banyak luas segitiga yang ingin dihitung? ";
    cin >> jumlah;

    for(int i = 1; i <= jumlah; i++){
        cout << "Perhitungan luas segitiga ke " << i << "\n \n";
        luasSegitiga();   //Calling the Function//
        cout << "================================== \n";
    }
    cout << "Perhitungan selesai!\n";
    
    return 0;
}