/*
Soal 1 - Array 1 Dimensi

Buatlah sebuah record yang berisi field koordinat X, Y, Z yang bertipe data integer.
Deklarasikan sebuah array 1 dimensi dengan ukuran array 8 menggunakan record ersebut.
Buatlah program untuk mengisi masing-masing koordinat tersebut dengan titik-titik koordinat sbb:
P0(0,0,0), P1(20,0,0), P2(20,0,20), P3(0,0,20), P4(0,20,0), P5(20,20,0), P6(20,20,20), P7(0,20,20)
Buatlah output untuk menampilkan proyeksi Xp dan Yp untuk masing-masing koordinat tersebut dengan
M = 5
Rumus proyeksi adalah sbb:
Xp := round(X / (1 – (Z / M)));
Yp := round(Y / (1 – (Z / M)));
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Coordinates
{

public:
    double X;
    double Y;
    double Z;

    int projectionXp( double &M )
    {
        int Xp =  round( X / (1 - (Z / M)) );
        
        return Xp;
    }

    int projectionYp( double &M )
    {
        int Yp = round( Y / (1 - (Z / M)) );

        return Yp;
    }
};

void line( int length )
{
    for (int i = 0; i < length; i++ )
    {
        printf( "=" );
    }
    printf( "\n" );
}

int main()
{
    double M = 5;
    Coordinates arr[8];
        
    for ( int i = 0; i < 8; i++ )
    {
        printf( "Masukkan titik koordinat P%d\n", i );
        printf( ">> " );
        scanf( "%lf %lf %lf", &arr[i].X, &arr[i].Y, &arr[i].Z );
    }
    
    printf( "\n" );
    printf( "M = %.0lf\n", M );
    printf( "\tX\tY\tZ\tXp\tYp\n" );
    line( 45 );
    
    for ( int i = 0; i < 8; i++ )
    {
        printf( "\t%.0lf\t%.0lf\t%.0lf\t%d\t%d\n", arr[i].X, arr[i].Y, arr[i].Z, arr[i].projectionXp(M), arr[i].projectionYp(M) );
    }
    
    return 0;
}