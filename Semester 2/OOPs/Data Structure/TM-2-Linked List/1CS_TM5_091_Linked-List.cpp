#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Node
{
    char name[100];
    Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* ptr = NULL;

void newNode( char n[100] )
{
    Node* ptr = (Node*)malloc(sizeof(struct Node));
    
    //ptr->name = n;
    strcpy( ptr->name, n );
    ptr->next = NULL;

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

void appendNode( char n[100] )
{
    Node* ptr = (Node*)malloc(sizeof(struct Node));
    //ptr->name = n;
    strcpy( ptr->name, n );
    ptr->next = NULL;

    tail->next = ptr;
    tail = ptr;
}

void printLinkedList()
{
    Node* ptr = head;
    Node* temp;

    while ( ptr != NULL )
    {
        cout << "[" << ptr->name << "] --> alamat Ptr " << ptr << " --> Next ptr " << ptr->next << "\n";
        temp = ptr->next;
        ptr = temp;
    }
}

void searchData( char* find )
{
    Node* ptr = head;

    while ( strcmp(ptr->name, find) == 0 )
    {
        ptr = ptr->next;

        if ( ptr == NULL )
        {
            printf( "Data tidak ditemukan!" );
        }
    }

    cout << "Data " << ptr->name << " is found at address " << ptr << "\n";
}

int main()
{
    char data[100];
    char findData[100];

    printf( "--SOAL 1--\n" );
    printf( "Entry Serial Data\n\n" );
      
    int i = 0;
    do
    {
        printf( "Data Ke %d: ", ++i );
        cin.getline( data, 100 );

        if( strlen( data ) > 0 )
        {
            newNode( data );
        }

    } while ( strlen( data ) > 0 );
      

    printf( "\nJumlah data %d\n\n", (i-1) );

    if ( head != NULL )
    {
        ptr = head;
        ptr = tail;

        printf( "Hasil Entry Data:\n" );

        int i = 0;
        do
        {
            ++i;
            printLinkedList();
        } while( ptr->next != NULL );          
    }

    do
    {
        printf( "\nData yang anda cari: " );
        gets( findData );

        if ( strlen(findData) > 0 )
        {
            searchData( findData );
        }
    } while ( strlen( data ) > 0 );
    
    return 0;
}