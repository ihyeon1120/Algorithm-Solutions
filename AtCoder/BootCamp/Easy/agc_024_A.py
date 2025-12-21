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
    a, b, c, k = mi()
    bound = 10**18
    if (abs(a-b) > bound):
        print("Unfair")
    elif k % 2 == 0:
        print(a - b)
    else:
        print(b - a)


if __name__ == '__main__':
    solve()