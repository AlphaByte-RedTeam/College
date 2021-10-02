// C++ program to create calculator using 
// switch statement 
#include <iostream> 
using namespace std; 

// Main program 
int main() 
{ 
	char (op); 
	int num1, num2; 
 
    cout << "What Operator You Want to Use? i.e +, -, *, /, %";
	cin >> op; 

    cout << "Enter First Number = ";
	cin >> num1;

    cout << "Enter Second Number = ";
    cin >> num2;

	// Switch statement begins 
	switch (op) { 
		
		// If user enter + 
		case '+': 
			cout << num1 + num2; 
			break; 
		
		// If user enter - 
		case '-': 
			cout << num1 - num2; 
			break; 
		
		// If user enter * 
		case '*': 
			cout << num1 * num2; 
			break; 
		
		// If user enter / 
		case '/': 
			cout << num1 / num2; 
			break; 
        
        // If user enter %
        case '%':
            cout << num1 % num2;
            break;
        
		// If the operator is other than +, -, *, / or %, 
		// error message will display 
	default: 
		cout << "Error! Operator is Not Correct"; 
		break; 
	} // switch statement ends 

	return 0; 
} 


//PSEUDOCODE

//CALCULATOR Program using C++

/* 
FUNCTION GetOperator()

DEKLARASI:
 

    const validOperators = {'+', '-', '*', '/', '%'}
    opIsValid : boolean
    op : char

ALGORITMA:


    opIsValid <- False
    While (NOT opIsValid) do
        Read(op)
        For (int i = 0; I < 5; i++) do
            If(validOperators[i] == op) then
                opIsValid = True
            end if
        end for
    end while

    Return op
    END FUNCTION


PROGRAM Kalkulator

{ Program menampilkan hasil hitungan dari dua buah bilangan berdasarkan operator yang diberikan user}


DEKLARASI:

op: char
num1, num2: float
result: float

ALGORITMA:

 
Read(num1)
op <- GetOperator()
Read(num2)
If(op == '+') then
result = num1 + num2
Else if (op == '-') then
result = num1 - num2
Else if (op == '*') then
result = num1 * num2
Else if (op == '/') then
result = num1 / num2
Else if (op == '%') then
result = num1 MOD num2

Write(result)
*/


/*
Pseudo-Code

PROGRAM Kalkulator

{Mengoperasikan input dari user sesuai dengan operasi yang diinginkan user}


Procedure Pertambahan:

{Menjumlahkan input dari user, hasil = (num1 + num2)}

Deklarasi :

num1,num2 : float

hasil : float

Deskripsi :

     hasil = num1 + num2

     write (hasil)

 --------------------------------------------------------

Procedure Pengurangan:

{Menngurangkan input dari user, hasil = (num1 - num2)}

Deklarasi :

num1,num2 : float

hasil : float

Deskripsi :

     hasil = num1 - num2

     write (hasil)

 --------------------------------------------------------

Procedure Perkalian:

{Menngalikan input dari user, hasil = (num1 * num2)}

Deklarasi :

num1,num2 : float

hasil : float

Deskripsi :

     hasil = num1 * num2

     write (hasil)

 --------------------------------------------------------

Procedure Pembagian:

{Membagi input dari user, hasil = (num1 / num2)}

Deklarasi :

num1,num2 : float

hasil : float

Deskripsi :

     hasil = num1 / num2

     write (hasil)

 --------------------------------------------------------

Program Utama :

{Mengoperasikan input dari user sesuai dengan operasi yang diinginkan user}


Deklarasi :

     num1, num2, :float

     op : char


Deskripsi :

     input : num1,num2 : float

            op : char {op bisa diisi dengan pertambahan, pengurangan, perkalian, pembagian}

 

     read(op)

     case(op):

     ‘pertambahan’: Pertambahan

     ‘pengurangan’: Pengurangan

     ‘Perkalian’: Perkalian

     ‘Pembagian’: Pembagian

     end case

-------------------------------------------------------------------------------------------------------------------------------------------------------
*/