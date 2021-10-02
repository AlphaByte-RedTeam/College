#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Patient {
    
    string name;
    string disease;
};


void printForms ( Patient arrPatients[], int n ){

    for ( int i = 0; i < n; i++ ){
        cout << arrPatients[i].name << ", " << endl;
        cout << arrPatients[i].disease << ", " << endl;
    }
}


//SEQUENTIAL SEARCH FUNCTION
Patient seqSearch ( string name, Patient arrPatients[], int n ){

    Patient patient;
    
    for ( int i = 0; i < n; i++ ){
        if ( arrPatients[i].name == name ){
            patient = arrPatients[i];
        }
        else if ( i == n - 1 ){
            cout << "Pasien tidak ditemukan, coba lagi!" << endl;
            //recursive function
        }
    }

    return patient;
}


//BINARY SEARCH FUNCTION
Patient binSearch ( string name, Patient arrPatients[], int n){

    Patient patient;

    int left = 0;
    int right = n - 1;
    int mid;
    bool found = false;

    while ( left <= right ){
        mid = (left + right) / 2;

        if ( name == arrPatients[mid].name ){
            found = true;
            patient = arrPatients[mid];
            break;
        }
        
        else if ( name < arrPatients[mid].name ){
            right = mid - 1;
        }

        else {
            left = mid + 1;
        }
    }

    if ( found == true ){
        cout << "Data Pasien Ditemukan" << endl;
    }

    else {
        cout << "Pasien tidak ditemukan, coba lagi!" << endl;
        //recursive function
    }

    return patient;
}

//MAIN PROGRAM
int main (){

    const int n = 4;
    Patient arrPatients[10] = {};
    Patient patient;

    //FILLING
    for ( int i = 0; i < n; i++ ){
        Patient patient;

        cout << "Masukkan Nama : ";
        getline (cin, patient.name);

        cout << "Masukkan Penyakit : ";
        getline (cin, patient.disease);

        arrPatients[i] = patient;
    }


    //SORTING
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            if ( arrPatients[j].name > arrPatients[i].name ){
                
                Patient temp = arrPatients[j];
                arrPatients[j] = arrPatients[i];
                arrPatients[i] = temp;
            }
        }
    }


    string inputName = "Oliver";

    auto start = steady_clock::now();

    Patient patientData = seqSearch( inputName, arrPatients, n );
    //Patient patientData = binSearch( inputName, arrPatients, n );

//17:45 05/11/2020
    cout << "Masukkan Nama Yang Ingin Dicari : ";
    getline (cin, patient.name);

    cout << patient.name << " terkena penyakit " << patient.disease << endl;

    auto end = steady_clock::now();
    auto diff = end - start;
    double elapsedTime = double( duration_cast <microseconds> (diff).count() );
    cout << "Elapsed time in Microseconds: " << elapsedTime << endl;

    return 0;
}