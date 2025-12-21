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
    s = input().strip()
    for i in range(len(s)):
        if (i == a) :
            if (s[i] != '-'):
                print("No")
                return
        elif (0 > ord(s[i]) - ord('0') or ord(s[i]) - ord('0') > 9):
            print("No")
            return
    print("Yes")


if __name__ == '__main__':
    solve()