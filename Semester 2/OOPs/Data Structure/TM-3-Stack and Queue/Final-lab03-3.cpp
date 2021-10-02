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
Node* head = NULL;
Node* tail = NULL;
Node* temp;

void enqueue( int num )
{
    Node* queries = (Node*)malloc(sizeof(Node));
    queries->data = num;

    if ( tail == NULL )
    {
        tail = queries;
        tail->next = NULL;
        head = tail;
    }

    else
    {
        tail->next = queries;
        queries->next = NULL;
        tail = queries;
    }
}

void display()
{
    if ( head == NULL && tail == NULL )
    {
        printf( "Queue is empty!!\n" );
        return;
    }
    temp = head;

    while ( temp != NULL )
    {
        cout << "[ {cell: " << temp << "} " << setiosflags(ios::right) << setw(6) << temp->data << " | " << temp->next << "]\n";
        temp = temp->next;
    }
    printf( "\n" );
}

void dequeue()
{
    if ( head == NULL )
    {
        printf( "Cannot dequeue!!\n" );
        return;
    }
    temp = head;
    
    if ( temp->next != NULL )
    {
        temp = temp->next;
        cout << head->data << "\n";
        free( head );
        head = temp;
    }

    else
    {
        cout << head->data << "\n";
        free( head );
        head = NULL;
        tail = NULL;
    }
}

void dequeueAll()
{
    while ( head != NULL )
        dequeue();
}

int main()
{
    srand(time(0));
    
    for ( int i = 0; i < 10; i++ )
    {
        int randomNumber = rand() % 100 + 1;
        enqueue( randomNumber );
    }

    cout << "Kepala: " << head << "\n";
    cout << "[ {cell: Alamat  }   Data | berikut ]\n";

    display();
    dequeueAll();

    return 0;
}