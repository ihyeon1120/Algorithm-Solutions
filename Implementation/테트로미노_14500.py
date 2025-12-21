import sys
import math
from collections import deque, Counter
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

# sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

tets = [
    [(0, 0), (0, 1), (0, 2), (0, 3)],
    [(0, 0), (1, 0), (0, 1), (1, 1)],
    [(0, 0), (1, 0), (2, 0), (2, 1)],
    [(0, 0), (1, 0), (1, 1), (2, 1)],
    [(0, 0), (0, 1), (0, 2), (1, 1)]
]

def solve():
    n, m = mi()
    grid = [[-(1 << 30)] * (max(n, m)) for _ in range(max(n, m))]
    for i in range(n):
        t = li()
        for j in range(len(t)):
            grid[i][j] = t[j]
        
    
    def rotate():
        ret = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                ret[j][n-1-i] = grid[i][j]
        return ret
    if (n < m): n = m
    else: m = n
    ans = 0
    for r in range(4):
        for i in range(n):
            for j in range(m):
                
                out_of_range = False
                for tet in tets:
                    t = 0
                    for r, c in tet:
                        if (i + r < 0 or i + r >= n or j + c < 0 or j + c >= m): 
                            out_of_range = True
                            continue
                        t += grid[i+r][j+c]
                    if (out_of_range): continue
                    ans = max(ans, t)
        grid = rotate()

    print(ans)


if __name__ == '__main__':
    solve()