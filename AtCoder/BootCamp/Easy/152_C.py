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
    min_val = 1 << 30
    for t in arr:
        if (min_val > t):
            min_val = t
            ans += 1
    print(ans)
if __name__ == '__main__':
    solve()