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
    interval = [h, h]
    pt = 0
    flag = True
    for _ in range(n):
        t, l, u = mi()
        if (not flag): continue
        interval[0] = max(1, interval[0] - (t - pt))
        interval[1] = interval[1] + (t - pt)
        if (interval[0] > u or interval[1] < l): flag = False
        interval[0] = max(interval[0], l)
        interval[1] = min(interval[1], u)
        pt = t
    print("Yes" if (flag) else "No")
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()