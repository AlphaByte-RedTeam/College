// PROGRAM KONVERSI ANGKA KE ROMAWI//

#include<iostream>
using namespace std;

int main()
{
    int x;
      cout<<"CONVERTING NUMBER TO ROMAN NUMBER" << endl;

    cout<<"Type a number : ";
    cin>>x;

    if (x>=3000)
        {
        cout<<"MMM";
        x=x-3000;
        }
    if (x>=2000)
        {
        cout<<"MM";
        x=x-2000;
        }
    if (x>=1000)
        {
        cout<<"M";
        x=x-1000;
        }
    if (x>=900)
        {
        cout<<"CM";
        x=x-900;
        }

    if(x>=500)
        {
        cout<<"D";
        x=x-500;
        }
    if(x>=400)
        {
        cout<<"CD";
        x=x-400;
        }
    if(x>=300)
        {
        cout<<"CCC";
        x=x-300;
        }
    if(x>=200)
        {
        cout<<"CC";
        x=x-200;
        }
    if(x>=100)
        {
        cout<<"C";
        x=x-100;
        }
    if(x>=90)
        {
        cout<<"XC";
        x=x-90;
        }
    if(x>=50)
        {
        cout<<"L";
        x=x-50;
        }
    if(x>=40)
        {
        cout<<"XL";
        x=x-40;
        }
    if(x>=30)
        {
        cout<<"XXX";
        x=x-30;
        }
    if(x>=20)
        {
        cout<<"XX";
        x=x-20;
        }
    if(x>=10)
        {
        cout<<"X";
        x=x-10;
        }
    if(x>=9)
        {
        cout<<"IX";
        x=x-9;
        }
    if(x>=8)
        {
        cout<<"V";
        x=x-8;
        }
    if(x>=7)
        {
        cout<<"V";
        x=x-7;
        }
    if(x>=6)
        {
        cout<<"V";
        x=x-6;
        }
    if(x>=5)
        {
        cout<<"V";
        x=x-5;
        }
    if(x>=4)
        {
        cout<<"IV";
        x=x-4;
        }
    if(x>=3)
        {
        cout<<"III";
        x=x-3;
        }
    if(x>=2)
        {
        cout<<"II";
        x=x-2;
        }
    if(x>=1)
        {
        cout<<"I";
        x=x-1;
        }
    return 0;
}

//Ini adalah contoh code konversi angka ke bilangan romawi by 32200091_Andrew Virya Victorio//


//NARASI//

    //1. Masukkan sebuah angka dari 1-10
    //2. Angka yang diinput oleh user dikonversi menjadi angka romawi
    //3. Stop


//PSEUDOCODE//

    //DEKLARASI//
    //var (a)
    
    //ALGORITMA//
    //read (x)
    //if (a = 1)
    //write : I
    //if (a = 2)
    //write : II
    //if (a = 3)
    //write : III
    //if (a = 4)
    //write : IV
    //if (a = 5)
    //write : V
    //if (a = 6)
    //write : VI
    //if (a = 7)
    //write : VII
    //if (a = 8)
    //write : VIII
    //if (a = 9)
    //write : IX
    //if (a = 10)
    //write : X
    //if (a = 0)
    //write : none