#include <iostream>
#include <stdlib.h>

int main()
{
    short option;
    int value;

    do
    {
        system( "CLS" );
        printf( "Menu\n" );
        printf( "1. Tambah data ke tree\n" );
        printf( "2. Cari data\n" );
        printf( "3. Hapus data dari tree - deletion by Merging\n" );
        printf( "4. Hapus data dari tree - deletion by Copying\n" );
        printf( "5. Pre-order traversal\n" );
        printf( "6. Post-order traversal\n" );
        printf( "7. In-order traversal\n" );
        printf( "8. Level-order traversal\n" );
        printf( "9. Delete Leaf\n" );
        printf( "10. Hapus Node dengan satu anak\n" );
        printf( "11. Find Predecessor\n" );
        printf( "0. Keluar\n\n" );

        printf( "Pilihan anda : " );
        scanf( "%d", &option );

        system( "PAUSE" );
    } while ( option != 0 );

    return 0;
}