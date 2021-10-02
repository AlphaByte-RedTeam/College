#include <iostream>

#include <string>

using namespace std;

void bubbleSort(int nim[], string names[], int n) {
  int i, j;
  int tempNim;
  string tempName;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (nim[j] > nim[j + 1]) {

        tempNim = nim[j + 1];
        nim[j + 1] = nim[j];
        nim[j] = tempNim;

        tempName = names[j + 1];
        names[j + 1] = names[j];
        names[j] = tempName;
      }
    }
  }
}

//fungsi untuk print nilai
print(int nim[], string names[], int n) {
  for (int i = 0; i < n; i++) {
    cout << nim[i] << " - " << names[i] << "\n";
  }
}

int main() {
  int n = 9;
  int nim[] = {
    9911500,
    9811501,
    9822402,
    9811502,
    9733200,
    9733205,
    9611504,
    9611505,
    9522304
  };
  string names[] = {
    "Valdi",
    "Alisha",
    "Rauf",
    "Anka",
    "Aji",
    "Wahyu",
    "Rendi",
    " Dana",
    "Irma"
  };

  //buat enter
  cout << "\n";

  //tampilkan nilai belum terurut
  cout << "Data mahasiswa tak terurut: \n";
  print(nim, names, n);

  //buat enter
  cout << "\n";

  bubbleSort(nim, names, n);

  cout << "Data mahasiswa terurut: \n";
  print(nim, names, n);

  return 0;
}
