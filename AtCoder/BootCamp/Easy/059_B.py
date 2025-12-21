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
    a = int(input())
    b = int(input())
    if (a > b): print("GREATER")
    elif (a < b): print("LESS")
    else: print("EQUAL")

if __name__ == '__main__':
    solve()