#include <stdlib.h>
#include <stdio.h>

int static compare1(const void* first, const void* second){
    if(*(int*)first > *(int*)second)
        return 1;
    else if(*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
int static compare2(const void* first, const void* second){
    if(*(int*)first < *(int*)second)
        return 1;
    else if(*(int*)first > *(int*)second)
        return -1;
    else
        return 0;
}
int main(){
    int a[5] = {8, 2, 5, 4, 7};
    int b[5] = {8, 2, 5, 4, 7};
    int a_len = 5, b_len = 5;
    
    qsort(a,a_len,sizeof(int),compare1);
    qsort(b,b_len,sizeof(int),compare2);
    
    for(int i = 0; i < a_len; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < b_len; i++){
        printf("%d ", b[i]);
    }
    return 0;
}

