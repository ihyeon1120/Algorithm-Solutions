// Problem: BOJ 11375

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// 각 직원이 어떤일을 할 수 있는지를 나타내는 배열
vector<int> jobs[1001];
// assign[i] -> i번째 일이 어떤 직원가 매칭 되었는지 나타내는 배열
int assign[1001] = {0};
// 방문배열 같은 느낌 현재 dfs에서 이 일을 진행했는지 확인하고 진행 되었으면 더 이상 dfs를 하지 않음
bool done[1001];

bool dfs(int x) {
    for(int i = 0; i < jobs[x].size(); i++) {
        int job = jobs[x][i];
        if (done[job]) continue;
        done[job] = true;
        // job이 할당되지 않았거나 매칭을 변경해서 현재 job의 할당을 비울 수 있다면
        if (assign[job] == 0 || dfs(assign[job])) {
            assign[job] = x;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    for(int person = 1; person < n+1; person++)
    {
        int k; cin >> k;
        while (k--)
        {
            int job; cin >> job;
            jobs[person].push_back(job);
        }
        
    }

    int ans = 0;
    // 첫 번째 일
    for(int i = 1; i <= n; ++i) {
        fill(done, done + 1001, false);
        if (dfs(i)) ans += 1;
    }

    cout << ans << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}