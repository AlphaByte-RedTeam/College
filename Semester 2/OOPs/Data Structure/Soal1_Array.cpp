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
    double M = 5;

    double projectionXp( double &X, double &Y, double &Z )
    {
        double Xp = round( X / (1 - (Z / M)) );
        
        return Xp;
    }

    double projectionYp( double &X, double &Y, double &Z )
    {
        double Yp = round( Y / (1 - (Z / M)) );

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
    Coordinates arr[8];
    Coordinates coordinate;
    double pXp;
    double pYp;
    
    for ( int i = 0; i < 8; i++ )
    {
        printf( "Masukkan titik koordinat P%d\n", i );
        printf( ">> " );
        //scanf( "%.0lf %.0lf %.0lf", &arr[i].X, &arr[i].Y, &arr[i].Z );
        cin >> arr[i].X >> arr[i].Y >> arr[i].Z;
        pXp = coordinate.projectionXp( arr[i].X, arr[i].Y, arr[i].Z );
        pYp = coordinate.projectionYp( arr[i].X, arr[i].Y, arr[i].Z );
        //printf( "%.0lf %.0lf %.0lf\n", arr[i].X, arr[i].Y, arr[i].Z );
    }
    
    printf( "\n" );
    printf( "M = %.0lf\n", coordinate.M );
    printf( "\tX\tY\tZ\tXp\tYp\n" );
    line( 45 );
    
    for ( int i = 0; i < 8; i++ )
    {
        printf( "\t%.0lf\t%.0lf\t%.0lf\t%.0lf\t%.0lf\n", arr[i].X, arr[i].Y, arr[i].Z, pXp, pYp );
    }
    
    return 0;
}