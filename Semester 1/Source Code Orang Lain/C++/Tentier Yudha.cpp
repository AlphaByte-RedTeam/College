#include <iostream>
#include <windows.h>
using namespace std;

int dat[10] = {21, 5, 7, 4, -4, -9, 16, 8, 9, 30};
int tmp[10] = {24, 1, 3, 9, 10, -1, 3, 0, 5, 50};
int length = 10;

void show(int * arr) {
	for (int i = 0; i < length; i++) {
   	cout << arr[i] << " ";
   }
}

int add(int a, int b) {
	return (a + b);
}

void addArray(int * arr, int * arr2) {
 	for (int i = 0; i < length; i++ ) {
		cout << add(arr[i], arr2[i]) << " ";
   }
}

int greaterThan(int a, int b) {
	if (a > b) {
		return a;
   }
   return b;
}

void maxArray(int * arr, int * arr2) {
	for (int i = 0; i < length; i++ ) {
		cout << greaterThan(arr[i], arr2[i]) << " ";
   }
}

int total(int * arr) {
	int n =0;

   for (int i = 0; i < length; i++ ) {
		n = n + arr[i];
   }

   return n;
}
main() {
	do {
		int input = 0;
		cout << "Menu\n";
	   cout << "1. Tampikan array dat\n";
		cout << "2. Tampikan array tmp\n";
	   cout << "3. jumlahkan dat dengan tmp\n";
	   cout << "4. terbesar antara dat dan tmp\n";
  		cout << "5. total dat\n";
   	cout << "6. total tmp\n";
	   cout << "7. keluar\n";
   	cout << "Input : ";
		cin >> input;

	   switch(input) {
	   	case 1:
   	   	show(dat);
	      break;
	      case 2:
      		show(tmp);
      	break;
         case 3:
      		addArray(dat, tmp);
      	break;
         case 4:
      		maxArray(dat, tmp);
      	break;
         case 5:
      		cout << total(dat);
      	break;
         case 6:
      		cout << total(tmp);
      	break;
         default:
				exit(0);
   	}
      cout << '\n';
      system("pause");
      system("cls");
   }	while(true);
}