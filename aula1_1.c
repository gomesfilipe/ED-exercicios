#include <stdio.h>
#include <stdlib.h>

int main(){
    int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
    int *p1, *p2, *p3, *p4;
    
    printf("Valores iniciais e enredecos das variaveis:\n");
    printf("a1 = %d | &a1 = %p\n", a1, &a1);
    printf("a2 = %d | &a2 = %p\n", a2, &a2);
    printf("a3 = %d | &a3 = %p\n", a3, &a3);
    printf("a4 = %d | &a4 = %p\n\n", a4, &a4);
    
    p1 = &a1;
    p2 = &a2;
    p3 = &a3;
    p4 = &a4;
    
    printf("Para onde apontam os ponteiros:\n");
    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    printf("p3 = %p\n", p3);
    printf("p4 = %p\n\n", p4);

    *p1 = 5;
    *p2 = 6;
    *p3 = 7;
    *p4 = 8;

    printf("Novos valores das variaveis apos serem atualizadas via ponteiros:\n");
    printf("a1 = %d\n", a1);
    printf("a2 = %d\n", a2);
    printf("a3 = %d\n", a3);
    printf("a4 = %d\n\n", a4);

    return 0;
}