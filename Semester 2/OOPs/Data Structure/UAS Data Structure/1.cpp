#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode( int data )
{
    Node* node = (Node*) malloc( sizeof(Node) );
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* addLevelOrder( int arr[], Node* root, int i, int n )
{
    if ( i < n )
    {
        Node* temp = newNode( arr[i] );
        root = temp;

        root->left = addLevelOrder( arr, root->left, (2 * i) + 1, n );
        root->right = addLevelOrder( arr, root->right, (2 * i) + 2, n );
    }

    return root;
}

void inOrder( Node* root )
{
    if ( root != NULL )
    {
        inOrder( root->left );
        printf( "%d ", root->data );
        inOrder( root->right );
    }
}

int main()
{
    int a[20] = { 12, 35, 41, 23, 22, 10, 99, 21, 50, 40, 
                  39, 48, 24, 11, 66, 51, 55, 44, 33, 22 };
    int n = sizeof(a) / sizeof( a[0] );
    Node* root = addLevelOrder( a, root, 0, n );
    printf( "\n" );
    inOrder( root );
    printf( "\n" );

    return 0;
}