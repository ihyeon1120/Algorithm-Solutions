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
    a, b = mi()
    if (a > 0): print("Positive")
    elif (b < 0):
        if ((b - a) % 2 == 0): print("Negative")
        else: print("Positive")
    else: print("Zero")

if __name__ == '__main__':
    solve()