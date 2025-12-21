import sys
import math
from collections import deque, Counter
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, m = mi()
    cnt = [0] * (m+1)
    for i in range(n):
        temp = li()
        for t in temp[1:]:
            cnt[t] += 1
    ans = 0
    for i in range(1, m+1):
        if (cnt[i] == n): ans += 1
    print(ans)
    
if __name__ == '__main__':
    solve()