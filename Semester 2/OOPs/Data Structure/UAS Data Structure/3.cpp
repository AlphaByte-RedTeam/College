#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

struct Stack
{
    int data;
    Node* next;
};  Node* top = NULL;

void push( int* num )
{
    Stack* cell = (Stack*)malloc(sizeof(Stack));
    cell->data = num;
    cell->next = top;
    top = cell;
}

Node* postOrder( Node* node )
{
    if ( node == NULL )
        return;
    
    postOrder( node->left );
    postOrder( node->right );
    printf( "%d ", node->data );
    push( node->data );
}

int main()
{  
    int a[20] = { 12, 35, 41, 23, 22, 10, 99, 21, 50, 40, 
                  39, 48, 24, 11, 66, 51, 55, 44, 33, 22 };
    
    Node* root = postOrder( a );

    return 0;
}