#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* previous;
};
Node* head = NULL;
Node* tail = NULL;
Node* ptr = NULL;

void newNode( int n )
{
    Node* ptr = (Node*)malloc(sizeof(Node));

    ptr->data = n;
    ptr-> next = NULL;

    if ( head == NULL )
    {
        head = ptr;
        tail = ptr;
    }

    else
    {
        tail->next = ptr;
        tail = ptr;
    }
}

int main()
{
    int option;
    int a[4][5] = { {12, 35, 41, 23, 22},
                    {10, 99, 21, 50, 40},
                    {39, 48, 24, 11, 66},
                    {51, 55, 44, 33, 22} };
    //soal no.2
    int *b[4][5] = { {&a[0][0], &a[1][0], &a[2][0], &a[3][0], &a[4][0]},
                     {&a[0][1], &a[1][1], &a[2][1], &a[3][1], &a[4][1]},
                     {&a[0][2], &a[1][2], &a[2][2], &a[3][2], &a[4][2]},
                     {&a[0][3], &a[1][3], &a[2][3], &a[3][3], &a[4][3]} };

    cout << "\n\n";

//soal no.1
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
                for ( int i = 0; i < 4; i++ )
                {
                    for ( int j = 0; j < 5; j++ )
                    {
                        cout << "{" << b[i][j] << "}, ";
                    }
                }
                break;

            case 2:
                for ( int i = 0; i < 4; i++ )
                {
                    for ( int j = 0; j < 5; j++ )
                    {
                        cout << &a[i][j] << "->" << a[i][j] << "->" << b[i][j] << "\n";
                    }
                }
                break;
            
            case 3:
                for ( int i = 0; i < 4; i++ )
                {
                    for ( int j = 0; j < 5; j++ )
                    {
                        cout << &a << ", ";
                    }
                }
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