/*
Soal 2 – Array 2 Dimensi: 

Buatlah program yang dapat menyimpan 25 data input ke sebuah matriks berukuran 5 x 5 . lakukan
proses perkalian matriks tersebut dengan matriks sbb:

1 0 0 0 0
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
*/

#include <iostream>

void line( int length )
{
    for ( int i = 0; i < length; i++ )
    {
        printf( "=" );
    }

    printf( "\n" );
}

int main()
{
    const int rows = 5;
    const int columns = 5;
    int len = 25;
    
    int givenArr[rows][columns] = { {1, 0, 0, 0, 0},
                                    {0, 1, 0, 0, 0},
                                    {0, 0, 1, 0, 0},
                                    {0, 0, 0, 1, 0},
                                    {0, 0, 0, 0, 1} };
    int inputArr[rows][columns];
    int result[rows][columns] = {0};

    // Input Matrix
    for ( int i = 0; i < rows; i++ )
    {
        for ( int j = 0; j < columns; j++ )
        {
            printf( "Input Array[%d][%d] = ", i, j );
            scanf( "%d", &inputArr[i][j] );
        }
    }

    // Multiplication Matrix
    for ( int i = 0; i < rows; i++ )
    {
        for ( int j = 0; j < columns; j++ )
        {
            for ( int k = 0; k < 5; k++)
            {
                result[i][j] += inputArr[i][k] * givenArr[k][j];
            }
        }
    }

    line( len );

    // Result of Multiplication Matrix
    printf( "Hasil perkalian matrix\n" );
    line( len );

    for ( int i = 0; i < rows; i++ )
    {
        for ( int j = 0; j < columns; j++ )
        {
            printf( "%d ", result[i][j] );
        }
        printf( "\n" );
    }

    return 0;
}