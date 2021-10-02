//Terdapat variabel N untuk diinput, dan
//variabel jumlah dengan nilai awal 0,
//variabel angka nilai awalnya 1. Deret hitung
//angka terus bertambah dengan syarat mencapai maksimal
//nilai sama dengan di N. Jumlah=jumlah+angka
//Buatlah algoritma pseudocodenya dan flowchartnya dengan struktur FOR


//C++ Code//
#include <iostream>
using namespace std;

int main(){
    int n, jumlah, angka; //DECLARATION
    cout << "Input N = ";
    cin >> n;

    for(jumlah=0; jumlah<=n; jumlah++){
        for(angka=1; angka<=n; angka++){
            jumlah=jumlah+angka;
        }
        cout << jumlah << " " << endl;
    }
    return 0;
}
//CODE BY 32200091_ANDREW VIRYA VICTORIO


//PSEUDOCODE//

//MAIN PROGRAM//

//int main(){
    // n, jumlah, angka : int;
    // write N : string;
    // read N : int;

    //for(initial statement1; loop condition1; update statement1){
        //for(initial statement2; loop condition2; update statement2){
            //jumlah=jumlah+angka;
        //}
        //write jumlah : int
    //}
    //return 0;

//}

//PSEUDOCODE BY 32200091_ANDREW VIRYA VICTORIO