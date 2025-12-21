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
    n, k, q = mi()
    get_points = [0] * (n+1)
    for _ in range(q):
        t = int(input())
        get_points[t] += 1
    for i in range(1, n + 1):
        if (k - q + get_points[i] <= 0):
            print("No")
        else: print("Yes")

if __name__ == '__main__':
    solve()