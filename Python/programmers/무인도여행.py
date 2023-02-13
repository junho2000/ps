import sys #파이썬은 기본 재귀 깊이에 제한이 있어 입력이 커지는 경우 RecursionError 가 발생할 수 있음
sys.setrecursionlimit(100000)

def solution(maps):
    global totalsum
    answer = []
    maps = [list(map) for map in maps]
    
    def validCheck(a, b):
        return a >= 0 and a < len(maps) and b >= 0 and b < len(maps[0]) and maps[a][b] != "X"
    def dfs(i, j):
        global totalsum
        maps[i][j] = 'X'
        dx = [1, 0, -1, 0]
        dy = [0, -1, 0, 1]        
        for d in range(4):
            nx = j + dx[d]
            ny = i + dy[d]
            if validCheck(ny, nx):
                totalsum += int(maps[ny][nx])
                dfs(ny, nx)
    
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if validCheck(i, j):
                totalsum = int(maps[i][j])
                dfs(i,j) # i, j -> y, x
            
                if totalsum != 0:
                    answer.append(totalsum)
                
    if len(answer) == 0:
        return [-1]
    return sorted(answer)