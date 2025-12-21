import sys
import math
from collections import deque, Counter
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

class Lazy_Segment:
    tree = []
    lazy = []
    arr = []
    sz = 0
    def __init__(self, a: list):
        arr = a
        sz = len(a)
        h = int(math.ceil(math.log2(sz)))
        tree_sz = (1 << (h + 1))
        self.tree = [0] * tree_sz
        self.lazy = [0] * tree_sz
        self.init(1, 0, self.sz-1)

    def init(self, node, s, e):
        if (s == e): self.tree[node] = self.arr[s]
        else:
            m = (s + e) // 2
            self.init(2*node, s, m)
            self.ini(2*node+1, m+1, e)
            self.tree[node] = self.merge(self.tree[2*node], self.tree[2*node+1])

    def merge(a: int, b: int): return a + b

    def propagate(self, node, s, e):
        if (self.lazy[node] != 0):
            self.tree[node] += (e - s + 1) * self.lazy[node]
            if (s != e):
                self.lazy[2*node] = self.merge(self.lazy[node], self.lazy[2*node])
                self.lazy[2*node+1] = self.merge(self.lazy[node], self.lazy[2*node+1])
            self.lazy[node] = 0

    def update(self, node, s, e, l, r, v) -> None:
        self.propagate(node, s, e)
        if (e < l or r < s): return
        elif (l <= s and e <= r): 
            self.tree[node] += (e - s + 1) * v
            if (s != e):
                self.lazy[2*node] += v
                self.lazy[2*node+1] += v
            return
        m = (s + e) // 2
        self.update(2*node, s, m, l, r, v)
        self.update(2*node + 1, m + 1, e, l, r, v)
        self.tree[node] = self.merge(self.tree[2*node], self.tree[2*node+1])

    def query(self, node, s, e, l, r) -> int:
        self.propagate(node, s, e)
        if (e < l or r < s): return 0
        elif (l <= s and e <= r): return self.tree[node]
        m = (s + e) // 2
        return self.merge(self.query(2*node, s, m, l, r), self.query(2*node+1, m+1, e, l, r))

    def query(self, l, r) -> int: return self.query(1, 0, self.sz-1, l, r)
    def update(self, l, r, v): self.update(1, 0, self.sz-1, l, r, v)