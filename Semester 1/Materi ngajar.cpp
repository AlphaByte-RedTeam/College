//MATERI NGAJAR
/*
* : asterisk                    --> digunakan untuk pointer atau sebagai tanda kali
/ : slash
+ : plus
= : equal
! : negation mark               --> tanda negasi/complement yang mana artinya kebalikannya
< : less than                   --> digunakan sebagai operator lebih kecil dari di if
> : greater than                --> digunakan sebagai operator lebih besar dari di if
'' : single quoatation mark     --> biasa buat tipe data char
" " : double quoatation mark    --> biasa buat tipe data string
& : ampersand                   --> digunakan untuk reference pointer
# : hash                        --> untuk meng-include header file
. : dot                         --> di dalam programming, (.) digunakan sebagai tanda koma
; : semicolon                   --> untuk mengakhiri setiap baris code
() : parenthesis/normal bracket
{} : curly bracket
[] : square bracket
, : comma
*/

//EXPONENT FUNCTION

#include <iostream>
using namespace std;

int exponentFunction ( int baseNum, int powerNum ){ //isi parameter

    int result = 1; //result harus 1

    for ( int i = 0; i < powerNum; i++ ){
       
        result *= baseNum;
    }

    return result;
}

void print (){

  cout << exponentFunction( 9, 4 ); //menampilkan fungsi exponent
}

int main (){

    print();
    
    return 0;
}


//LIAT BEBERAPA PPT UBM

1. Fundamental Programming:

- cara menulis kode yang baik & benar:
	~ menulis kode yang cepat
	~ menulis kode yang baik
	~ indentation

- membuat suatu program:
	~ menuliskan terlebih dahulu narasinya terlebih dahulu
	~ berfikir logic
  ~ breakdown satu per satu langkah atau flownya
  ~ gambarkan hasil output yang diinginkan

2. Basic Programming:

- Variable
- Data Types
- syntax
- modular programming
- loop
- algorithm
- if statement --> next vidcon
- switch case
- bedanya sama if statement & switch case??
- array 1D, 2D, Multidimensional

C++ adalah the next level of C programming language.
C++ is a great language to learn.


//MATERI ARRAY 1D, 2D, and MULTIDIMENSIONAL ARRAYS
/*
#include <iostream>
using namespace std;

int main (){

    int arrOneDim[] = { 1, 5, 9, 2, 0, 32 };

    int arrTwoDim[??][??] = {
                            { 4, 2, 1, 7, 9 },
                            { 8, 3, 24, 5, 9 }
                        };

    //ACCESSING ARRAYS
    cout << arrOneDim[2] << endl << endl; //menampilkan 1 nilai array

    for ( int i = 0; i < 6; i++ ){
        cout << arrOneDim[i] << endl;
    }

    return 0;
}
*/
//TANYA: Berapa nilai array?

/*
//MATERI LOOP
#include <iostream>
using namespace std;

int main() {

int a;

cout << "Flavor Text Goes Here (taking input a) : ";
cin >> a;

int i = 0;  //INISIALISASI i = 0
while ( i < 3 ) //penggunaan while loop i < 3
{
    cout << i*a << endl;    //penampilan output 
                            //i*a berarti jika i = 0, dan a = 3, maka 0x3
    i++;        //lalu yang tadinya i = 0, loop condition increment sebanyak 1x, maka i menjadi 1x
                //artinya i * a = 1 * 3
}

cout << "SELESAI";

return 0;
}

/*
ALGORITMA

//MAIN PROGRAM

    deklarasi
    a : integer

    print(Flavor Text Goes Here (taking input a) : )
    read : a

    WHILE LOOP

        deklarasi
        i : integer --> in this case, i = 0
                    ^~ dari atas situ gk usah ditulis
        while i < 3
            print i * a
            i++
        END

        print(SELESAI)

Penulisan code yg rapih

Tips & trick writing faster code

0 & Null

Looping (while, for, do..while)
*Penulisan loop yg bgs

Function with parameter & passing

Array & accessing & printing
*/

arr[/baris/][/kolom/] = {
              {3, 6}, //baris1
              {8, 8} //baris2
            /*k   k
              o   o
              l   l
              o   o
              m   m
              1   2
            */
  
};

//kasus diatas pake 2 baris 2 kolom
//gimana kalo pake 2 baris 5 kolom??


arr[2][5] = {
              {2, 9, 4, 8, 100},
              {9, 3, 5, 200, 3}
  
};

//diatas adalah penggunaan array 2D dgn 2 baris 5 kolom


//akses array
//karna ini array 2D, so harus pake 2x For Loops
for (int i = 0; i < 2; i++){ //loop 1 bwt akses array baris
  for (int j = 0; j < 5; j++){//loop 2 bwt akses array kolom
    cout << "Element di X[" << i << "][" << j << "] is :";
    cout << x[i][j] << endl;
  }
}
//cara diatas bertujuan untuk menampilkan
//keseluruhan data yang ada di dalam array
//menggunakan FOR loops


//syntax FOR loop : 
for (int i = 0; i < /angka di array baris/; i++){
  for (int i = 0; i < /angka di array kolom/; i++){
    //code yang akan dieksekusi
  }
}

//kenapa untuk mengakses array pada saat looping
//selalu menggunakan i = 0??

//basically i, j, or whatever, terserah, yg penting
//gampang diingat, jangan sampe ngecohin diri sendiri

// = 0 itu karena array menggunakan index basis 0

//jadi, setiap array, dimulai dari penyebutan
//0, 1, 2, 3, .... n

//yg mana artinya, ketika mau mengakses menggunakan index
//data X dengan index sekian, element sekian

//cth :
  
/*
  arr[5] 
  
  disini ada 5 kolom array
  
  dalam index    0, 1, 2, 3, 4
  dalam element  1, 2, 3, 4, 5  
  
  
    
  contoh ada data:
          {13, 7, 8, 6, 20}
    index  0,  1, 2, 3,  4
  element  1,  2, 3, 4,  5
  
  utk mengakses data angka 8
  berarti ngomongnya :
  
  index ke 2
  element ke 3
*/  
  
// kalo ada code seperti ini
  
  int arr[3][5] = {
                    {3, 7, 64, 69, 77},
                    {6, 88, 23, 13, 44},
                    {4, 8, 21, 29, 65}
  };
  


for (int i = 0; i < 3; i++){
  for (int j = 0; i < 5; i++){
    cout << "Element di X[" << i << "][" << j << "] is :";
    cout << x[i][j] << endl;
  }
}

// ^^~~cara diatas merupakan cara untuk menampilkan
//       seluruh element array


//gimana cara akses angka 23 doang, gw gmw yg lain

//simple aj code ny

cout << arr[1][2];

//akses angka 6 gimana?

cout << arr[1][0];

//akses angka 65 gimana?

cout << arr[2][4];




//NB : tolong coba perhatiin dari syntax
//     semi-colon, commas, sign, semua hal
//     detail lainnya diperhatiin.


//FYI : Belajar Array tanpa belajar Pointer is uselesss


Yang ada tanda garis miring dua (//) itu comment
*> ini untuk single line comment

Yang ada tanda (/* (text) */) itu juga comment
*> ini untuk multi line comment

//MATERI POINTER
#include <iostream>
using namespace std;

int main (){

    int age = 19;
    double gpa = 4.0;
    string name = "Andrew";

    cout << &gpa << endl;
}

/* C/C++ Basic

   Di pemrograman C/C++, ada banyak sekali
   dasar-dasarnya. Let's start with header
   file!
*/

#include <iostream>
#include <string>
#include <conio.h>
//#include <....> --> Dan lainnya
using namespace std;

/*
  
  Di C/C++, pada saat memulai
  menuliskan program, selalu
  diawali dengan menuliskan
  header file (file dengan
  extension .h). File tersebut
  berisikan deklarasi (konstanta,
  fungsi, kelas, namespace, DSB).
  
  File ini tidak berisi implementasi
  atau code program dari fungsi/kelas
  yang didefinisikan di dalamnya. Bagian
  implementasi biasanya disimpan dalam
  bentuk Object Code, yaitu file yang
  sudah dikompilasi sebelumnya. File
  ini biasa disebut "Standard Runtime
  Library", File ini akan dipanggil
  secara otomatis pada tahap linking.
 
*/
  
  

//C++ Bersifat Case Sensitive
/*
  Artinya penulisan huruf besar
  dan huruf kecil sangat sensitive.
  Perhatikan penulisan code!!
*/
  
  
  
/*
//FUNCTION OR PROTOTYPE (void)

dataType varFunctionName (parameter1, parameter2, ...){
  
  //code to be executed
}

Tips menuliskan function atau prototype :
  
1. Jangan sembarangan menulis variable
   dengan sembarang nama yang jelas,
   seperti a, x, b, dan lainnya.
   Penulisan variable harus jelas
   dan memiliki tujuan penulisan.
   
   Contoh yang baik:
     void print () --> procedure
                       untuk
                       print
                       
   Contoh yang tidak baik:
     void p () --> apa maksudnya??
   
2. Berhati-hati terhadap penggunaan
   data type, karena jika salah memilih,
   bisa mengacaukan seluruh code yang ada.
  
  
*/

//FUNCTION Arithmetic Operation
int arithOp (int a, int b){
  
  int sum;
  
  sum = a + b;
  
  return sum;
  
}

//MAIN PROGRAM
int main (){
  
  //code to be executed
  cout << arithOp(8, 10);
  
  return 0;  /*--> jangan pernah lupa
                   untuk menuliskan
                   return 0; di C/C++ */
}

//OUTPUT: 18

/*
  
  RETURN 0;
  nilai 0 pada return 0; berfungsi untuk
  mengembalikan nilai ke sistem operasi,
  dan menyatakan bahwa program dieksekusi
  dan dihentikan secara normal (sampai
  perintah terakhir). Jika program di-
  hentikan secara paksa (tidak normal),
  nilai yang akan dikembalikan ke sistem
  operasi adalah nilai selain 0 (biasanya
  menggunakan nilai 1).
  
*/
// 07/11/2020 ~ 21:40
// ======================================================
  
   NEW!!
// ======================================================

/*
  MODULAR PROGRAMMING:
    Modular programming adalah metode 
    pemrograman terpisah. Maksud dari 
    pemrograman terpisah adalah, fungsi
    main dengan fungsi lainnya dibuat
    secara terpisah.
    
    Contoh: Fungsi main dengan fungsi gaji
            dibuat secara terpisah, dan
            contoh lainnya.
      
  Modular Programming terbagi menjadi 2:
    - Function : fungsi yang mengembalikan
                 nilai
    
    - Procedure : yaitu fungsi yang tidak
                  mengembalikan nilai (void)
                  
                  
                  
  Ada 2 tipe function, yaitu:
    - Function dengan parameter
    - Function tanpa Parameter
    
  Kegunaan dari Modular Programming
  yaitu menghindari duplikasi code.
  Bayangkan kalau ada code yang di-
  gunakan untuk membuat fungsi
  perkalian, dan kalian copy paste
  code kalian tanpa merubah variable
  nya, apa yang terjadi? Bisa terjadi
  error ataupun bug. Ini adalah
  kesalahan yang biasa dilakukan oleh
  programmer, baik newbie maupun yang
  sudah pro.
  
  Keuntungan lainnya yaitu memudahkan
  programmer untuk maintain. Bayangkan,
  kalau ada fungsi perkalian sebanyak
  10 buah fungsi yang sama, kalian pasti
  akan kerepotan me-maintain. Atau jika
  kalian mau merubah beberapa codenya,
  kalian harus merubah seluruh codenya.
  
  Kalau kalian membuat function, kalian
  bisa lebih mudah untuk mengcontrol
  code kalian. Kalian cukup merubah
  beberapa kali saja. Dan tampilan code
  kalian akan menjadi lebih rapih.
  
  Tapi perlu diingat, bukan membuat
  semua code kalian dijadikan fungsi.
  Itu dapat memperlambat kecepatan dari
  program kalian dikarenakan pada saat
  pemanggilan fungsi, compiler menghasilkan
  instruksi pemanggilan. 
  
  //boleh cari lebih detail terkait
    kenapa pemanggilan function bisa
    memperlambat program.
  
*/

//ALGORITHM OF MAKING A FUNCTION

data_Type functionName ( data_Type1 parameters1, ...n )
{
  //code to be executed
}

//ALGORITHM OF CALLING A FUNCTION

int main ()
{
  functionName ( argument1, ....n )
  
  return 0:
}
  
//DIATAS ADALAH ALGORITMA SUATU FUNCTION

//PENJELASAN:
  /*
    parameter yang ada di dalam fungsi
    merupakan FORMAL PARAMETER. Sedangkan
    parameter yang ada di dalam sebuah
    main program disebut ACTUAL PARAMETER.
    
    parameter yang di dalam sebuah fungsi
    di passing ke dalam main program.
  */
     
    // CONTOH ALUR FUNCTION:
    
    int perkalian ( int a, int b ) ---------------
    {                                            |
      return a*b;    --> fungsi perkalian        |
                         dikembalikan dengan     |
                         nilai integer lagi.     |
    }                                            |
                                                 |      
    void kaliDanPrint ( int a, int b ) ----------|
    {                                            |
      int hasil = perkalian ( a, b ); <----------|
      cout << hasil << endl;          ^(passing  |
    }                                   value)   |
                                                 |
    int main ()                                  |
    {                                            |
      kaliDanPrint ( 4, 9 );   <-----------------|
      kaliDanPrint ( 5, 83 );  <-----------------|
      kaliDanPrint ( 77, 77 ); <-----------------|
                               ^(passing value)
      return 0;
    }
    
    //OUTPUT:
      
      36
      415
      5929
  
  /*
    void kaliDanPrint ( int a, int b )
    
                        ^parameter yang
                         ada diatas
                         merupakan para-
                         meter formal.
    
    int main ()
    {
      kaliDanPrint ( 5, 83 );
      ^              ^actual
      ^               parameter
      ^function calling
      
      return 0;
    }
    
    
    nilai yang berada di dalam actual parameter
    diproses dengan menggunakan fungsi yang sudah
    dibuat tadi.
    
    penulisan fungsi harus selalu diatas main program
    
    jika penulisan fungsi ada dibawah main program,
    maka function tersebut dinamakan PROTOTYPE FUNCTION
  */
    
    //SEKILAS TENTANG PROTOTYPE FUNCTION:
    //------------------------------------
      
      //FUNCTION PROTOTYPE
      int tambah ( int, int );
      
      int main ()
      {
        int sum;
        
        //pemanggilan fungsi
        sum = tambah ( 9, 8 );
        cout << "9 + 8 = " << sum << endl;
        
        return 0;
      }
      
      //FUNCTION DEFINITION
      int tambah ( int a, int b )
      {
        return a+b;
      }
// 09/11/2020 ~ 21:48
// ======================================================
#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    int day = 4;
    
    switch (day){
      
      case 1:
        cout << "Senin";
        break;
        
      case 2:
        cout << "Selasa";
        break;
      
      case 3:
        cout << "Rabu";
        break;
      
      default:
        cout << "tod";
        break;
    }
}


/*
  Syntax Switch:
  
  
  switch (variable){
    
    case x:
      //code to be executed
      break;
    
    case y:
      //code to be executed
      break;
      
    default:
      //code to be executed
      break;
  }
*/
  
/*
  functional switch yaitu untuk :
    
    1. mempersingkat if
    2. mempermudah dalam pembacaan
    3. efisiensi
  
  
  
  *tetapi tidak semua bisa menggunakan
   switch case.
*/
  
switch (true) {
    case $object->student === null:
        // do stuff
        break;
    case  $object->student->name === 'Brian':
        // do other stuff
        break;
    // ...
}

/*
Well, switch feels "lighter" in many cases than 
an if/else if ladder, in my opinion. Basically 
you don't have that much syntax with braces and 
parentheses in the way of your code. That being
zaid, switch inherits C's syntax. That means you 
have break and only a single scope for variables 
unless you introduce new blocks.

Still, the compiler is able to optimize switch 
statements into a lookup table and perform 
compile-time checking for literals when dealing
with enumerations. So, I'd suggest that it's 
usually preferable to use switch over if/else 
if if you're dealing with numeric or enum types.
*/