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
    s = input().rstrip()
    cnt = [0] * 26
    for c in s:
        cnt[ord(c) - ord('a')] += 1
        if (cnt[ord(c) - ord('a')] >= 2):
            print("no")
            return
    print("yes")

if __name__ == '__main__':
    solve()