//PROGRAM MENENTUKAN KATEGORI UMUR//

#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Input Age : ";
    cin >> age;
    
    if(age >= 0 and age <=5){
        cout << "The category is toddler";
        }
    else if(age >=6 and age <= 12){
        cout << "The category is children";
    }
    else if(age >=13 and age <= 20){
        cout << "The category is teenager";
    }
    else if(age >=21 and age <= 60){
        cout << "The category is adult";
    }
    else if(age >=61){
        cout << "The category is oldster";
    }
    return 0;
}

//Code by 32200091_Andrew Virya Victorio write in C++//


//NARASI//
    //1. Masukkan Umur
    //2. Jika rentang umur dari 0-5 tahun, maka dikategorikan sebagai balita
    //3. Jika rentang umur dari 6-12 tahun, maka dikategorikan sebagai anak-anak
    //4. Jika rentang umur dari 13-20 tahun, maka dikategorikan sebagai remaja
    //5. Jika rentang umur dari 21-60 tahun, maka dikategorikan sebagai dewasa
    //6. Jika rentang umur lebih dari 61 tahun, maka dikategorikan sebagai orang tua
    //7. Selesai//


//PSEUDOCODE//
    //umur : real
    //if (umur : real and umur : real)
    //write : maka dikategorikan sebagai balita
    //else if (umur : real and umur : real)
    //write : maka dikategorikan sebagai anak-anak
    //else if (umur : real and umur : real)
    //write : maka dikategorikan sebagai remaja
    //else if (umur :reak and umur : real)
    //write : maka dikategorikan sebagai dewasa
    //else if (umur : real)
    //write : maka dikategorikan sebagai orang tua
    //end if