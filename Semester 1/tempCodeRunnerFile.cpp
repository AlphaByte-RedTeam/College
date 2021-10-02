//*****************************************************************
//  © ANDREW VIRYA VICTORIO 2020/10/10  13:18
//  NIM: 32200091
//  TEKNIK INFORMATIKA A.T 2020: 1PTI1: PEMROGRAMAN DASAR (TIB21)
//  RABU -- 8 SKS
//  UTS: C++ PROJECT TO MAKE COVID-19 SCREENING PROGRAM
//  DOSEN: CHYQUITHA DANUPUTRI, S.KOM, M.KOM
//  TEMPO: 2020/09/16 ~~ 2020/10/14
//*****************************************************************

//C++ CODE
//DEFINE HEADER
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;


//=====================================
/*
MEMBUAT FUNGSI UNTUK DATA PASIEN:
NAMA PASIEN, UMUR, NIK, ALAMAT,
NO. TELP.
*/
//=====================================

string dataPasienNama(){
    string nama;
    cout << "NAMA PASIEN : ";
    cin.ignore();
    getline(cin, nama);

    return nama;
}
int dataPasienUmur(){
    int umur;
    cout << "UMUR : ";
    cin >> umur;

    return umur;
}

string dataPasienNik(){
    string nik;
    const int maxChar1 = 16;
    cout << "NIK : ";
    cin >> setw(maxChar1) >> nik;

    return nik;
}

string dataPasienAlamat(){
    string alamat;
    cout << "ALAMAT : ";
    cin.ignore();
    getline (cin, alamat);
    
    return alamat;
}

string dataPasienTelp(){
    string noTelp;
    const int maxChar2 = 12;
    cout << "NO TELEPON : +62";
    cin >> setw(maxChar2) >> noTelp;

    return noTelp;
}
//=====================================

//PROSEDUR GARIS
void makeLine(int length) {
	for (int i = 0; i < length; i++)
		cout << "=";
	
	cout << "\n";
}
//=====================================

//MAIN PROGRAM
int main (){

    //DEKLARASI UNTUK JUMLAH PASIEN
    int jumlahPasien = 0;
    int i;

    //DEKLARASI GEJALA
    char batukKering, batukLendir, bersin, bersinPilek, sakitTubuh, 
    kelemahanOtot, demamRingan, demamTinggi, kesulitanBernapas, indraHilang;

    //INTRO SELAMAT DATANG
    cout << "=============================================== \n";
    cout << "Selamat Datang Di Program COVID-19 Screening!! \n";
    cout << "=============================================== \n";
    cout << "           Berapa Jumlah Pasien? = ";
    cin >> jumlahPasien;
    cout << "=============================================== \n";

    //DEKLARASI HASIL SCREENING
    string hasil[jumlahPasien];
    string nama [jumlahPasien];

    //LOOPING: JUMLAH PASIEN
    for (i=0; i<jumlahPasien; i++){
        string name;
        cout << "Data Pasien ke-" << i+1 << "\n \n";
    
    //NAMA PASIEN
    cout << "NAMA PASIEN : ";
    cin >> name;
    nama[i] = name;

    //PEMANGGILAN FUNGSI BAGIAN DATA PASIEN
    dataPasienUmur();
    dataPasienNik();
    dataPasienAlamat();
    dataPasienTelp();

    //PERNYATAAN Y/T
    cout << "============================================================================= \n";
    cout << "      Ketik Y/y jika pernyataan benar atau T/t jika pernyataan salah! \n";
    cout << "============================================================================= \n";
    cout << "                   Jawablah pernyataan berikut ini : \n \n";

    cout << "Apakah anda mengalami batuk kering? ";
    cin >> batukKering; //input Y/y atau T/t
    
    cout << "Apakah anda mengalami batuk + lendir? ";
    cin >> batukLendir; //input Y/y atau T/t 

    cout << "Apakah anda mengalami bersin? ";
    cin >> bersin; //input Y/y atau T/t

    cout << "Apakah anda mengalami bersin + pilek? ";
    cin >> bersinPilek; //input Y/y atau T/t

    cout << "Apakah anda mengalami sakit tubuh? ";
    cin >> sakitTubuh; //input Y/y atau T/t

    cout << "Apakah anda mengalami kelemahan otot? ";
    cin >> kelemahanOtot; //input Y/y atau T/t

    cout << "Apakah anda mengalami demam ringan? ";
    cin >> demamRingan; //input Y/y atau T/t

    cout << "Apakah anda mengalami demam tinggi? ";
    cin >> demamTinggi; //input Y/y atau T/t

    cout << "Apakah anda mengalami kesulitan bernapas? ";
    cin >> kesulitanBernapas; //input Y/y atau T/t

    cout << "Apakah anda mengalami kehilangan indra pengecap atau perasa? ";
    cin >> indraHilang; //input Y/y atau T/t

    cout << "=============================================================\n \n";

    //BATUK KERING + BERSIN
    if (tolower(batukKering) == 'y' &&
        tolower(bersin) == 'y' ){
            cout << "Indikasi penyakit hanya karena polusi udara.\n";
            hasil[i] = "POLUSI UDARA";
        }
        else if (tolower (batukKering) == 't' &&
                 tolower (bersin) == 'y' ){
                     cout << "Indikasi hanya bersin biasa.\n";
                     hasil[i] = "BERSIN BIASA";
                 }
        else if (tolower (batukKering) == 'y' &&
                 tolower (bersin) == 't' ){
                     cout << "Indikasi hanya batuk biasa.\n";
                     hasil[i] = "BATUK BIASA";
                 }
        else {
            cout << "TIDAK ADA INDIKASI.\n";
            hasil[i] = "TIDAK ADA INDIKASI";
        }
            //BATUK KERING + BATUK LENDIR + BERSIN + BERSIN PILEK
            if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 'y'){
                     cout << "Indikasi penyakit hanya PILEK BIASA, segera minum obat.\n";
                     hasil[i] = "PILEK BIASA";
                 }
            else if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 't'){
                     cout << "Indikasi hanya FLU BIASA, segera minum obat.\n";
                     hasil[i] = "FLU BIASA";
                 }
            else if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 't' &&
                     tolower (bersinPilek) == 't'){
                     cout << "Indikasi hanya BATUK BIASA, segera minum obat.\n";
                     hasil[i] = "BATUK BIASA";
                 }
            else if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 't' &&
                     tolower (bersin) == 't' &&
                     tolower (bersinPilek) == 't'){
                     cout << "Indikasi hanya BATUK BIASA, segera minum obat.\n";
                     hasil[i] = "BATUK BIASA";
                 }
            else if (tolower (batukKering) == 't' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 'y'){
                     cout << "Indikasi hanya FLU BIASA, segera minum obat.\n";
                     hasil[i] = "FLU BIASA";
                 }
            else if (tolower (batukKering) == 't' &&
                     tolower (batukLendir) == 't' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 'y'){
                     cout << "Indikasi hanya BERSIN-BERSIN, segera minum obat.\n";
                     hasil[i] = "BERSIN-BERSIN";
                 }
            else if (tolower (batukKering) == 't' &&
                     tolower (batukLendir) == 't' &&
                     tolower (bersin) == 't' &&
                     tolower (bersinPilek) == 'y'){
                     cout << "Indikasi hanya FLU BIASA, segera minum obat.\n";
                     hasil[i] = "FLU BIASA";
                 }
            else{
                cout << "TIDAK ADA INDIKASI.\n";
                hasil[i] = "TIDAK ADA INDIKASI";
            }
                 
            //BATUK KERING+BATUK LENDIR + BERSIN
            //BERSIN PILEK + SAKIT TUBUH + KELEMAHAN OTOT
            //DEMAM RINGAN
            if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 'y' &&
                     tolower (sakitTubuh) == 'y' &&
                     tolower (kelemahanOtot) == 'y' &&
                     tolower (demamRingan) == 'y'){
                         cout << "Anda terkena penyakit FLU, segera minum obat.\n";
                         hasil[i] = "FLU";
                     }
            else if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 'y' &&
                     tolower (sakitTubuh) == 'y' &&
                     tolower (kelemahanOtot) == 'y' &&
                     tolower (demamRingan) == 't'){
                         cout << "Anda terkena penyakit FLU TANPA DEMAM, segera minum obat.\n";
                         hasil [i] = "FLU TANPA DEMAM";
                     }
            else if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 'y' &&
                     tolower (sakitTubuh) == 'y' &&
                     tolower (kelemahanOtot) == 't' &&
                     tolower (demamRingan) == 't'){
                         cout << "Anda terkena penyakit FLU TANPA DEMAM & TIDAK LEMAH OTOT, segera minum obat.\n";
                         hasil[i] = "FLU TANPA DEMAM & TIDAK LEMAH OTOT";
                     }
            else if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 'y' &&
                     tolower (sakitTubuh) == 't' &&
                     tolower (kelemahanOtot) == 't' &&
                     tolower (demamRingan) == 't'){
                         cout << "Anda terkena penyakit FLU TANPA DEMAM DAN TIDAK SAKIT TUBUH MAUPUN LEMAH OTOT, segera minum obat.\n";
                         hasil[i] = "FLU TANPA DEMAM & TIDAK SAKIT TUBUH MAUPUN LEMAH OTOT";                        
                     }
            else if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 't' &&
                     tolower (sakitTubuh) == 't' &&
                     tolower (kelemahanOtot) == 't' &&
                     tolower (demamRingan) == 't'){
                         cout << "Indikasi hanya FLU BIASA, segera minum obat.\n";
                         hasil[i] = "FLU BIASA";
                     }
            else if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 't' &&
                     tolower (bersinPilek) == 't' &&
                     tolower (sakitTubuh) == 't' &&
                     tolower (kelemahanOtot) == 't' &&
                     tolower (demamRingan) == 't'){
                         cout << "Indikasi hanya BATUK BIASA, segera minum obat.\n";
                         hasil[i] = "BATUK BIASA";
                     }
            else if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 't' &&
                     tolower (bersin) == 't' &&
                     tolower (bersinPilek) == 't' &&
                     tolower (sakitTubuh) == 't' &&
                     tolower (kelemahanOtot) == 't' &&
                     tolower (demamRingan) == 't'){
                         cout << "Indikasi hanya BATUK BIASA, segera minum obat.\n";
                         hasil[i] = "BATUK BIASA";
                     }
                else {
                         cout << "TIDAK ADA INDIKASI.\n";
                         hasil[i] = "TIDAK ADA INDIKASI";
                     }
            //BATUK KERING+BATUK LENDIR + BERSIN
            //BERSIN PILEK + SAKIT TUBUH + KELEMAHAN OTOT
            //DEMAM TINGGI + KESULITAN BERNAPAS + KEHILANGAN INDRA
            if (tolower (batukKering) == 'y' &&
                     tolower (batukLendir) == 'y' &&
                     tolower (bersin) == 'y' &&
                     tolower (bersinPilek) == 'y' &&
                     tolower (sakitTubuh) == 'y' &&
                     tolower (kelemahanOtot) == 'y' &&
                     tolower (demamRingan) == 'y' &&
                     tolower (demamTinggi) == 'y' &&
                     tolower (kesulitanBernapas) == 'y' &&
                     tolower (indraHilang) == 'y'){
                         cout << "Anda terinfeksi COVID-19, segera lakukan Test atau pergi kerumah sakit terdekat!\n";
                         hasil[i] = "COVID-19";
                     }
            else if (tolower (batukKering) == 't' &&
                     tolower (batukLendir) == 't' &&
                     tolower (bersin) == 't' &&
                     tolower (bersinPilek) == 't' &&
                     tolower (sakitTubuh) == 't' &&
                     tolower (kelemahanOtot) == 't' &&
                     tolower (demamRingan) == 't' &&
                     tolower (demamTinggi) == 't' &&
                     tolower (kesulitanBernapas) == 't' &&
                     tolower (indraHilang) == 't'){
                         cout << "TIDAK ADA INDIKASI.\n";
                         hasil[i] = "TIDAK ADA INDIKASI";
                     }
                     else {
                         cout << "Anda tidak terkena penyakit\n";
                         hasil [i] = "TIDAK ADA INDIKASI";
                     }
    cout << "================================================================================= \n";

    }

    system("cls");
    cout << "\t\t\tHASIL PEMERIKSAAN PASIEN : \n\n";
    makeLine(100);
    cout << "|\tNO\t|\t\tNAMA\t\t|\t\t\tHASIL\t\t\t|\n";
    makeLine(100);
    for(int i=0; i<jumlahPasien; i++){
        cout << "|\t" << (i+1) << "\t" << "|\t\t" << nama[i] << "\t\t" << "|\t\t\t" << hasil[i] << "\t\t|\n\n";
    }
    makeLine(100);

    cout << "3M: MENCUCI TANGAN, MEMAKAI MASKER, MENJAGA JARAK\n";
    cout << "LAKUKAN PHYSICAL DISTANCING\n";
    cout << "JAGALAH KESEHATAN TUBUH ANDA\n";
    cout << "KALAU TERPAKSA KELUAR, LAKUKAN 3M\n";
    cout << "TETAP DIRUMAH SAJA\n";
    cout << "SEMOGA SEHAT SELALU\n";

    return 0;
}