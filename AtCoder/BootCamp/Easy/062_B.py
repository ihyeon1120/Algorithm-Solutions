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
    h, w = mi()
    image = []
    for i in range(h):
        image.append(input().strip())
    print("#" * (w+2))
    for s in image:
        print("#" + s + "#")
    print("#" * (w+2))
if __name__ == '__main__':
    solve()