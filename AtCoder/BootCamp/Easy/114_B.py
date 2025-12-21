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
    s = input()
    ans = (1 << 30)
    for i in range(len(s) - 2):
        t = int(s[i:i+3])
        ans = min(ans, abs(t - 753))
    print(ans)


if __name__ == '__main__':
    solve()