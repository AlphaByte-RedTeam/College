#include <iostream>

using namespace std;

int main(){
  int array[100], i, n;
  float rata, total=0;

  cout << "===============================================" << endl;
  cout << "Program Menghitung Nilai Rata-rata dengan Array" << endl;
  cout << "===============================================" << endl;
  cout << "Masukkan banyaknya data : ";
  cin >> n;

  for(i=0; i<n; i++){
    cout << "Nilai Ke-" << i+1 << " : ";
    cin >> array[i];
    total = total + array[i];
  }

  rata = total/n;
  cout << "Hasil nilai total adalah : " << total << endl;
  cout << "Hasil rata-rata adalah : " << rata << endl;

  return 0;

}

//PSEUDOCODE

/*PROCEDURE
{Mencari rata-rata nilai dari jumlah total data nilai}*/
//{masukkan banyak data}
//{hitung nilai dari setiap jumlah data sebagai nilai total}
//{lalu menghitung nilai rata-rata dari nilai total}

/*
//DECLARATION :
    array : integer
    i, n  : integer
    rata  : float
    total : integer

//DESCRIPTION
    write : string (Program menghitung nilai rata-rata dengan Array)
    write : string (masukkan banyaknya data : )
    read  : variable n


//MAIN PROGRAM
    for(initial statement; loop condition; upadete statement)
    write : string (Nilai ke : ) ; i+1
    read  : array[i]
    total=total + array[i]

    rata=total/n

    write : string (Hasil nilai total adalah)
    write : string (Hasil rata-rata adalah)

    end case

//By 32200091_Andrew Virya Victorio