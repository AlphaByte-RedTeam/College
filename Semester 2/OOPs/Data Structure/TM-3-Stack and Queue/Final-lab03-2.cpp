#include <iostream>
#include <cstdlib>
#include <ios>
#include <iomanip>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* top = NULL;

void pushAndSort( int num )
{
    Node* cell = (Node*)malloc(sizeof(Node));

    cell->data = num;
    
    if ( top == NULL || cell->data < top->data )
    {
        cell->next = top;
        top = cell;
    }

    else
    {
        Node* prev = top;

        while ( true )
        {
            Node* ptr = prev->next;

            if ( ptr == NULL || cell->data < ptr->data )
            {
                prev->next = cell;
                cell->next = ptr;
                break;
            }

            else
            {
                prev = ptr;
            }
        }
    }
}

void display()
{
    Node* ptr;

    if ( top == NULL )
        printf( "Stack is empty!!\n" );

    else
    {
        ptr = top;
        
        while ( ptr != NULL )
        {
            printf( "%d\n", ptr->data );
            ptr = ptr->next;
        }
        printf( "\n" );
    }
}

int main()
{
    srand(time(0));
    
    for ( int i = 0; i < 10; i++ )
    {
        int randomNumber = rand() % 100 + 1;
        pushAndSort( randomNumber );
    }

    printf( "\n" );
    display();

    return 0;
}