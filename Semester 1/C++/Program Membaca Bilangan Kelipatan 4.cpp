//Program membaca bilangan kelipatan 4//

#include <iostream>
using namespace std;

//DECLARATION//
int main(){
    int x;

    cout << "Input a number : ";
    cin >> x;

//ALGORITHM//
    if (x % 4 == 0){
        cout << x << " is a multiple of four number" << endl;
    }
    else if (x % 4 != 0){
        cout << x << " is not a multiple of four number" << endl;           
    }
    return 0;

}
//Ini adalah Contoh Code Program 32200091_Andrew Virya Victorio//



//NARASI//

//1. Masukkan angka bilangan bulat
//2. Masukkan rumus x/4
//3. Jika x/4 = 0 maka x adalah bilangan bulat kelipatan empat
//4. Jika x/4 tidak sama dengan 0 maka, X bukan bilangan bulat kelipatan empat
//5. Selesai//


//PSEUODOCODE//

    //DEKLARASI//
    //      x : integer
    
    //ALGORITMA//
    //      Read (x)
    //      if (x mod 4 = 0)
    //      write : x adalah bilangan bulat kelipatan empat
    //      else is (x mod 4 tidak sama dengan 0)
    //      write : x bukan bilangan kelipatan empat
    //      endif

