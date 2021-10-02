#include <iostream> 
#include <string>

using namespace std;  
  
/*
 * Fungsi ini menggunakan elemen terakhir sebagai nilai acuan
 * Fungsi ini akan memisahkan semua nilai yang lebih kecil ke sebelah kiri sebelum nilai acuan
 * dan semua nilai yang lebih besar ke sebelah kanan setelah nilai acuan
 * nim[] --> nilai yang mau di sort,  
 * start --> indeks awal
 * end --> indeks nilai acuan
*/
int buatPartisi (int nim[], string names[], int start, int end)  
{  
    int acuan = nim[end]; // nilai acuan  
    int i = (start - 1); // indeks elemen terbawah
  int tempNim;
  string tempName;
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // jika elemen saat ini lebih kecil dari nilai acuan
      if (nim[j] < acuan)  
      {  
 
        i++;
        //tukar elemen score ke i dengan score ke j
      	tempNim = nim[i];
    		nim[i] = nim[j];
    		nim[j] = tempNim;

        tempName = names[i];
    		names[i] = names[j];
    		names[j] = tempName;
      }  
    } 
    
    //setelah perulangan selesai tukar score pada indeks setelah i dengan nilai acuan
     tempNim = nim[i + 1];
    nim[i + 1] = nim[end];
    nim[end] = tempNim;

    tempName = names[i + 1];
    names[i + 1] = names[end];
    names[end] = tempName;
    
    //keluarkan indeks dari nilai acuan
    return (i + 1);  
}  
  
/* 
 * Fungsi melakukan quick sort
 * nim[] --> nilai yang mau di sort,  
 * start --> batas awal index untuk sort,  
 * end --> batas akhir index untuk sort 
 */
void quickSort(int nim[], string names[], int start, int end)  
{  
    if (start < end)  
    {  
		//partisi indeks adalah indeks dari nilai acuan yang memisahkan
		//elemen yang lebih kecil dan lebih besar dari nilai acuan
        int partisiIndex = buatPartisi(nim, names, start, end);  
  
		//sort nilai yang lebih kecil dari nilai acuan
        quickSort(nim, names, start, partisiIndex - 1);  
        //sort nilai yang lebih besar dari nilai acuan
        quickSort(nim, names, partisiIndex + 1, end);  
    }  
}  

//fungsi untuk print nilai
print(int nim[], string names[], int n) {
	for (int i=0; i<n; i++){
    cout << nim[i] << " - " << names[i] << "\n";
	}
}  

int main()  
{  
	int n = 9;
  int nim[] = {9911500, 9811501, 9822402, 9811502, 9733200, 9733205, 9611504, 9611505, 9522304};
  string names[] = {"Valdi", "Alisha", "Rauf", "Anka", "Aji", "Wahyu", "Rendi", " Dana", "Irma"};
	
	//buat enter
	cout << "\n";
	
	//tampilkan nilai belum terurut
	cout << "Data mahasiswa tak terurut: \n";  
	print(nim, names, n);
	
	//buat enter
	cout << "\n";
	
	quickSort(nim, names, 0, n - 1);
    
  cout << "Data mahasiswa terurut: \n";  
  print(nim, names, n);
    
  return 0;  
}  
