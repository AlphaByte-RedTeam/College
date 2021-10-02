#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;
    Node* parent;

    Node( int val )
    {
        this->data = val;
        left = right = parent = NULL;
        height = 1;
    }
};

Node* addData( Node* node, int value, Node* parent )
{
    if ( node == NULL )
    {
        Node* newNode = new Node( value );
        if ( parent == NULL )
            newNode->parent = NULL;
        
        else
            newNode->parent = parent;
        
        return newNode;
    }

    if ( value < node->data )
        node->left = addData( node->left, value, node );
    
    else if ( value > node->data )
        node->right = addData( node->right, value, node );
    
    else
    {
        printf( "Data cannot be duplicated!!\n" );
        return node;
    }

    return node;  
}

int main()
{
    short option;
    Node* root = NULL;

    do
    {
        system( "CLS" );
        printf( "Menu\n" );
        printf( "1. Tambah data ke tree\n" );
        printf( "2. Cari data\n" );
        printf( "3. Hapus data dari tree - deletion by Merging\n" );
        printf( "4. Hapus data dari tree - deletion by Copying\n" );
        printf( "5. Pre-order traversal\n" );
        printf( "6. Post-order traversal\n" );
        printf( "7. In-order traversal\n" );
        printf( "8. Level-order traversal\n" );
        printf( "9. Delete Leaf\n" );
        printf( "10. Hapus Node dengan satu anak\n" );
        printf( "11. Find Predecessor\n" );
        printf( "0. Keluar\n\n" );

        printf( "Pilihan anda : " );
        scanf( "%d", &option );

        int i = 0;
        switch ( option )
        {
            case 0:
                exit(0);
                break;

            case 1:
                int x;
                // Input data: 50 25 75 10 35 60 85 5 15 30 40 55 65 80 90
                printf( "Input Data, untuk mengakhiri, tekan 0\n\n" );
                do
                {
                    printf( "Input data ke %d : ", ++i );
                    scanf( "%d", &x );
                    root = addData( root, x, NULL );
                } while( x > 0 );
                printf( "\nProses input data selesai!\n" );
                break;
        }

        system( "PAUSE" );
    } while ( option != 0 );

    return 0;
}