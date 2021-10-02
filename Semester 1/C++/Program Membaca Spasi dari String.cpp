#include <iostream>
#include <string>

using namespace std;

int main() {
  string nama;
  
  cout << "Nama :";
  getline(cin, nama); //ngebaca spasi dari string

  cout << nama << " is name";

  return 0;
}