import sys
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
v = [-1] * (n+1)
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

def dfs(cur):
    if (v[cur] != -1): return
    v[cur] = 1
    for nxt in adj[cur]:
        if (v[nxt] != -1): continue
        
        dfs(nxt)
ans = 0
for i in range(1,n+1):
    if (v[i] == -1):
        dfs(i)
        ans += 1

print(ans)