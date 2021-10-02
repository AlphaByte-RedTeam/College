//setprecision() function berfungsi untuk membulatkan bilangan

//C++ Program using setprecision() function and example

#include <iostream>     // std::cout, std::fixed  
#include <iomanip>      // std::setprecision  
using namespace std;  
      
int main () { 

    double f =3.14159;  

    cout << setprecision(5) << f << '\n';  
    cout << setprecision(9) << f << '\n';  
    cout << fixed;  
    cout << setprecision(5) << f << '\n';  
    cout << setprecision(9) << f << '\n';  

      return 0;  
} 

/* Contoh Output :

3.1416
3.14159
3.14159
3.141590000 */