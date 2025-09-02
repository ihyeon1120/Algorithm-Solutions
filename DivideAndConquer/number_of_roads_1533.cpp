// Problem: BOJ 1533

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

const int MOD = 1000003;
matrix adj_mat;

matrix multi(const matrix &a, const matrix &b) {
    ll size = sz(a);
    matrix ret(size, vector<ll>(size, 0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= MOD;
        }
    }
    return ret;
}

matrix power(const matrix &mat, ll d) {


    if (d == 1) return mat;
    matrix half = power(mat, d / 2);
    matrix res = multi(half, half);
    if (d % 2 == 1) res = multi(res, mat);

    return res;
}

void solve() {
    int s, e, t; 
    ll n, time;
    cin >> n >> s >> e >> time;

    if (time == 0) {
        if (s == e) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }

    adj_mat.assign(5*n, vector<ll>(5*n, 0));

    /*
        아이디어 도저히 생각 안나서 구글링
        1. 가중치가 들어 있는 인접행렬을 가중치를 1로 만들어 계산이 "가능"하게 만들어야함
        2. 가중치들을 전부 노드화 시켜서 5n * 5n 행렬을 생성
        3. 분할정복으로 행렬곱해서 정답 도출
    */ 

    // 모든 대기간선 생성
    for (int i = 0; i < n; ++i) {
        for (int d = 1; d <= 4; ++d) {
            // i번 노드의 d분 대기 상태 -> d-1분 대기 상태로 가는 간선
            adj_mat[i * 5 + d][i * 5 + d - 1] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            int weight = row[j] - '0';
            
            if (weight > 0) {
                // i의 출발 가능 상태(i, 0)에서
                // j의 (weight-1)분 대기 상태(j, weight-1)로 가는 간선
                adj_mat[i * 5 + 0][j * 5 + weight - 1] = 1;
            }
        }
    }

    cout << power(adj_mat, time)[(s-1) * 5][(e-1) * 5] % MOD << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}