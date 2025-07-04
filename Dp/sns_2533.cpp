// Problem: BOJ 2533

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> adj;
vector<vector<int>> dp;
// dp[i][0] -> i번째 노드가 얼리 어댑터가 아닐 때 i를 루트 노드로 하는 서브트리에 필요한 최소 얼리 어댑터의 개수
// dp[i][1] -> i번째 노드가 얼리 어댑터일 때     i를 루트 노드로 하는 서브트리에 필요한 최소 얼리 어댑터의 개수

// "사이클이 없는 트리"니까 방문 배열을 만들지 않고 부모만 따로 받아서 순회
void dfs(int node, int parent) {
    // 얼리 어댑터인 경우 나 자신을 포함하기에 1로 초기화
    dp[node][1] = 1;
    // 얼리 어댑터가 아닌 경우 0으로 초기화
    dp[node][0] = 0;

    for(int child : adj[node]) {
        if (child == parent) continue;
        dp[node][1] = 1;
        dfs(child, node);
    }
    for (int child : adj[node]) {
        if (child == parent) continue;
        // 내가 얼리 어댑터인 경우는 자식이 0이든 1이든 상관없이 최소값
        dp[node][1] += min(dp[child][0], dp[child][1]);
        // 내가 얼리 어댑터가 아니면 자식은 무조건 얼리 어댑터
        dp[node][0] += dp[child][1];
    }

}

void solve() {
    int N; cin >> N;
    adj.assign(N+1, vector<int>());
    dp.assign(N+1, vector<int>(2, 0));
    while (--N)
    {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    dfs(1, -1);
    cout << min(dp[1][0], dp[1][1]) << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}