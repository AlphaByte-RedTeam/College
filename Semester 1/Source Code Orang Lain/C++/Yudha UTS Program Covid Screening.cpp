#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void makeLine(int length) {
	for (int i = 0; i < length; i++)
		cout << "=";
	
	cout << "\n";
}

main() {
	cout << "Selamat datang di program pemeriksaan gejala terinfeksi virus Corona\n";
	makeLine(70);
	int n = 0;
	cout << "Berapa jumlah pasien: ";
	cin >> n;
	
	string names[n];
	string results[n];
	
	for (int i = 0; i < n; i++) {
		string nama, umur, nik, alamat, notelp;
		
		cout << "\n\nMasukan data pasien ke-" << i + 1 << "\n";
		
		cout << "Nama : ";
		cin >> nama;
		names[i] = nama;
		
		cout << "Umur : ";
		cin >> umur;
		cout << "Nik : ";
		cin >> nik;
		cout << "Alamat : ";
		cin >> alamat;
		cout << "No Telp : ";
		cin >> notelp;
		
		cout << "\nTulis 'Y/y' jika pernyataan berikut benar, atau 'T/t' jika salah \n";
		
		char batukkering, batuklendir, bersin, pilek, sakittubuh;
		char kelemahanotot, demamringan, demamtinggi, kesulitanbernafas, indrahilang;
		
		cout << "Apakah " << nama << " batuk kering? ";
		cin >> batukkering;
		
		cout << "Apakah " << nama << " batuk lendir? ";
		cin >> batuklendir;
		
		cout << "Apakah " << nama << " bersin? ";
		cin >> bersin;
		
		cout << "Apakah " << nama << " pilek? ";
		cin >> pilek;
		
		cout << "Apakah " << nama << " sakit tubuh? ";
		cin >> sakittubuh;
		
		cout << "Apakah " << nama << " kelemahan otot? ";
		cin >> kelemahanotot;
		
		cout << "Apakah " << nama << " demam ringan? ";
		cin >> demamringan;
		
		cout << "Apakah " << nama << " demam tinggi? ";
		cin >> demamtinggi;
		
		cout << "Apakah " << nama << " kesulitan bernafas? ";
		cin >> kesulitanbernafas;
		 
		cout << "Apakah " << nama << " hilang indra pengecap dan perasa? ";
		cin >> indrahilang;
		
		cout << "\n";
		if (
			tolower(batukkering) == 'y' && 
			tolower(bersin) == 'y' && 
			tolower(batuklendir) == 'y' && 
			tolower(sakittubuh) == 'y' && 
			tolower(kelemahanotot) == 'y' && 
			tolower(demamtinggi) == 'y' && 
			tolower(kesulitanbernafas) == 'y' && 
			tolower(indrahilang) == 'y'
		) {
			cout << "Indikasi penyakit karena virus corona";
			results[i] = "Virus Corona";
		} else if (
			tolower(batukkering) == 'y' && 
			tolower(bersin) == 'y' && 
			tolower(batuklendir) == 'y' && 
			tolower(pilek) == 'y' && 
			tolower(sakittubuh) == 'y' && 
			tolower(kelemahanotot) == 'y' && 
			tolower(demamringan) == 'y'
		) {
			cout << "Indikasi penyakit karena sakit flu";
			results[i] = "Sakit flu";
		} else if (
			tolower(batukkering) == 'y' && 
			tolower(bersin) == 'y' && 
			tolower(batuklendir) == 'y' && 
			tolower(pilek) == 'y'
		) {
			cout << "Indikasi penyakit karena pilek biasa";
			results[i] = "Pilek biasa";
		} else if (
			tolower(batukkering) == 'y' && tolower(bersin) == 'y'
		) {
			cout << "Indikasi penyakit karena polusi udara";
			results[i] = "Polusi udara";
		} else {
			cout << "Tidak ada indikasi";
			results[i] = "Gapapa";
		}
	}
	
	system("cls");
	
	cout << "Hasil pemeriksaan covid 19 berdasarkan gejala pasien\n\n";
	
	cout << "No\tNama\tHasil\n";
	makeLine(20);
	for (int i = 0; i<n; i++) {
		cout << (i+1) << '\t' << names[i] << '\t' << results[i] << '\n';
	}
	
	cout << "\nSemoga cepat sembuh!";
	getch();
}
