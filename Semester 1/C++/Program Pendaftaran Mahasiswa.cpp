//PEMDAS 13
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
using namespace std;

/*
INPUT:                  --> struct
- NamaMahasiswa                  --> string
- tahun masuk           --> int
- kode fakultas         --> int
- kode jurusan          --> int
- no urut pendaftaran   --> int
- nilai test masuk      --> int
PROSES:                 --> switch case
- Kode pilihan 01 (Fakultas teknik): - kode jurusan 11 --> teknik informatika --> Uang masuk Rp. 30.000.000 --> array
                                     - kode jurusan 21 --> sistem informasi --> Uang masuk Rp. 32.000.000   --> array
                                
- Kode pilihan 02 (Fakultas Pertanian): - kode jurusan 12 --> Agroteknologi --> Uang masuk Rp. 32.000.000   --> array
                                        - kode jurusan 22 --> Kehutanan --> Uang masuk Rp. 28.000.000       --> array
- jika nilai test masuk calon mahasiswa >=85, disc uang masuk 30%   --> int
- jika nilai <85 atau <=80, disc uang masuk 15%                     --> int
OUTPUT:
- NIM merupakan gabungan karakter dari tahun masuk, kode fakultas, kode jurusan dan NoUrut_Daftar pendaftaran
- Keterangan fakultas dan jurusan
- jumlah harga discount
- jumlah total biaya bersih
- data mahasiswa akan dikeluarkan sebagai laporan file berdasarkan NIM masing" berupa .txt
*/

/*
PROGRAM PENDAFTARAN CALON MAHASISWA UNIVERSITAS X
=================================================
Kode Fakultas:                                      --> flavour text
------------------------
(01) Fakultas Teknik
(02) Fakultas Pertanian
Kode Jurusan & Harga Uang Masuk:
----------------------------------------
(11) Teknik Informatika: Rp. 30.000.000
(21) Sistem Informasi:   Rp. 32.000.000
(12) Agroteknologi:      Rp. 32.000.000
(22) Kehutanan:          Rp. 28.000.000 
=================================================
Masukkan Jumlah Calon Mahasiswa: ?                  --> int, loop
=================================================
Calon Mahasiswa Ke-?                                --> loop
=================================================
Nama: (NamaMahasiswa lengkap)
Tahun Masuk: 20??
Kode Fakultas: ??                                   --> if..else OR switch case
Kode Jurusan: ??                                    --> if..else OR switch case
No.Urut Pendaftaran: ??
Nilai Test Masuk: ??                                --> batas nilai 0-100
=================================================
NIM: tahunMasuk_kodeFakultas_kodeJurusan_noDaftar 20011201
Fakultas: ????
Jurusan: ????
*/

struct dataMahasiswa{

    string NamaMahasiswa;
    string fakultas;
    string jurusan;
    string nim;
    string KodeFakultas;

    int TahunMasuk;
    int KodeJurusan;
    int NoUrut_Daftar;
    int NilaiTest;
    int UangMasuk;
    int uang;
    int diskon;
    int biayaBersih;

};

string nim ( int TahunMasuk, string KodeFakultas, int KodeJurusan, int NoUrut_Daftar )
{
    //Mengubah tipe data lain ke tipe string untuk digabungkan
    string stmasuk = to_string( TahunMasuk ), skjurusan = to_string( KodeJurusan ), sno_urut = to_string(NoUrut_Daftar);

    return stmasuk + KodeFakultas + skjurusan + sno_urut; 
}

int main (){

    int jumlahMahasiswa;

    dataMahasiswa arrMahasiswa[10000];
    dataMahasiswa NamaMahasiswa;
    dataMahasiswa tahun;
    dataMahasiswa fakultas;
    dataMahasiswa jurusan;
    dataMahasiswa noUrut;
    dataMahasiswa nilai;
    dataMahasiswa uang;
    
    string type = ".txt";

    cout << "PROGRAM PENDAFTARAN CALON MAHASISWA UNIVERSITAS X\n";
    cout << "=================================================\n";
    cout << "Kode Fakultas:\n"
         << "------------------------\n"
         << "(01) Fakultas Teknik\n"
         << "(02) Fakultas Pertanian\n\n"
         << "Kode Jurusan & Harga Uang Masuk:\n"
         << "----------------------------------------\n"
         << "(11) Teknik Informatika: Rp. 30.000.000\n"
         << "(21) Sistem Informasi:   Rp. 32.000.000\n"
         << "(12) Agroteknologi:      Rp. 32.000.000\n"
         << "(22) Kehutanan:          Rp. 28.000.000\n"
         << "=================================================\n";
    cout << "Masukkan Jumlah Calon Mahasiswa: ";
    cin >> jumlahMahasiswa;
    cout << "=================================================\n";

    dataMahasiswa data[jumlahMahasiswa];
    //cin.ignore();

    for ( int i = 0; i < jumlahMahasiswa; i++ ){

        bool checker1 = false;
        bool checker2 = false;

        cout << "Calon Mahasiswa Ke-" << i+1 << endl;
        cout << "=================================================\n";

        cout << "Nama: ";
        cin.ignore();
        getline ( cin, data[i].NamaMahasiswa );

        cout << "Tahun Masuk: ";
        cin >> data[i].TahunMasuk;

        cout << "Kode Fakultas: ";
        cin >> data[i].KodeFakultas;

        cout << "Kode Jurusan: ";
        cin >> data[i].KodeJurusan;

        cout << "No. Urut Daftar: ";
        cin >> data[i].NoUrut_Daftar;

        cout << "Nilai Test: ";
        cin >> data[i].NilaiTest;
        cout << "=================================================";

        while ( checker1 == false ){

            if ( data[i].KodeFakultas == "01" ){
                data[i].fakultas = "Fakultas Teknik";
                checker1 = true;

                do{
                    if ( data[i].KodeJurusan == 11 ){
                        data[i].jurusan = "Teknik Informatika"; 
                        data[i].uang = 30000000;
                        checker2 = true;

                    } 
                    
                    else if ( data[i].KodeJurusan == 21 ){
                        data[i].jurusan = "Teknik Informatika";
                        data[i].uang = 32000000;
                        checker2 = true;

                    } 
                    
                    else{
                        //cout << endl;
                        cout << "Kode Jurusan Yang Dimasukkan Salah!!\n";
                        
                        cout << "Masukkan Kode Jurusan Yang Benar: ";
                        cin >> data[i].KodeJurusan;
                    }
                } 
                while (checker2 == false);
                

            }

            else if ( data[i].KodeFakultas == "02" ){
                data[i].fakultas = "Fakultas Pertanian";
                checker1 = true;

                do{

                    if ( data[i].KodeJurusan == 12 ){
                        data[i].jurusan = "Agroteknologi"; 
                        data[i].uang = 32000000;
                        checker2 = true;

                    }
                    
                    else if ( data[i].KodeJurusan == 22 ){
                        data[i].jurusan = "Kehutanan";
                        data[i].uang = 28000000;
                        checker2 = true;
                        
                    }
                    
                    else{
                        //cout << endl;
                        cout << "Kode Jurusan Yang Dimasukkan Salah!!\n";
                        
                        cout << "Masukkan Kode Jurusan Yang Benar: ";
                        cin >> data[i].KodeJurusan;
                        cout << endl;
                    }
                } 
                
                while ( checker2 == false );

            } 
            
            else{
                //cout << endl;
                cout << "Kode Fakultas Yang Dimasukkan Salah!!\n";

                cout << "Masukkan Kode Fakultas Yang Benar: ";
                cin >> data[i].KodeFakultas;
                cout << endl;
            }
        }

        if ( data[i].NilaiTest >= 85 ){
            data[i].diskon = 0.3 * data[i].uang;
        }
        
        else if ( data[i].NilaiTest >= 80 * data[i].NilaiTest < 85 ){
            data[i].diskon = 0.15 * data[i].uang;
        }
        
        else{
            data[i].diskon = 0;
        }

        data[i].biayaBersih = data[i].uang - data[i].diskon;
        data[i].nim = nim ( data[i].TahunMasuk, data[i].KodeFakultas, data[i].KodeJurusan, data[i].NoUrut_Daftar );
        
        stringstream file;
        file << data[i].nim << type;
        
        ofstream mhsfile;
        mhsfile.open(file.str());
        mhsfile << "Nama Mahasiswa  : " << data[i].NamaMahasiswa << endl;
        mhsfile << "NIM             : " << data[i].nim << endl;
        mhsfile << "Fakultas        : " << data[i].fakultas << endl;
        mhsfile << "Jurusan         : " << data[i].jurusan << endl;
        mhsfile << "Potongan/Diskon : " << data[i].diskon << endl;
        mhsfile << "Biaya Bersih    : " << data[i].biayaBersih << endl;
        mhsfile.close();
        cout << endl;
    }
    cout << "Proses Cetakan Selesai!"; 
    
    return 0;
}