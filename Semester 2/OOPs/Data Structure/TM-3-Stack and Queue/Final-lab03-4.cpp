#include <iostream>
#include <cstdlib>
#include <ios>
#include <iomanip>
using namespace std;

int queue[1000];
int queueSize = 1000;
int head = -1;
int tail = -1;

void enqueue( int num )
{
    if ( tail == head-1 || (head == 0 && tail == queueSize-1) )
        printf( "Queue overflow!!\n" );

    else
    {
        if ( head == -1 )
            head = 0;
        tail++;
        
        if ( tail == queueSize )
            tail = -1;
        
        queue[tail] = num;
    }
}

void display()
{
    if ( head == -1 )
    {
        printf( "Queue is empty!!\n" );
        return;
    }

    for ( int i = head; i <= tail; i++ )
        printf( "Enqueue element: %d\n", queue[i] );
    
    printf( "\n" );
}

void dequeue()
{
    if ( head == -1 || head == tail+1 )
        printf( "Queue underflow!!\n" );
    
    else
    {
        printf( "Dequeued elements: %d\n", queue[head] );
        head++;

        if ( head == tail+1 )
        {
            head = -1;
            tail = -1;
        }
    }
}

void dequeueAll()
{
    while ( head >= 0 )
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

    display();
    dequeueAll();

    return 0;
}