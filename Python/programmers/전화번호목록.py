#내가 푼 풀이 하지만 마지막 2개가 시간초과 뜸...
#O(n^2)
def solution(phone_book):
    phone_book.sort()
    for one in range(len(phone_book)):
        for others in range(one+1,len(phone_book)):
            if phone_book[one] == phone_book[others][:len(phone_book[one])]:
                return False
    return True
    
# sort하지 않고 푼 풀이 using 'startswith' method
# 하지만 이것도 마지막 2개에서 시간초과 뜸..
#O(n^2)
def solution(phone_book):
    for i in range(len(phone_book)):
        for j in range(i + 1, len(phone_book)):
            if phone_book[i].startswith(phone_book[j]):
                return False
            if phone_book[j].startswith(phone_book[i]):
                return False
    return True
    
# 다른 풀이 roop 1개로 줄임
# 6 12 6789 -> sort -> 12 6 6789 (사전 순)
# 12 6, 6 6789 
def solution(phone_book):
    phone_book.sort()
    
    for p1, p2 in zip(phone_book, phone_book[1:]):
        if p2.startswith(p1):
            return False
    return True

#hashing을 이용한 풀이

def solution(phone_book):
    hash_map = {}
    for number in phone_book:
        hash_map[number] = 1
    
    for phone_number in phone_book:
        jubdoo = ''
        for cha in phone_number:
            jubdoo += cha
            if jubdoo in hash_map and jubdoo != phone_number:
                return False
    return True
