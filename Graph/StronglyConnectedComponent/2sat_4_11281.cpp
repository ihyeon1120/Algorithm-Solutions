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

    for (int i = 1; i < n+1; ++i) {
        if (sccID[2*i] == sccID[2*i - 1]) {
            cout << 0 << endl;
            return;
        }
    }

    cout << 1 << endl;

    vector<int> values(n+1);
    for (int i = 1; i < n + 1; ++i) {
        int true_value = 2 * i;
        int false_value = 2 * i - 1;
        // sccID의 순은 위상정렬의 역순이므로 역순부터 false(0)을 할당함
        // 0을 할당하는 이유는 함의 관계이기에 1을 할당한다면 뒤에 나오는 scc가 1을 할당해야하만 하기에 더 약한 조건을 걸어줌
        if (sccID[true_value] > sccID[false_value]) {
            values[i] = 0;
        } else {
            values[i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << values[i] << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}