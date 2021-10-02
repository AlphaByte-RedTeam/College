//RECURSION PROGRAM
//FPB

#include <iostream>
using namespace std;

int fpb(int num1, int num2);

int main (){
    int num1, num2;

    cout << "Input first positive number = ";
    cin >> num1;

    cout << "Input second positive number = ";
    cin >> num2;

    cout << "FPB dari " << num1 << " dan " << num2 << " adalah " << fpb (num1, num2);

    return 0;
}

int fpb(int num1, int num2){
    if (num2 != 0){
        return fpb (num2, num1 % num2);
    }
    else{
        return num1;
    }
}

//PSEUDOCODE//
/*RECURSION PROGRAM FPB
  
  FUNCTION for FPB
  fpb : int (num1 : int, num2 : int)

  MAIN PROGRAM
  main : int
    num1 : int, num2 : int

    write : string (Input First Positive number)
    read : int (num1)

    write : string (Input second positive number)
    read : int (num2)

    write : FPB dari (input num1) dan (input num2) adalah (hasil)
    return to 0

    fpb : int (num1 : int, num2 : int)

    if num2 != 0
    return to fpb (num2, num1 / num2)

    else
    return num1

    By 32200091_Andrew Virya Victorio

*/

//ITERATIVE PROGRAM
//FPB

#include <iostream>
using namespace std;

int fpb(int num1, int num2){
    while (num1 != num2){
        if (num1 > num2)
            num1 = num1-num2;
        else 
            num2 = num2-num1;
    }
    return num1;
}

int main(){

    int num1, num2;

    cout << "Input first number = ";
    cin >> num1;

    cout << "Input second number = ";
    cin >> num2;

    cout << "FPB dari " << num1 << " dan " << num2 << " adalah = " << fpb (num1, num2);
}

//PSEUDOCODE
/*ITERATIVE PROGRAM FOR FPB
  fpb : int (num1 : int, num2 : int)
  while (num1 != num2)
  if (num1 > num2)
  num1 = num1-num2
  else
  num2 = num2 - num1
  return to num1

  main : int
  num1 : int, num2 : int
  write : string (input first number)
  read : num 1 : int
  write : string (input second number)
  read : num2 : int

  By 32200091_Andrew Virya Victorio
*/

/*Rekursif adalah fungsi yang memanggil dirinya sendiri
  menggunakan pernyataan pilihan perulangan (if, if..else, switch)
  melalui pemanggilan fungsi berulang. Program stop jika pada kondisi
  dasarnya terpenuhi*/

/*Iterasi adalah proses pengulangan dengan menggunakan
  perintah perulangan (for, while, do..while) secara ekspisit
  Program stop jika kondisi looping bernilai salah*/