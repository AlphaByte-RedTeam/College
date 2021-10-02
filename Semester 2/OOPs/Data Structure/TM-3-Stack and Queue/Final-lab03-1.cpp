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

void push( int num )
{
    Node* cell = (Node*)malloc(sizeof(Node));

    cell->data = num;
    cell->next = top;

    top = cell;
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
            cout << "[ {cell: " << ptr << "} " << setiosflags(ios::right) << setw(6) << ptr->data << " | " << ptr->next << "]\n";
            ptr = ptr->next;
        }
        printf( "\n" );
    }
}

void pop()
{
    if ( top == NULL )
        printf ( "Stack underflow!!\n" );
    
    else
    {
        cout << top->data << "\n";
        top = top->next;
    }
}

void popAll()
{
    while ( top != NULL )
        pop();
}

int main()
{
    srand(time(0));
    
    for ( int i = 0; i < 10; i++ )
    {
        int randomNumber = rand() % 100 + 1;
        push( randomNumber );
    }

    cout << "Kepala: " << top << "\n";
    cout << "[ {cell: Alamat  }   Data | berikut ]\n";

    display();
    popAll();

    return 0;
}