#include <iostream>
#include <conio.h>
using namespace std;

/*
The idea is creating a Node object, and then creating a Singly Linked-List
object, and then using those Singly Linked-List object to link all the node.
*/

class Node
{
    public:
        int key;    // Making one node is unique from other node using unique key.
        int data;   // Contains the information store in the node.
        Node *next; // A pointer which point to an object of next in the node class only.

        /* Node Constructor */
        Node()
        {  
            // Default constructor
            key = 0;
            data = 0;
            next = NULL;
        }

        Node( int k, int d )
        {
            key = k;
            data = d;
        }
};

class SinglyLinkedList
{
    public:
        // Instantiate Node class
        Node *head;

        // Default constructor
        SinglyLinkedList()
        {
            head = NULL;
        }

        // Passing by address        
        SinglyLinkedList( Node *n )
        {
            head = n;
        }

        // Checking particular Node if it exist or not using key value
        Node *nodeExist( int k )
        {
            // Traversing linked List
            Node *temp = NULL;

            Node *ptr = head;
            while ( ptr != NULL )
            {
                if ( ptr->key == k )
                {
                    temp = ptr;
                }
                ptr = ptr->next;   
            }
            return temp;
        }

        // Append a node to the list
        // Appending will always happen at the end of the list
        void appendNode( Node *n )
        {
            if ( nodeExist(n->key) != NULL )
            {
                printf( "Node already exist with key value %d\n", n->key );
                printf( "Append another node with different key value\n" );
            }

            else
            {
                if ( head == NULL )
                {
                    head = n;
                    printf( "Node appended\n\n" );
                }
                
                else
                {
                    Node *ptr = head;
                    while ( ptr->next != NULL )
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    printf( "Node appended\n" );
                }
            }
        }

        // Prepend Node:
        // Prepend node attach a node at the start
        void prependNode( Node *n )
        {
            if ( nodeExist( n->key ) != NULL )
            {
                printf( "Node already exist with key value %d\n", n->key );
                printf( "Append another node with different key value\n" );
            }
            
            else
            {
                n->next = head;
                head = n;
                printf( "Node prepended\n" );
            }
        }

        // Insert Node after a particular node in the List
        void insertNodeAfter( int k, Node *n )
        {
            Node *ptr = nodeExist( k );
            if ( ptr == NULL )
            {
                printf( "No node exist with key value: %d\n", k );
            }

            else
            {
                if ( nodeExist( n->key ) != NULL )
                {
                    printf( "Node already exist with key value %d\n", n->key );
                }

                else
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    printf( "Node inserted\n" );
                }
            }
        }

        // Delete Node by key
        void deleteNodeByKey( int k )
        {
            if ( head == NULL )
            {
                printf( "Singly Linked List already empty, cannot delete\n" );
            }

            else if ( head != NULL )
            {
                if ( head->key == k )
                {
                    head = head->next;
                    printf( "Node unlinked with keys value: %d\n" );
                }

                else
                {
                    Node *temp = NULL;
                    Node *previousPtr = head;
                    Node *currentPtr = head->next;

                    while ( currentPtr != NULL )
                    {
                        if ( currentPtr->key == k )
                        {
                            temp = currentPtr;
                            currentPtr = NULL;
                        }

                        else
                        {
                            previousPtr = previousPtr->next;
                            currentPtr = currentPtr->next;
                        }                        
                    }

                    if ( temp != NULL )
                    {
                        previousPtr->next = temp->next;
                        printf( "Node unlinked with keys value: %d\n", k );
                    }
                    
                    else
                    {
                        printf( "Node doesn't exist with key value: %d\n", k );
                    }
                }
            }            
        }

        // Update Node
        void updateNodeByKey( int k, int d )
        {
            Node *ptr = nodeExist( k );
            if ( ptr != NULL )
            {
                ptr->data = d;
                printf( "Node data updated successfully\n" );
            }

            else
            {
                printf( "Node doesn't exist with key value: %d\n", k );
            }
        }

        // Printing List
        void printList()
        {
            if ( head == NULL )
            {
                printf( "No nodes in singly linked list\n" );
            }

            else
            {
                printf( "\nSingly Linked List Values: " );
                Node *temp = head;

                while ( temp != NULL )
                {
                    cout << "(" << temp->key << ", " << temp->data << ") --> \n";
                    temp = temp->next;
                }
            }
        }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1;
    int k1;
    int data1;

    int a[4][5] = { {12, 35, 41, 23, 22},
                    {10, 99, 21, 50, 40},
                    {39, 48, 24, 11, 66},
                    {51, 55, 44, 33, 22} };
    //soal no.2
    int *b[4][5] = { {&a[0][0], &a[1][0], &a[2][0], &a[3][0], &a[4][0]},
                     {&a[0][1], &a[1][1], &a[2][1], &a[3][1], &a[4][1]},
                     {&a[0][2], &a[1][2], &a[2][2], &a[3][2], &a[4][2]},
                     {&a[0][3], &a[1][3], &a[2][3], &a[3][3], &a[4][3]} };

//soal no.1
    for ( int i = 0; i < 4; i++ )
    {
        for ( int j = 0; j < 5; j++ )
        {
            cout << "{"<< a[i][j] << "}, \n";
        }
    }

    do{
        printf( "1. Tampilkan alamat array B\n" );
        printf( "2. Tampilkan Linked List\n" );
        printf( "3. Tampilkan Double Linked List\n" );
        printf( "\nPilih operasi yang diinginkan!\n" );
        printf( "\n>> " );
        scanf( "%d", &option );

        Node *n1 = new Node();

        switch ( option )
        {
            case 1:
                for ( int i = 0; i < 4; i++ )
                {
                    for ( int j = 0; j < 5; j++ )
                    {
                        cout << "{" << b[i][j] << "}, \n";
                    }
                }
                break;

            case 2:
                break;
            
            case 3:
                break;
            
            case 0:
                break;
            
            default:
                break;
        }
    } while( option != 0 );

    do
    {
        printf( "\n" );
        printf( "1. Append Node\n" );
        printf( "2. Prepend Node\n" );
        printf( "3. Insert Node\n" );
        printf( "4. Delete Node\n" );
        printf( "5. Update Node\n" );
        printf( "6. Print\n" );
        printf( "7. Clear Screen\n" );
        printf( "0. Exit\n" );
        printf( "\nSelect operation you want to perform\n" );
        printf( ">> " );

        scanf( "%d", &option );
        Node *n1 = new Node();
        //Node n1;

        switch ( option )
        {
            case 0:
                break;
            
            case 1:
                printf( "Append Node Operation\n" );
                printf( "Enter key: " );
                scanf( "%d", &key1 );
                printf( "Enter data: " );
                scanf( "%d", &data1 );
                n1->key = key1;
                n1->data = data1;
                s.appendNode(n1);
                //printf( "%d = %d\n", n1.key, n1.data );
                break;
            
            case 2:
                printf( "Prepend Node Operation\n" );
                printf( "Enter key: " );
                scanf( "%d", &key1 );
                printf( "Enter data: " );
                scanf( "%d", &data1 );
                n1->key = key1;
                n1->data = data1;
                s.prependNode( n1 );
                break;

            case 3:
                printf( "Insert Node Operation\n" );
                printf( "Enter key: " );
                scanf( "%d", &key1 );
                printf( "Enter data: " );
                scanf( "%d", &data1 );
                n1->key = key1;
                n1->data = data1;
                s.insertNodeAfter( k1, n1 );
                break;

            case 4:
                printf( "Delete Node Key Operation\n" );
                printf( "Enter key to be deleted: " );
                scanf( "%d", &key1 );
                s.deleteNodeByKey( k1 );
                break;

            case 5:
                printf( "Update Node Key Operation\n" );
                printf( "Enter key: " );
                scanf( "%d", &key1 );
                printf( "Enter data: " );
                scanf( "%d", &data1 );
                s.updateNodeByKey( key1, data1 );
                break;

            case 6:
                s.printList();
                break;
            
            case 7:
                system( "cls" );
                break;

            default:
                printf( "Enter proper option number!\n" );
        }
    } while( option != 0 );
    
    return 0;
}