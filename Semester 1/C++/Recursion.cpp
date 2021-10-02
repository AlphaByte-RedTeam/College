#include <iostream>
using namespace std;

int fpb(int num1, int num2);

int main (){
	int num1, num2;
	
	cout << "Input any two positive numbers = ";
	cin >> num1 >> num2;
	cout << "FPB dari " << num1 << " dan " << num2 << " adalah " << fpb (num1, num2);
	
	return 0;
}
int fpb(int num1, int num2){
	if (num2 != 0){
		return fpb (num2, num1 % num2);
	}
	else {
		return num1;
	}
}
