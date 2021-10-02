#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void swap ( int &a, int &b ){

    int temp = a;
    a = b;
    b = temp;
}

bool ascending ( int a, int b ){
    return a > b;
}

bool descending ( int a, int b ){
    return a < b;
}

void fillArray ( vector<int> &arr){
    int size;
    cout << "How much size of array : ";
    cin >> size;

    arr.resize ( size );

    for ( int i = 0; i < arr.size(); i++ ){
        cout << "#" << i << " Input : ";
        cin >> arr[i];
    }
}

void print ( const vector<int>& arr){
    for ( int i = 0; i < arr.size(); i++ ){
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

void sort ( vector <int> &arr, function<bool(int a, int b)> order = ascending ){
    for ( int i = 0; i < arr.size(); i++ ){
        bool isSorted = true;
        for ( int j = 0; j < (arr.size() - 1); j++ ){
            if ( order(arr[j], arr[j + 1]) ){
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if ( isSorted ){
            break;
        }
    }
}

int main (){

    vector<int> arr;
    fillArray(arr);

    system("cls");
    //before sort
    cout << "Before sort : \n";
    print(arr);

    sort(arr);
    
    //after sort
    cout << "After sort ascending : \n";
    print(arr);

    sort(arr, ascending);

    return 0;
}