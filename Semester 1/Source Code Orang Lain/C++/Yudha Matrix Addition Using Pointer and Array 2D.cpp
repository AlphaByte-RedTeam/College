#include <iostream>
#include <conio.h>

using namespace std;

/*
 * Fungsi untuk membuat array
 * keyword new digunakan untuk melakukan alokasi memory secara dinamis pada saat run time
 *
 * parameter:
 * row:int - jumlah baris matrix yang mau dibuat
 * col:int - jumlah kolom matrix yang mau dibuat
*/
int ** constructMatrix(int row, int col) {
	//buat variabel untuk menampung data matrix 2 dimensi
	int ** matrix;	
	
	//alokasikan memory untuk membuat array dimensi pertama
	matrix = new int*[row];
	
	//lakukan looping terhadap semua elemen array
	for (int i=0; i<col; i++)
		//alokasikan memory untuk membuat array di dalam array
		matrix[i] = new int[col];
		
	//keluarkan array yang telah di buat
	return matrix;
}

/*
 * Fungsi untuk mengisi matrix
 *
 * parameter:
 * matrix: **int - matrix yang mau di input
 * row:int - jumlah baris matrix yang mau dibuat
 * col:int - jumlah kolom matrix yang mau dibuat
*/
void fillMatrix(int **matrix, int row, int col, string label) {
	//output heading
	cout << "\nInput matrix " << label << "\n";
	
	//lakukan loop terhadap baris
	for (int i=0; i<row; i++) {
		//lakukan loop terhadap kolom
		for (int j=0; j<col; j++) {
			//isi nilai elemen matriks pada baris ke i dan kolom ke j
			cout << "A[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
}

/*
 * Fungsi untuk menjumlahkan matrix
 *
 * parameter:
 * matrixA: **int - Matrix pertama
 * matrixA: **int - Matrix kedua
 * row:int - jumlah baris matrix yang mau dibuat
 * col:int - jumlah kolom matrix yang mau dibuat
*/
int ** addMatrix(int ** matrixA, int ** matrixB, int row, int col) {
	//buat matrix baru untuk menampung hasil
	int ** result = constructMatrix(row, col);
	
	//lakukan loop baris
	for (int i=0; i<row; i++) {
		//lakukan loop kolom
		for (int j=0; j<col; j++) {
			//set elemen pada baris ke i dan kolom ke j menjadi hasil jumlah antara matrik A dan B
			//pada kolom dan baris yang sama
			result[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	
	//keluarkan matriks yang menyimpan hasil penjumlahan
	return result;
}

/*
 * Fungsi untuk menampilkan matrix
 *
 * parameter:
 * matrix: **int - Matrix yang mau di print
 * label: **int - label(nama dari matriksnya contoh: A, B, Hasil)
 * row:int - jumlah baris matrix yang mau dibuat
 * col:int - jumlah kolom matrix yang mau dibuat
*/
void printMatrix(int ** matrix, int row, int col, string label) {
	//print heading
	cout << "\nMatrix " << label << '\n';
	
	//lakukan loop baris
	for (int i=0; i<row; i++) {
		//lakukan loop kolom
		for (int j=0; j<col; j++) {
			//print elemen pada baris ke i dan kolom ke j
			//setelah itu beri tab agar ada jarak antar elemen
			cout << matrix[i][j] << '\t';
		}
		//berikan enter ketika satu baris matrik telah di print
		cout << '\n';
	}
}

int main() {
	//variabel untuk menampung jumlah kolom dan baris
	int row = 0, col = 0;
	
	cout << "Program Penjumlahan Matrix \n";
	
	//input baris dan kolom
	cout << "Input ordo \n";
	cout << "Jumlah baris : ";
	cin >> row;
	
	cout << "Jumlah kolom : ";
	cin >> col;
	
	//buat matrix A dan B
	int ** matrixA = constructMatrix(row, col);
	int ** matrixB = constructMatrix(row, col);
	
	//isi matrix A dan B
	fillMatrix(matrixA, row, col, "A");
	fillMatrix(matrixB, row, col, "B");
	
	//Tampilkan isi matrix A dan B
	printMatrix(matrixA, row, col, "A");
	printMatrix(matrixB, row, col, "B");
	
	//Jumlahkan matrix A dan B
	int ** result = addMatrix(matrixA, matrixB, row, col);
	
	//print matrix hasil penjumlahan A dan B
	printMatrix(result, row, col, "Hasil");
	
	getch();
	
	return 0;
}