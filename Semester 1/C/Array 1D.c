#include <stdio.h>
//#include <iostream>

void main(){
    int a;
    int b[4];
    for (a=0;a<4;a++){
        printf("Masukkan nilai B[%d] : " ,a);
        scanf("%d", &b[a]);
    }
    for (a=0;a<4;a++){
        printf("\n Nilai B [%d] adalah : %d",a,b[a]);
    }
    getch();
}