import sys

# 재귀 제한은 이 문제에서 필요 없지만 습관적으로 두셔도 무방합니다.
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def solve():
    N, Q = map(int, input().split())
    
    # cur_change: 현재 시점의 누적 변화량
    # min_change: 역사상 가장 많이 감소했을 때의 값 (최저점)
    # 인덱스 편의를 위해 N+2 크기로 넉넉히 잡습니다.
    cur_change = [0] * (N + 2)
    min_change = [0] * (N + 2)
    
    for _ in range(Q):
        i, x = map(int, input().split())
        
        # 1. 내 앞쪽 간격(D[i])은 벌어짐 -> 증가
        cur_change[i] += x
        # (증가하는 건 조건 위반 위험이 없으므로 min_change 갱신 필요 없음)
        
        # 2. 내 뒤쪽 간격(D[i+1])은 좁아짐 -> 감소
        # 맨 마지막 원소(N) 뒤에는 아무도 없으므로 i < N일 때만 처리
        if i < N:
            cur_change[i+1] -= x
            # 감소했으니 최저점 갱신 확인
            if cur_change[i+1] < min_change[i+1]:
                min_change[i+1] = cur_change[i+1]
    
    # 정답 계산
    ans = 0
    # j는 1번째 원소부터 N번째 원소까지
    for j in range(1, N + 1):
        # 필요한 초기 간격(D_j) 계산
        # 공식: 초기값 >= 1 - (최저 변화량)
        init_diff = 1 - min_change[j]
        
        # 이 간격(init_diff)은 전체 합계에서 몇 번이나 더해질까?
        # A_1에는 1번, A_2에는 1번 ... A_N에도 1번 포함됨 -> 총 (N - j + 1)번 포함
        # 예: D_1은 모든 A에 다 들어감. D_N은 A_N에만 들어감.
        ans += init_diff * (N - j + 1)
        
    print(ans)

if __name__ == '__main__':
    solve()