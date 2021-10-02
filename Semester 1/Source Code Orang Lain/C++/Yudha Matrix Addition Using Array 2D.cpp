/*
 * Hai Tomato
*/

#include <iostream>
#include <conio.h>

using namespace std;

const int row = 3;
const int col = 3;

typedef int LarikCol[3];
typedef LarikCol Matriks[3];

/*
 * Fungsi untuk mengisi matriks
 *
 * parameter:
 * matriks: Matriks - matriks yang mau di input
 * label: string - Label dari matriks yang di input contoh: A, B
*/
void isiMatriks(Matriks matriks, string label) {
	//output heading
	cout << "\nIsi matriks " << label << "\n";
	
	//lakukan loop terhadap baris
	for (int i=0; i<row; i++) {
		//lakukan loop terhadap kolom
		for (int j=0; j<col; j++) {
			//isi nilai elemen matriks pada baris ke i dan kolom ke j
			cout << "A[" << i << "][" << j << "] = ";
			cin >> matriks[i][j];
		}
	}
}

/*
 * Fungsi untuk menjumlahkan matriks
 *
 * parameter:
 * matriksA: Matriks - Matriks pertama
 * matriksA: Matriks - Matriks kedua
 * hasil: Matriks - Matriks yang menyimpan hasil
*/
void tambahMatriks(Matriks matriksA, Matriks matriksB, Matriks hasil) {	 
	//lakukan loop baris
	for (int i=0; i<row; i++) {
		//lakukan loop kolom
		for (int j=0; j<col; j++) {
			//set elemen pada baris ke i dan kolom ke j menjadi hasil jumlah antara matrik A dan B
			//pada kolom dan baris yang sama
			hasil[i][j] = matriksA[i][j] + matriksB[i][j];
		}
	}
}

/*
 * Fungsi untuk menampilkan matriks
 *
 * parameter:
 * matriks: Matriks - matriks yang mau di print
 * label: string - label(nama dari matriksnya contoh: A, B, Hasil)
*/
void printMatriks(Matriks matriks, string label) {
	//print heading
	cout << "\nMatriks " << label << '\n';
	
	//lakukan loop baris
	for (int i=0; i<row; i++) {
		//lakukan loop kolom
		for (int j=0; j<col; j++) {
			//print elemen pada baris ke i dan kolom ke j
			//setelah itu beri tab agar ada jarak antar elemen
			cout << matriks[i][j] << '\t';
		}
		//berikan enter ketika satu baris matrik telah di print
		cout << '\n';
	}
}

int main() {
	cout << "Program Penjumlahan Matriks \n";
	
	//buat matriks A dan B
	Matriks matriksA;
	Matriks matriksB;
	
	//isi matriks A dan B
	isiMatriks(matriksA, "A");
	isiMatriks(matriksB, "B");
	
	//Tampilkan isi matriks A dan B
	printMatriks(matriksA, "A");
	printMatriks(matriksB, "B");
	
	//buat matriks untuk menyimpan hasil jumlah
	Matriks hasil;
	
	//Jumlahkan matriks A dan B dan simpan hasil jumlahnya pada matriks hasil
	tambahMatriks(matriksA, matriksB, hasil);
	
	//print matriks hasil
	printMatriks(hasil, "Hasil");
	
	getch();
	
	return 0;
}

/*
 * Semangat yaa :")
*/
