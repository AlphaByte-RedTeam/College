/*Perhatikan algoritma sbb

Function Fak(input N : integer) → integer

{mengembalikan nilai N!. jika N = 0, maka 0!=1

 

coba : jika N>0, maka N! = N x (N-1)!}

Deklarasi

{tidak ada}

 

Deskripsi

If N = 0 then

 Return 1 {basis}

Else

 Return N*Fak(N-1) {coba}

Endif

 

Algoritma faktorial

{program utama yang memanggil fungsi faktorial}

Deklarasi

Bil : integer

Function Fak(input Bil : integer) → integer

{mengembalikan nilai N!}

Deskripsi

Read(Bil)

Write(Bil, ‘ ! adalah :’,Fak(Bil))


Merupakan metode apakah di atas?

Buatkan programnya
*/

//RECURSION PROGRAM
#include <iostream>
using namespace std;

int fak (int n){
    if (n==0){
        return 1;
    }
    else {
        return n*fak (n-1);
    }
}

int main (){

    int x;

    cout << "SELAMAT DATANG DI PROGRAM FAKTORIAL\n";
    cout << "===================================\n";
    cout << "          Masukkan angka : ";
    cin >> x;
    cout << x << "! = " << fak(x);
}

/* PROGRAM REKURSI KARENA SI FUNGSI FAK MEMANGGIL
   DIRINYA SENDIRI YANG BERADA DI DALAM MAIN PROGRAM */

/*PROGRAM HANYA DAPAT MENGELUARKAN HASIL MAXIMUM DI ANGKA
  33 FAKTORIAL DIKARENAKAN KETERBATASAN SYNTAX, KALAU SUDAH
  MASUK KE 34 FAKTORIAL, ANGKANYA SANGAT PANJANG DAN HARUS
  MENGGUNAKAN LONG LONG SYNTAX, TETAPI KARENA DISINI PSEUDOCODE
  NYA MENGGUNAKAN SYNTAX INTEGER, MAKA ANGKA MAX YANG BISA DI
  INPUT SAMPAI DENGAN 33 FAKTORIAL. */