// Program Mencari Bilangan Bulat Terbesar

#include <iostream>
using namespace std;

int main(){
    int A, B;
    
    cout << "Input first number here = ";
    cin >> A;
    cout << endl;

    cout << "Input second number here = ";
    cin >> B;
    cout << endl;

    if (A > B){
        cout << "The biggest number is = " << A;
    }
    else {
        cout << "The biggest number is = " << B;
    }

    return 0;
}