#include <iostream>
using namespace std;

int main()
{
    int option;
    int a[4][5] = { {12, 35, 41, 23, 22},
                    {10, 99, 21, 50, 40},
                    {39, 48, 24, 11, 66},
                    {51, 55, 44, 33, 22} };

    printf( "\n\n" );
    
    for ( int i = 0; i < 4; i++ )
    {
        for ( int j = 0; j < 5; j++ )
        {
            cout << "{"<< a[i][j] << "}, ";
        }
    }

    do{
        printf( "\n" );
        printf( "1. Tampilkan alamat array B\n" );
        printf( "2. Tampilkan Linked List\n" );
        printf( "3. Tampilkan Double Linked List\n" );
        printf( "0. Exit" );
        printf( "\n\n--Pilih operasi yang diinginkan!--\n" );
        printf( "\n>> " );
        scanf( "%d", &option );

        switch ( option )
        {
            case 1:
                break;

            case 2:
                break;
            
            case 3:
                break;
            
            case 0:
                break;
            
            default:
                printf( "Input Kode Tidak Benar!" );
                break;
        }
    } while( option != 0 );

    return 0;
}