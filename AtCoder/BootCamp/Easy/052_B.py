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
    s = input()
    x = 0
    ans = 0
    for c in s:
        if c == 'D':
            x -= 1
        elif c == 'I': 
            x += 1
        ans = max(ans, x)
    print(ans)

if __name__ == '__main__':
    solve()