import sys
import math
from collections import deque, Counter, defaultdict
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

parent = []

coordinate_id = dict()
cnt_vertex = []
cnt_edge = []

def get_id(cor):
    if (cor not in coordinate_id):
        coordinate_id[cor] = len(coordinate_id)
    return coordinate_id

def find(x):
    global parent, cnt_edge, cnt_vertex
    if (x != parent[x]):
        parent[x] = find(parent[x])
    return x

def union(x, y):
    global parent, cnt_edge, cnt_vertex
    root_x = find(x)
    root_y = find(y)
    if (root_x != root_y):
        parent[root_y] = root_x
        cnt_vertex[root_x] += cnt_vertex[root_y]
        cnt_edge[root_x] += 1
    else:
        cnt_edge[root_x] += 1
def solve():
    global parent, cnt_edge, cnt_vertex
    n = int(input())
    parent = [i for i in range(2*(n+1))]
    cnt_vertex = [0 for _ in range(2*(n+1))]
    cnt_edge = [0 for _ in range(2*(n+1))]
    for _ in range(n):
        x, r = mi()
        u = get_id(x-r)
        v = get_id(x+r)
        union(u, v)
    ans = 0
    for i in range(len(coordinate_id)):
        if (parent[i] == i):
            ans += min(cnt_edge[i], cnt_vertex[i])
    print(ans)


if __name__ == '__main__':
    solve()