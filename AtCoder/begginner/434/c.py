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
    n, h = mi()
    flag = True

    # 첫 목표
    t, l, u = mi()
    low = max(1, h - t)
    high = h + t          

    if high < l or u < low:
        flag = False
    else:
        low = max(low, l)
        high = min(high, u)

    prev = t

    for _ in range(n-1):
        tt, l, u = mi()
        dt = tt - prev
        prev = tt
        
        if flag:
            low -= dt
            high += dt
            if low < 1: low = 1

            if high < l or u < low:
                flag = False
            else:
                low = max(low, l)
                high = min(high, u)

    print("Yes" if flag else "No")


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()