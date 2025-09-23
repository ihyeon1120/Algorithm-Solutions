MOD = 10007
MAXN = 1001
n = int(input())
dp = [0] * (MAXN)
dp[1] = 1
dp[2] = 3


for i in range(3, MAXN):
    dp[i] = (dp[i-1] + 2 * dp[i-2]) % MOD
print(dp[n])