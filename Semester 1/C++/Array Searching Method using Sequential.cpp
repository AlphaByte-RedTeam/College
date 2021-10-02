//ARRAY METHOD USING
//SEQUENTIAL SEARCH

#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main (){

    int arr[10] = { 15, 12, 3, 7, 10, 6, 17, 9, 14 };
    int i = 0;
    int n;
    int x;
    int posisi = 0;

    cout << "data yang ingin dicari? ";
    cin >> x;

    while ( i < 9 && arr[i] !=x ){
        i++;
    }
    if (arr[i]!=x) {
        cout << "maaf data yang dicari tidak ada";
    }
    else if (arr[i]==x){
        posisi = i+1;
        cout << "pada posisi ke " << posisi;
    }

    //getch();

    return 0;
}