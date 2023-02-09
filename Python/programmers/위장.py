#의상이 중복되는 것이 없으니 종류만 세면 됨
# k+1 * m+1 * n+1 ..... -1

#Counter를 이용하는 방법
from collections import Counter
def solution(clothes):
    answer = 1
    counter = Counter(type for clothe, type in clothes)
    print(list(counter.values()))
    for i in list(counter.values()):
        answer *= i + 1
    return answer -1


#Counter를 이용하지 않는 방법
def solution(clothes):
    hash_map = {}
    answer = 1
    for i in range(len(clothes)):
        hash_map[clothes[i][1]] = 0
    for i in range(len(clothes)):
        hash_map[clothes[i][1]] += 1
    for i in hash_map.values():
        answer *= i + 1
    return answer - 1
        
    
print(solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]))