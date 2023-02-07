#include <stdlib.h>
#include <stdio.h>

int main()
{
    int num;
    printf("pls write some digit to make a array..! : ");
    scanf("%d", &num);
    int *p = (int*)malloc(sizeof(int)*num); //동적메모리할당
    for(int i = 0; i < num; i++){
        p[i]= i+1;
    }
    for(int j = 0; j < num; j++){
        printf("%d ",p[j]);
    }
    printf("\n");
    free(p); //동적메모리해제
    return 0;
}