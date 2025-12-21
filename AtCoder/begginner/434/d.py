import sys
input = sys.stdin.readline

def solve():
    MAX_H = 2000
    MAX_W = 2000
    
    N = int(input())
    clouds = []
    for _ in range(N):
        clouds.append(list(map(int, input().split())))

    grid = [[0] * (MAX_W + 2) for _ in range(MAX_H + 2)]

    for u, l, d, r in clouds:
        # (u, d) ++
        # (u, r+1) --
        # (l+1, d) --
        # (l+1, r+1) ++
        grid[u][d] += 1
        grid[u][r+1] -= 1
        grid[l+1][d] -= 1
        grid[l+1][r+1] += 1
    
    for i in range(1, MAX_H + 1):
        for j in range(1, MAX_W + 1):
            grid[i][j] += grid[i][j-1] + grid[i-1][j] - grid[i-1][j-1]

    base_empty_count = 0
    ones = [[0] * (MAX_W + 2) for _ in range(MAX_H + 2)]

    for i in range(1, MAX_H + 1):
        for j in range(1, MAX_W + 1):
            if grid[i][j] == 0:
                base_empty_count += 1
            elif grid[i][j] == 1:
                ones[i][j] = 1
    
    for i in range(1, MAX_H + 1):
        for j in range(1, MAX_W + 1):
            ones[i][j] += ones[i-1][j] + ones[i][j-1] - ones[i-1][j-1]

    for u, l, d, r in clouds:

            cnt = ones[l][r] - ones[u-1][r] - ones[l][d-1] + ones[u-1][d-1]
            
            print(base_empty_count + cnt)

if __name__ == '__main__':
    solve()