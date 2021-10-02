#include <iostream>
#include <conio.h>
using namespace std;

int main (){
    
    int i;
    int j;
    int n;
    int hasil;

    //Masukkan data pasien
    cout << "Masukkan banyak pasien : ";
    cin >> n;

    string data[2][n], x, ketemu[2][n];

    for (i = 0; i < n; i++){
        cout << "Data pasien Ke-"<<i+1<<endl;
        cout << "Nama : ";
        cin >> data[0][i];
        cout << "Penyakit : ";
        cin >> data[1][i];
    }

    //pencarian data pasien
    cout << "\n======================" << endl;
    cout << "Data yang ingin dicari : ";
    cin >> x;

    i=0;
    j=0;

    ulang:
    if (i!=n){

        if (x == data[0][i] || x == data[1][i]){
            ketemu[0][j] = data[0][i];
            ketemu[1][j] = data[1][i];
            hasil = true;
            j++
            i++
            goto ulang;
        }
        else {
            i++;
            goto ulang;
        }
    }
    else {
        cout << "==============================="<<endl;
        cout << "Hasil pencarian data, yaitu :"<< endl;
        cout << "==============================="<<endl;
        if(hasil){
            for (i=0; i < j; i++) {
                cout << "Data ditemukan" << endl;
                cout << "Nama :" << ketemu[0][i] << endl;
                cout << "Penyakit :" << ketemu[1][i] << endl;
            }
        }else if(!(hasil)){
            cout << "Data tidak ditemukan" << endl;
        }
    }
    return 0;
}