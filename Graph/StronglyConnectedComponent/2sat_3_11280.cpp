// Problem: BOJ 11280

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 20001;

vector<vector<int>> adj;
vector<int> discovered(MAXN, -1);
vector<int> sccID(MAXN, -1);
stack<int> s;
int scc_cnt, vertex_cnt = 0;

// 기본적인 scc 스켈레톤 코드
int scc(int cur) {
    int lowlink = discovered[cur] = vertex_cnt++;
    s.push(cur);
    
    for(int next : adj[cur]) {
        if (discovered[next] == -1) {
            lowlink = min(lowlink, scc(next));
        }
        else if (sccID[next] == -1) {
            lowlink = min(lowlink, discovered[next]);
        }
    }

    if (discovered[cur] == lowlink) {
        while(1) {
            int t = s.top(); s.pop();
            sccID[t] = scc_cnt;
            if (t == cur) break;
        }
        ++scc_cnt;
    }

    return lowlink;

} 

void solve() {
    int n, m; cin >> n >> m;
    adj.assign(2*n+1, vector<int>());
    while(m--) {
        int a, b; cin >> a >> b;
        // 음수(not)면 홀수로 양수면 짝수로
        a = (a < 0 ? -2*a - 1 : 2*a);
        b = (b < 0 ? -2*b - 1 : 2*b);
        int not_a = (a % 2 == 0 ? a - 1 : a + 1);
        int not_b = (b % 2 == 0 ? b - 1 : b + 1);
        adj[not_a].push_back(b);
        adj[not_b].push_back(a);
    }
    // 홀짝으로 나눠서 보니까 2n개 만큼 돌리기
    for(int i = 1; i < 2*n + 1; ++i) {
        if (discovered[i] == -1) scc(i);
    }
    /*
        한 scc내에 a와 not_a가 동시에 존재한다면 0
        설명:   하나의 scc에 a와 ~a가 존재하는 경우
                a가 참이라면 ~a가 참이어야한다는 결론에 도달 -> a와 ~a가 동시에 참일 수는 없음
    */
        for (int i = 1; i < n+1; ++i) {
        if (sccID[2*i] == sccID[2*i - 1]) {
            cout << 0 << endl;
            return;
        }
    }

    cout << 1 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}