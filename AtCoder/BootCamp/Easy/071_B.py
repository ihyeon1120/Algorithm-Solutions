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
    s = input().strip()
    cnt = [0] * 26
    for c in s:
        cnt[ord(c) - ord('a')] += 1
    for i in range(26):
        if cnt[i] == 0:
            print(chr(i + ord('a')))
            return
    print("None")

if __name__ == '__main__':
    solve()