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
    left = -1
    right = 10000000
    for _ in range(m):
        l, r = mi()
        left = max(left, l)
        right = min(right, r)

    print(min(max(0, right - left + 1), n))

if __name__ == '__main__':
    solve()