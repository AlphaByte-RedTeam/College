//
//  fungsi3.cpp
//  Pert1
//
//  Created by Maya Cendana on 28/09/20.
//  Copyright © 2020 Maya Cendana. All rights reserved.
//

#include <iostream>
using namespace std;

double larger(double x, double y);
double compareThree(double x, double y, double z);

int main()
{
    double one, two;
    
    cout << "Bilangan terbesar dari 5 dan 10 = "
         << larger(5, 10) << endl;
    
    cout << "Masukkan 2 bilangan = ";
    cin >> one >> two;
    cout << endl;
    
    cout << "Bilangan terbesar dari " << one
         << " dan " << two << " = "
         << larger(one, two) << endl;
    
    cout << "Bilangan terbesar dari 3.4, 23.4, "
         << "dan 123.4 = "
         << compareThree(3.4, 23.4, 123.4)
         << endl;
    
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

double compareThree(double x, double y, double z)
{
    return larger(x, larger(y,z));
}
