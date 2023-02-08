#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // stdlib.h에 qsort 있음
int static compare1 (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
int compare2(const int *A, const int *B){ //내림차순용
    return *A < *B;
}
int main(){
    int A[5] = {8,5,7,2,1};
    int B[5] = {8,5,7,2,1};
    int A_len = 5;
    int B_len = 5;
    //정렬할 배열과, 길이, 원소당 크기, 비교함수를 넣어주면 된다.
    qsort(A,A_len,sizeof(int),compare1);
    qsort(B,B_len,sizeof(int),compare2);
    for(int i = 0; i < A_len; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    for(int i = 0; i < B_len; i++){
        printf("%d ", B[i]);
    }
    printf("\n");
    
    return 0;
}
