//Porgram loop do..while..
#include <iostream>

using namespace std;

int main()
{
    int n;
    int angka, jumlah;
    angka = 1;
    jumlah = 0;

    cout <<"N: ";
    cin  >> n;
    do
    {
        jumlah += angka;
        angka++;
    }
    while(angka < n);
    cout << jumlah;

    return 0;
}
//endl

//program loop increment for..
//menampilkan angka ascending
#include <iostream>
using namespace std;

int main(){
    int i;
    for (i=0; i<=20; i++)
        cout << i << " ";
        cout << endl;
    return 0;
}
//endl

//program loop decrement for..
//menampilkan angka descending
#include <iostream>
using namespace std;

int main(){
    int i;
    for (i=20; i>=0; i--);
        cout << i << " ";
        cout << endl;
    return 0
}
//endl

//program loop increment for..
//menampilkan pattern bintang
#include <iostream>
using namespace std;

int main(){
    int i, j;
    for (i=1; i<=5; i++){
        for (j=1; j<=i; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
//endl

//program loop decrement for..
//menampilkan pattern bintang descending

#include <iostream>
using namespace std;

int main(){
    int i,j;
    for (i=5; i>=1; i--){
        for (j=1; j<=i; j++)
        cout << "*";
        cout << endl;
    }
    return 0;
}
//endl

//PSEUDOCODE loop logical for..while..
//for (initial statement; logical expression, update expression)
    //statement
//initial expression
//while (expression)
//{
    //statement
    //update expression
//}

//program loop for..while..
#include <iostream>
using namespace std;

int main (){
    int i=0;
    while(i<10){ 
        cout << i << " ";
        i++;
        cout << endl;
    }
return 0;
}
//endl

//program loop while..
//program menampilkan bilangan kelipatan lima
#include <iostream>
using namespace std;

int main(){
    int i=0
    while (i<=20){
        cout << i << " ";
        i=i+5;
    }
    cout << endl;
    return 0;
}
//endl


//Notasi Algoritma pengulangan dgn menggunakan konstruksi FOR

//for (inisialisasi_pencacah; kondisi; penambahan_pencacah)
    //{
        //aksi
    //}