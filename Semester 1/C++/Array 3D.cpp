//*****************************************************************
//  © ANDREW VIRYA VICTORIO 2020/10/10  13:18
//  NIM: 32200091
//  TEKNIK INFORMATIKA A.T 2020: 1PTI1: PEMROGRAMAN DASAR (TIB21)
//  RABU -- 8 SKS
//  LATIHAN: MEMBUAT KONSEP PROGRAM MENGGUNAKAN 3D ARRAY
//           (FORUM 21 Okt)
//  DOSEN: CHYQUITHA DANUPUTRI, S.KOM, M.KOM
//*****************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

/*
MAKING FUNCTION:

* FUNCTION FOR DISPLAYING ARRAY
* FUNCTION FOR INPUTTING DISEASE
* FUNCTION FOR INPUTTING DISEASE DATA

*/

const int row = 2;
const int col = 2;

//INPUTTING LIST OF DISEASE

int main (){

    string temp;

    string listDisease[2][2][2] = {
                                    {
                                        {"Jantung Koroner", "Kanker Usus"},
                                        {"Stroke", "TBC"}
                                    },

                                    {
                                        {"Asma", "HIV"},
                                        {"DBD", "Tumor"}
                                    },

    };
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){

                    cout << listDisease[i][j][k] << "\n\n";
                }
            }
        }

    return 0;
}
