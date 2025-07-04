# Problem: BOJ 18185

import sys
input = sys.stdin.readline
N, B, C = map(int, input().split())
ramen = list(map(int, input().split()))
ans = 0 

# 2개를 낱개로 사는 경우 2B, 2개를 묶음으로 사는 경우 B + C
# B <= C 라면 묶음으로 살 필요가 없음
# B > C 라면 라면사기 small과 완전히 동일한 문제!
if (B <= C):
    print(B * sum(ramen))
    exit(0)

for i in range(N-2):

    # 가장 큰 값이 중앙에 있으면 3개로 묶었을 때 다음에서 최적해를 보장하지 않음
    # ex) 1 2 1 1 -> 3개 그냥 뽑으면 0 1 0 1이 남아 버림
    if ramen[i+1] > ramen[i+2]:
        min_n =  min(ramen[i], ramen[i+1] - ramen[i+2])
        ramen[i] -= min_n
        ramen[i+1] -= min_n
        ans += min_n * (B+C)
        min_n = min(ramen[i:i+3])
        ramen[i] -= min_n
        ramen[i+1] -= min_n
        ramen[i+2] -= min_n   
        ans += min_n * (B+2*C)
    # 위 경우가 아니면 3개씩 사기
    else:
        min_n = min(ramen[i:i+3])
        ramen[i] -= min_n
        ramen[i+1] -= min_n
        ramen[i+2] -= min_n
        ans += min_n * (B+ 2*C)
        # 3개 구매 이후 2개 구매
        min_n = min(ramen[i], ramen[i+1])
        ramen[i] -= min_n
        ramen[i+1] -= min_n
        ans += min_n * (B + C)

    ans += ramen[i] * B
    ramen[i] = 0
        
# N-3까지 처리했음 이후 N-2, N-1에 대한 처리
min_n = min(ramen[N-2], ramen[N-1])
ramen[N-2] -= min_n
ramen[N-1] -= min_n
ans += min_n * (B + C)

# 그래도 남은 라면들을 모두 1개씩 구매
ans += ramen[N-2] * B
ans += ramen[N-1] * B

print(ans)