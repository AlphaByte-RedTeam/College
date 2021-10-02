//********************************************************************
//  © KELOMPOK 11 2020/10/17
//  ANGGOTA :
//  ~ ANDREW VIRYA VICTORIO - 32200091
//  ~ VINCENT GEORGE CHANDRA - 32200083
//  ~ MATIAS INDRA PANGESTU - 32200095
//  ~ BENEDICTUS DIKHA ARIANDA - 32200092
//  ~ CALVIN OWEN SUSANTO - 32200084
//  TEKNIK INFORMATIKA A.T 2020: 1PTI1: PEMROGRAMAN DASAR (TIB21)
//  RABU -- 8 SKS
//  TUGAS KELOMPOK: MEMBUAT PROGRAM DENGAN 4 FUNGSI, 1 MAIN PROGRAM
//                  DENGAN 1 DIMENSI ARRAY DAN 2 DIMENSI ARRAY
//  PEMBAHASAN: 9
//  DOSEN: CHYQUITHA DANUPUTRI, S.KOM, M.KOM
//  TEMPO: 2020/10/21 ~~ 2020/10/28
//********************************************************************

#include <iostream>
#include <string>

using namespace std;

//VINCENT GEORGE CHANDRA - 32200083
struct indexStruct
{
	string name;
	int index;
};

//VINCENT GEORGE CHANDRA - 32200083
void printValidNames(string names[], int row) {

	cout << "Berikut adalah nama-nama yang terdaftar: " << endl;
	for (int i = 0; i < row; i++) {
		cout << names[i] << ", ";
	}
	cout << endl << endl;
}

//ANDREW VIRYA VICTORIO - 32200091
string inputName()
{
	string username;

	cout << "Masukan nama mahasiswa : ";
	getline(cin, username);
	cout << "Nama username: " << username << endl;

	return username;
}

//BENEDICTUS DIKHA ARIANDA - 32200092
indexStruct getIndex(string username, string names[5], int row)
{
	int number = 0;
	indexStruct indStruct;

	for (int i = 0; i < row; i++) {
		if (username == names[i]) {
			cout << "Nama terdaftar" << endl;
			number = i;

			indStruct.name = username;
			indStruct.index = number;
			break;
		}
		else if (i == 4) {
			cout << "Nama tidak terdaftar, coba input ulang: " << endl;
			username = inputName();
			indStruct = getIndex(username, names, row); // recursive function
		}
	}

	return indStruct;
}

//CALVIN OWEN SUSANTO - 32200084
float average(float tabelNilai[][5], int index, int col)
{
	float avg;
	float jumlah = 0;

	for (int i = 0; i < col; i++) {
		jumlah = jumlah + tabelNilai[index][i];
	}

	avg = jumlah / col;
	return avg;
}

//ANDREW VIRYA VICTORIO - 32200091
char getGrade(float avg)
{
	char grade = ' ';

	if (100 >= avg && avg >= 90) {
		grade = 'A';
	}
	else if (90 > avg && avg >= 80) {
		grade = 'B';
	}
	else if (80 > avg && avg >= 70) {
		grade = 'C';
	}
	else if (70 > avg && avg >= 60) {
		grade = 'D';
	}
	else if (60 > avg && avg >= 50) {
		grade = 'E';
	}
	else if (50 > avg) {
		grade = 'F';
	}
	else {
		cout << "Error!!";
	}

	return grade;
}

//MATIAS INDRA PANGESTU - 32200095
void printNilai(string name, float avg, char grade)
{
	cout << "\nBerikut Nilai Dari :" << endl;

	cout << "Nama: " << name << '\n';
	cout << "Rata-rata: " << avg << '\n';
	cout << "Skor: " << grade << '\n';
}


//VINCENT GEORGE CHANDRA - 32200083
int main()
{
	const int row = 5;
	const int col = 5;

	string username;
	indexStruct indStruct;
	int index;
	float avg;
	char grade;

	string names[row] = { "James", "John", "Oliver", "Castor", "Matthew" };
	float tabelNilai[row][col] = { { 80, 60, 75, 45, 90 },
								   { 90, 40, 40, 75, 80 },
								   { 45, 90, 100, 95, 80 },
								   { 80, 80, 80, 90, 80 },
								   { 72, 88, 45, 40, 90 }
	};
    
	cout << "========================" << endl;
	cout << "Database nilai mahasiswa" << endl;
    cout << "========================" << endl;

	printValidNames(names, row);
	username = inputName();

	indStruct = getIndex(username, names, row);
	username = indStruct.name;
	index = indStruct.index;

	avg = average(tabelNilai, index, col);
	grade = getGrade(avg);
	printNilai(username, avg, grade);

	return 0;
}