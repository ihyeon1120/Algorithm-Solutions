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
    a = [1<<30] * n
    b = li()
    for i in range(n-1):
        t = b[i]
        if (a[i] > t):
            a[i] = t
        a[i+1] = t
    print(sum(a))
if __name__ == '__main__':
    solve()