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
    if (len(s) != len(set(s))):
        print("no")
    else:
        print("yes")

if __name__ == '__main__':
    solve()