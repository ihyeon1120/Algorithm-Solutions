MAXN = 1001
MOD = 10007
n = int(input())

dp = [0] * 1001
dp[1] = 1
dp[2] = 2
for i in range(3, MAXN):
    # 끝에 1*2로 채우는 것과 2*2를 가로로 된 블럭으로 채우는 경우 2개를 더하기
    dp[i] = (dp[i-1] + dp[i-2]) % MOD

print(dp[n])