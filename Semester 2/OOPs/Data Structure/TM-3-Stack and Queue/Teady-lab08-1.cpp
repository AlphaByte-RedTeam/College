#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Record Definition
struct TheCell
{
  int dat;
  struct TheCell *berikut;
};

struct TheCell *ptrCell=NULL;
struct TheCell *kepala=NULL;

void push(int isi)
{
  struct TheCell *baru;
  baru=(struct TheCell *) malloc(sizeof(struct TheCell));
  if (kepala!=NULL) //untuk mengecek stack kosong atau tidak. atau bisa juga pakai isEmpty()
  {  //kalau tidak kosong, baru-> diarahkan ke kepala
    baru->berikut = kepala;
  }
  else
  {
    baru->berikut = NULL;
  }
  kepala = baru;
  kepala->dat = isi;
}

int top()
{
  return(kepala->dat);
}


int pop()
{
  if (kepala!=NULL)
  {
    int getData;
    getData = kepala->dat;
    ptrCell = kepala;
    kepala = kepala->berikut;
    free(ptrCell);
    return(getData);
  }
  else
  {
    return(NULL);
  }
}

bool isEmpty()
{
  if (kepala==NULL)
    return(true); //Berarti benar kosong
  else
    return(false); //Berarti bukan kosong
}

//program utama
int main()
{
  //deklarasi variable
  int i; int bilRandom;
  //pengisian bilangan random ke dalam stack
  for (i=1;i<=10;i++)
  {
    bilRandom = rand();
    push(bilRandom);
  }

  //PERHATIAN BLOCK YANG INI BUKAN MERUPAKAN OPERASI STACK
  //HANYA MENCOCOKKAN DATA2 YG AKAN DI POP()
  //Menampilkan semua Isi Stack dari awal sampai akhir berikut dengan alamat pointernya
  if (kepala!=NULL)  //Memastikan Linked List tidak kosong, yg ditandai dengan kepala != NULL
  {
    cout<<"Kepala: "<<kepala<<endl;
    cout<<"[ {cell: Alamat  }   Data | berikut ]"<<endl;
    //Arahkan ptrCell ke alamat yang ditunjuk oleh kepala
    ptrCell = kepala;
    do
    {
      //Tampilkan isi Node / Simpul
      cout<<"[ {cell: "<<ptrCell<<"} "<<setiosflags(ios::right)<<setw(6)<<ptrCell->dat;
      cout<<" | "<<ptrCell->berikut<<"]"<<endl;
      //Arahkan ptrCell ke Node/Simpul berikutnya
      ptrCell = ptrCell->berikut;
    }while (ptrCell != NULL); //keluar dari loop ketika ptrCell menunjukkan alamat ekor
    cout<<endl;
  }
  
  //Mengeluarkan isi stack dengan pop() dan memeriksa kekosongan stack dengan isEmpty()
  while(!isEmpty())
  {
    cout<<pop()<<endl;
  }
  getch();
}