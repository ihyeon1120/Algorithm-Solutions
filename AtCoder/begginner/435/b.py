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
    n = int(input())
    arr = li()
    ans = 0
    for l in range(n):
        for r in range(l+1, n):
            sub = arr[l:r+1]
            s = sum(sub)
            flag = True
            for i in sub:
                if s % i == 0:
                    flag = False
            if flag:
                ans += 1
    print(ans)
if __name__ == '__main__':
    solve()