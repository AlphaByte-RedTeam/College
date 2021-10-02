//HANOI TOWER PROGRAM
//RECURSION

#include <iostream>
using namespace std;

void tower (int , char , char , char );

int main (){
    
    int n;
    cout << "Input disk : ";
    cin >> n;
    tower (n, 'A', 'C', 'B');

    return 0;
}

void tower (int x, char a, char c, char b){
    if (x > 0){
        tower (x-1, a, b, c);
        cout << "Move disk " << x << " from " << a << " to " << c << endl;
        tower (x-1, b, c, a);
    }
}

/*

PROCEDURE :
recursion (int, char, char, char)
{void recursion untuk menara}

DECLARATION :
n : int

MAIN PROGRAM :
write : string text {Masukkan banyaknya Disk : }
read : n : int {membaca nilai N}
menara (n, A, C, B) {memanggil Fungsi}
END

CALLING PROGRAM :
menara (x : int, a : char, c : char, b : char)
if (x > 0){
    menara (x-1, a, b, c)
    write : string {Pindahkan disk (x) dari A ke C}
    menara (x-1, b, c, a)
}
END

*/