#include <iostream>

#include <string>

using namespace std;

int shellSort(int nim[], string names[], int n) {
  // Start with a big gap, then reduce the gap 
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i += 1) {
      int tempNim = nim[i];
      string tempName = names[i];

      int j;
      for (j = i; j >= gap && nim[j - gap] > tempNim; j -= gap) {
        nim[j] = nim[j - gap];
        names[j] = names[j - gap];
      }

      names[j] = tempName;
      nim[j] = tempNim;
    }
  }
  return 0;
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

  shellSort(nim, names, n);

  cout << "Data mahasiswa terurut: \n";
  print(nim, names, n);

  return 0;
}
