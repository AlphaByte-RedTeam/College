// program konversi waktu dari detik

#include <iostream>
using namespace std;

int main (){
    typedef struct { int hh; //jam
                     int mm; //menit
                     int ss; //detik
    } Jam;

    Jam J;
    int TotalDetik;
    int sisa;

//algoritma

    cout << "Berapa jumlah detik? ";
    cin >> TotalDetik;

    J.hh = TotalDetik/3600;
    sisa = TotalDetik%3600;
    J.mm = sisa/60;
    J.ss = sisa%60;

    cout << "Jadi, " << TotalDetik << " detik adalah " << J.hh << " jam " << J.mm << " menit " << J.ss << " detik " << endl;

    return 0;
}









// program konversi waktu ke detik

#include <iostream>
using namespace std;

int main (){
    int TotalDetik;
    typedef struct { int hh;
                     int mm;
                     int ss;
    } Jam;

    Jam J;

//logika
    cout << "Jam : ";
    cin >> J.hh;

    cout << "Menit : ";
    cin >> J.mm;

    cout << "Detik : ";
    cin >> J.ss;

//output

    TotalDetik = (J.hh*3600) + (J.mm*60) + J.ss;

    cout << "Jadi " << J.hh << " jam " << J.mm << " menit " << J.ss << " detik sama dengan " << TotalDetik << " detik." << endl; 
    return 0;
}












// program konversi selisih waktu dari jam awal

#include <iostream>
using namespace std;

int main(){
// Deklarasi
    typedef struct { int hh; //deklarasi jam
                     int mm; //deklarasi menit
                     int ss; //deklarasi detik
    } Jam;

    Jam JamAwal, JamAkhir, DurasiJam;
    int TotalDetikAwal, TotalDetikAkhir, DurasiDetik;
    int Sisa;

// algoritma jam awal
    
    cout << "Masukkan Jam Awal : ";
    cin >> JamAwal.hh;

    cout << "Masukkan Menit Awal : ";
    cin >> JamAwal.mm;

    cout << "Masukkan Detik Awal : ";
    cin >> JamAwal.ss;

    cout << "=====================================" << endl;

// algoritma jam akhir

    cout << "Masukkan Jam Akhir : ";
    cin >> JamAkhir.hh;

    cout << "Masukkan Menit Akhir : ";
    cin >> JamAkhir.mm;

    cout << "Masukkan Detik Akhir : ";
    cin >> JamAkhir.ss;

    cout << "=====================================" << endl;

    // menghitung detik awal
    TotalDetikAwal = (JamAwal.hh*3600) + (JamAwal.mm*60) + JamAwal.ss;

    // menghitung detik akhir
    TotalDetikAkhir = (JamAkhir.hh*3600) + (JamAkhir.mm*60) + JamAkhir.ss;

    // menghitung durasi detik
    DurasiDetik = (TotalDetikAkhir-TotalDetikAwal);

    cout << "Jadi " << DurasiDetik << "  Detik." << endl;

// konversi durasi detik menjadi jam-menit-detik
    DurasiJam.hh = DurasiDetik/3600;
    Sisa = DurasiDetik%3600;
    DurasiJam.mm = Sisa/60;
    DurasiJam.ss = Sisa%60;

    cout << "Jadi total durasinya adalah " << DurasiJam.hh << "Jam " << DurasiJam.mm << " Menit " << DurasiJam.ss << " Detik." << endl;
    
    return 0;
}