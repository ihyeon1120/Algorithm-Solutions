import sys
input_ = sys.stdin.readline
def minput(): return map(int, input_().split())


class UnionFind:
    def __init__(self, x):
        self.parent = [i for i in range(x)]
        self.size = [1] * x

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return
        elif self.size[root_x] >= self.size[root_y]:
            self.size[root_x] += self.size[root_y]
            self.parent[root_y] = root_x
        else:
            self.size[root_y] += self.size[root_x]
            self.parent[root_x] = root_y


while True:
    n, *hist = list(minput())
    if not n: break
    distinct = sorted(set(hist), reverse=True)
    rank = {distinct[i]: i for i in range(len(distinct))}
    order = [[] for _ in range(len(distinct))]
    for i in range(n):
        order[rank[hist[i]]].append(i)
    uf = UnionFind(n)
    ans = 0
    for i in range(len(distinct)):
        cur = order[i]
        for v in cur:
            if v and hist[v] <= hist[v - 1]:
                uf.union(v, v - 1)
            if v != (n - 1) and hist[v] <= hist[v + 1]:
                uf.union(v, v + 1)
        for v in cur:
            ans = max(ans, distinct[i] * uf.size[uf.find(v)])
    print(ans)
