//SORT
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main (){

    vector< int >  values = { 5, 1, 7, 9, 10 };
    sort(values.begin(), values.end());

    for ( int value : values )
        cout << value << endl;

    return 0;
}
