#include<iostream>
using namespace std;

int main()
{
    //program untuk menampilkan pengklasifikasian hewan

    int jumlahk, baris, kolom;
    cout << "Selamat datang di program pengklasifikasian hewan!\n\n";
    cout << "Masukkan jumlah pengklasifikasian : ";
    cin >> jumlahk; //jumlah klasifikasi

    cout << "Ingin membuat berapa baris? : ";
    cin >> baris;

    cout << "Ingin membuat berapa kolom? : ";
    cin >> kolom;

    cout << "\n";

    string hewan[jumlahk][baris][kolom];
    string hewank[jumlahk]; //untuk menyimpan tipe pengklasifikasian

    for(int i = 0; i < jumlahk; i ++) //untuk menyimpan tipe pengklasifikasian
    {
        cout << "Masukkan tipe pengklasifikasian ke-" << i+1 << " : ";
        cin >> hewank[i];
    }

    cout << "\n";

    for(int i = 0; i < jumlahk; i++) //untuk menyimpan data hewan tiap klasifikasi
    {
        cout << "Masukkan hewan dengan klasifikasi " << hewank[i] << "\n";

        for(int j = 0; j < baris; j++)
        {
            for(int k = 0; k < kolom; k++)
            {
                cout << "Masukkan nama hewan baris ke-" << j + 1 << " dan kolom ke-" << 
                        k + 1 << " : ";
                cin >> hewan[i][j][k];
            }
        }
        cout << "\n";
    }

    for(int i = 0; i < jumlahk; i++)
    {
        cout << i + 1 << ". " << hewank[i] << "\n";
        for(int j = 0; j < baris; j++)
        {
            for(int k = 0; k < kolom; k++)
            {
                cout << hewan[i][j][k] << ", "; 
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}