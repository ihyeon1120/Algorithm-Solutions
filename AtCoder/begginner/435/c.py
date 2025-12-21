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
    A = list(map(int, input().split()))

    cur = 0
    ans = 0

    for i in range(n):
        if i > cur:
            break
        cur = max(cur, i + A[i] - 1)
        ans = i + 1

    print(ans)

if __name__ == '__main__':
    solve()