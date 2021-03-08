#include <iostream>
#include <cstring>
using std::cout;

struct TheCell
{
    char name[10];
    int age;
};

struct TheCell DataMhs[250];

int main()
{
    strcpy( DataMhs[1].name, "Andrew" );
    DataMhs[1].age = 19;

    printf( "%s\n", DataMhs[1].name );
    printf( "%d\n", DataMhs[1].age );
}