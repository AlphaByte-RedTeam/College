//Converting Decimal to Binary Number

#include <iostream>
#include <cmath>
using namespace std;

long long convertDecimalToBinary(int);

int main()
{
    int n, binaryNumber;

    cout << "Enter a decimal number: ";
    cin >> n;
    binaryNumber = convertDecimalToBinary(n);
    cout << n << "(10) = " << binaryNumber << "(2)" << endl ;
    return 0;
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        cout << "Step " << step++ << ": " << n << "/2,  = " << remainder << ", Sisa = " << n/2 << endl;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}

//Converting Binary to Decimal Number

#include <iostream>
#include <cmath>

using namespace std;

int convertBinaryToDecimal(long long);

int main()
{
    long long n;

    cout << "Enter a binary number: ";
    cin >> n;
 
    cout << n << "(2) = " << convertBinaryToDecimal(n) << "(10)";
    return 0;
}

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}