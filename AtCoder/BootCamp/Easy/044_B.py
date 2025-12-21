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
    w = input().strip()
    cnt = [0] * 26
    for c in w:
        cnt[ord(c) - ord('a')] += 1
    for i in cnt:
        if (i % 2 != 0):
            print("No")
            return
    print("Yes")

if __name__ == '__main__':
    solve()