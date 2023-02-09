# permutations 라이브러리 사용
from itertools import permutations
def solution(numbers):
    prime_set = set()
    
    for i in range(len(numbers)):
        numbers_permutation = permutations(list(numbers), i + 1)
        numbers_perm_list = map(int, map("".join, numbers_permutation))
        prime_set |= set(numbers_perm_list)
        
    prime_set -= set(range(0,2)) #0,1 제거
    lim = int(max(prime_set)**0.5) + 1
    for i in range(2, lim):
        prime_set -= set(range(i*2, max(prime_set)+1,i)) # 자기자신은 빼고 자기자신의 배수를 지워줌
    return len(prime_set)

#recursive 하게 숫자 조합을 하기
prime_set = set()

def isPrime(num):
    if num in (0,1):
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def recursive(combination, others):
    if combination != "" and isPrime(int(combination)):
        prime_set.add(int(combination))
        
    for i in range(len(others)):
        recursive(combination + others[i], others[:i] + others[i+1:])

def solution(numbers):
    recursive("", numbers)
    
    return len(prime_set)