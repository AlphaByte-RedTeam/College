#include <iostream>
using namespace std;

#define MAX 100

struct Stack
{
    int top;
    int a[MAX];

    Stack() { top = -1; }
    bool push( int x );
    int pop();
    bool isEmpty();
};