#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200001;

void solve() {
    ll n; cin >> n;
    vector<int> p(n+1);
    vector<int> p_idx(n+1);
    vector<int> LNode(n+1, 0);
    vector<int> RNode(n+1, 0);
    int t;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        p[i] = t;
        p_idx[t] = i;
    }
    function<void(void)> build_tree = [&] (void) {
        stack<int> s;
        for (int i = 1; i <= n ; ++i) {
            int last_popped = 0;
            while(!s.empty() && p[s.top()] < p[i]) {
                last_popped = s.top();
                s.pop();
            }
            LNode[i] = last_popped;
            if (!s.empty()) {
                RNode[s.top()] = i;
            }
            s.push(i);
        }
    };

    function<ll(int)> dfs = [&] (int node) -> ll {
        ll ldist = 0, rdist = 0;

        if (LNode[node] != 0) ldist = abs(node - LNode[node]) + dfs(LNode[node]);        
        if (RNode[node] != 0) rdist = abs(node - RNode[node]) + dfs(RNode[node]);
        
        return max(rdist, ldist);
    };

    build_tree();
    ll ans = dfs(p_idx[n]);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}