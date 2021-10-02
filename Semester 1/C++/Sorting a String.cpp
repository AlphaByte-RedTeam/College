#include <iostream>
#include <string>
using namespace std;

int main (){

    string str;
    
    cout << "Enter String To Be Sorted : ";
    getline (cin, str);

    int len = str.length();
    cout << "\n String before get sorted : " << str << "\n";

    //using bubble sort to sort the characters in the string
    for ( int i  = 0; i < len; i++ ){
        for ( int j = 0; j < len; j++ ){
            if (str[i] > str[j]){

                //swapping the prev and next characters
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << "\n String after get sorted : " << str << "\n";

    return 0;
}