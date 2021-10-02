#include <iostream>
using namespace std;

double larger(double num1, double num2);

int main()
{
    double num1 = 13.00;
    double num2 = 36.53;
    
    cout << "Nilai terbesar antara 23.50 dan 37.80 = "
    << larger(23.50, 37.80) << endl;
    
    cout << "Nilai terbesar antara " << num1 << " dan "
    << num2 << " = " << larger(num1, num2) << endl;
    
    cout << "Nilai terbesar antara 34.50 dan "
         << num1 << " = " << larger(34.50, num1) << endl;
    
    return 0;
}

double larger(double x, double y)
{
    double max;
    
    if(x >= y)
        max = x;
    else
        max = y;
    
    return max;
}
