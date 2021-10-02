//*****************************************************************
//  © ANDREW VIRYA VICTORIO 2020/10/10  13:18
//  NIM: 32200091
//  TEKNIK INFORMATIKA A.T 2020: 1PTI1: PEMROGRAMAN DASAR (TIB21)
//  RABU -- 8 SKS
//  LATIHAN: MENJUMLAHKAN DUA BUAH MATRIX YANG TERDIRI DARI FUNGSI
//           UNTUK MENGINPUT MATRIX, FUNGSI UNTUK MENJUMLAHKAN MAT-
//           RIX DAN FUNGSI UNTUK MENCETAK MATRIX. (FORUM 21 Okt)
//  DOSEN: CHYQUITHA DANUPUTRI, S.KOM, M.KOM
//*****************************************************************

#include <iostream>
#include <conio.h>
using namespace std;

/*
    *   MEMBUAT ARRAY
    *   MENGISI ANGKA DI DALAM MATRIX
    *   MELAKUKAN PENJUMLAHAN
    *   MENAMPILKAN HASIL PENJUMLAHAN
*/

//DECLARATION
const int row = 3;
const int col = 3;

typedef int column[3];
typedef column Matrix[3];


// FUNCTION FOR INPUTTING MATRIX

void inputMatrix (Matrix matrix, string label) {
	
	cout << "\nInput Matrix = " << label << "\n";
	
	for (int i = 0; i < row; i++) {
		for (int j=0; j < col; j++) {
			cout << "A[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
}


// FUNCTION FOR MATRIX ADDITION

void sumMatrix (Matrix matrixA, Matrix matrixB, Matrix result) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
}


// FUNCTION FOR DISPLAYING MATRIX

void displayMatrix (Matrix matrix, string label) {

	cout << "\nMatrix " << label << '\n';
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << '\n';
	}
}

int main() {

    //HEADER PEMANIS
    cout << "=============================" << '\n';
	cout << "Program Penjumlahan Matriks!! \n";
	cout << "=============================" << '\n';
 
	Matrix matrixA;
	Matrix matrixB;
	
	inputMatrix (matrixA, "A");
	inputMatrix (matrixB, "B");
	
	displayMatrix (matrixA, "A");
	displayMatrix (matrixB, "B");

	Matrix result;
	
	sumMatrix (matrixA, matrixB, result);
	
	displayMatrix (result, "Hasil");
	
	getch();
	
	return 0;
}