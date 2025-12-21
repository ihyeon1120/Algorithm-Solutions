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
    a, b, k = mi()

    if (b - a +1 <= 2*k):
        for i in range(a, b+1): print(i)
    else:
        for i in range(a, a + k):
            print(i)
        for i in range(b - k + 1, b + 1):
            print(i)

if __name__ == '__main__':
    solve()