#include <iostream>
#include <stdlib.h>

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

Node* binarySearchTree( Node* node, int value )
{
    if ( node == NULL || node->data == value )
        return node;
    
    else if ( value < node->data )
    {
        printf( "data %d pergi ke kiri\n", node->left->data );
        return binarySearchTree( node->left, value );
    }
    
    else if ( value > node->data )
    {
        printf( "data %d pergi ke kanan\n", node->right->data );
        return binarySearchTree( node->right, value );
    }
}

Node* findPredeccessor( Node* node )
{
    if ( node->right == NULL )
        return node;
    
    return findPredeccessor( node->right );
}

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

Node* deleteByMerging( Node* node, int value )
{
    if ( node == NULL )
    {
        printf( "Data tidak ada!!\n\n" );
        return node;
    }

    else if ( value < node->data )
        node->left = deleteByMerging( node->left, value );
    
    else if ( value > node->data )
        node->right = deleteByMerging( node->right, value );
    
    else
    {
        if ( node->left == NULL && node->right == NULL )
        {
            node = NULL;
            free( node );
        }

        else if ( node->left != NULL && node->right == NULL )
        {
            Node* temp = node->left;
            free( node );
            return temp;
        }

        else if ( node->left == NULL && node->right != NULL )
        {
            Node* temp = node->right;
            free( node );
            return temp;
        }

        else if ( node->left != NULL && node->right != NULL )
        {
            Node* temp = findPredeccessor( node->left );
            temp->right = node->right;
            temp = node;
            node = node->left;
            free( temp );
        }
    }

    return node;
}

void preOrder( Node* node )
{
    if ( node == NULL )
        return;
    
    // Algorithm of preOrder: VLR
    printf( "%d ", node->data );  // visit
    preOrder( node->left );       // left node
    preOrder( node->right );      // right node
}

void postOrder( Node* node )
{
    if ( node == NULL )
        return;
    
    // Algorithm of postOrder: LRV
    postOrder( node->left );      // Left Node
    postOrder( node->right );     // Right Node
    printf( "%d ", node->data );  // visit
}

void inOrder( Node* node )
{
    if ( node == NULL )
        return;

    // Algorithm of inOrder Traversal: LVR
    inOrder( node->left );        // Left Node
    printf( "%d ", node->data );  // visit
    inOrder( node->right );       // Right Node
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
                printf( "Terima kasih telah menggunakan program ini!\n" );
                exit(0);
                break;

            case 1:
            {
                // Input data: 50 25 75 10 35 60 85 5 15 30 40 55 65 80 90
                int x;
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

            case 2:
            {
                int x;
                printf( "Data yang dicari : " );
                scanf( "%d", &x );
                Node* search = binarySearchTree( root, x );

                if ( search == NULL )
                    printf( "Data %d tidak ada!!\n\n", x );
                
                else
                {
                    if ( search == root )
                        printf( "Data %d ditemukan pada root\n\n", x );

                    else
                        printf( "%d ditemukan!!\nParent: %d\n\n", search->data, search->parent->data );
                }

                break;
            }

            case 5:
                printf( "Pre Order Traversal: " );
                preOrder( root );
                printf( "\n\n" );
                break;

            case 6:
                printf( "Post Order Traversal: " );
                postOrder( root );
                printf( "\n\n" );
                break;

            case 7:
                printf( "In Order Traversal: " );
                inOrder( root );
                printf( "\n\n" );
                break;

            default:
                break;
        }

        system( "PAUSE" );
    } while ( option != 0 );

    return 0;
}