#include <iostream>
#include <string>
using namespace std;

int main (){

    //Mendeklarasikan Array
    string data[10][2] = {{"Andre", "Penyakit : Demam"},
                          {"Jonathan", "Penyakit : Pilek"},
                          {"Adi", "Penyakit : Demam Berdarah"},{"Ivana","Penyakit : Batuk Kering"},
                          {"Sherly","Penyakit : Diabates"},{"Aji","Penyakit : Stroke"},
                          {"Geraldo","Penyakit : Hipertensi"},{"Diana","Penyakit : Gagal Jantung"},
                          {"Ayu","Penyakit : TBC"},{"Anissa","Gagal Jantung"} 
    };

    string cari;
    int i, j, n = 10;

    cout << "Daftar nama pasien";
    cout << "\n-----------------------------------------------------" << endl;
    cout << "\n";   //kenapa ada \n, terus dibawah baru nomor, kenapa gak dijadiin 1?
    cout << "1. Andre";
    cout << "\n2. Jonathan";
    cout << "\n3. Adi";
    cout << "\n4. Ivana";
    cout << "\n5. Sherly";
    cout << "\n6. Aji";
    cout << "\n7. Geraldo";
    cout << "\n8. Diana";
    cout << "\n9. Ayu";
    cout << "\n10. Anissa";
    cout << "\nMasukkan Nama yang anda ingin ketahui penyakitnya : ";
    cin >> cari;
    cout << "\n";

    for (i = 0; i < n; i++){
        if (data[i][0] == cari){
            j=1;
            cout << "Hasil pencarian " << data[i][j] << ".\n";
            break;
        }
    }
    if (i == n){
        cout << "Mohon input data yang benar";
    }
    return 0;
    
}