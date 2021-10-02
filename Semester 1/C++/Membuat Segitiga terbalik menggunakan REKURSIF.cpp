//RECURSION PROGRAM
//MEMBUAT SEGITIGA TERBALIK *

#include <iostream>
using namespace std;

void triangleRecursion (int baris1, int baris2);

int main (){ //MAIN PROGRAM

    int baris1; //DECLARING baris1

    cout << "Masukkan banyak baris : ";
    cin >> baris1;

    int baris2 = 1;
    triangleRecursion(baris1, baris2); //calling function
    
    return 0;
}

//RECURSION
void triangleRecursion (int baris1, int baris2){
    int i;
    for (i=0; i<(baris1 * 2)-1; i++){
        cout << "*";
    }
    if (baris1 != 0){
        cout << "\n";
        for (i=0; i<baris2; i++){
            cout << " ";
        }
        triangleRecursion (baris1 - 1, baris2 + 1);
    }
}