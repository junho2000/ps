def isPalindrome(x):
    if x==x[::-1]:
        return True
def solution(s):
    answer=0
    for i in range(len(s)): #0~6
        for j in range(i+1,len(s)+1): #1~7
            if isPalindrome(s[i:j]):
                if answer < j - i:
                    answer = j - i
    return answer
