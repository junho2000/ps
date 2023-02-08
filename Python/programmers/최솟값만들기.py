def solution(A,B):
    answer = 0
    A.sort()
    B.sort(reverse=True)
    for i in range(len(A)):
        answer += A[i] * B[i]
    return answer


#for C

##include <stdio.h>
##include <stdbool.h>
##include <stdlib.h>
#int compare1(const int *A, const int *B){
#    return *A > *B;
#}
#int compare2(const int *A, const int *B){
#    return *A < *B;
#}
#// A_len은 배열 A의 길이입니다.
#// B_len은 배열 B의 길이입니다.
#int solution(int A[], size_t A_len, int B[], size_t B_len) {
#    int answer = 0;
#    qsort(A,A_len,sizeof(int),compare1);
#    qsort(B,B_len,sizeof(int),compare2);
#    for(int i = 0; i < A_len; i++){
#        answer += A[i] * B[i];
#    }
#    //정렬할 배열과, 길이, 원소당 크기, 비교함수를 넣어주면 된다.
#    return answer;
#}
