// Program Konversi Jarak 

#include <iostream>
using namespace std;

// DEKLARASI 
int main (){
    typedef struct { int km;  // Jarak Km
                     int m;   // Jarak M
                     int cm;  // Jarak Cm
    } Jarak;

    Jarak X;
    int TotalJarak;
    int Sisa;

// ALGORITMA
    cout << "Selamat Datang Di Program Konversi Jarak!" << endl;

    cout << "Masukkan jarak yang ditempuh oleh Semut dalam Centimeter! ";
    cin >> TotalJarak;

    X.km = TotalJarak / 100000;
    X.m = (TotalJarak % 100000)/100;
    X.cm = (TotalJarak % 100000)%100;

    cout << "Jadi jarak yang ditempuh oleh semut adalah " << X.km << " KM " << X.m << " M " << X.cm << " CM " << endl;

    return 0;
}

// Ini adalah kode untuk mengkonversi jarak semut dari CM ke KM, M, dan CM
// 32200091_Andrew Virya Victorio