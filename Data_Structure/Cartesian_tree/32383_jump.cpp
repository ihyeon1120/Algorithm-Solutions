// Problem: BOJ 32383

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1000000007;
const int MAXN = 500001;
vector<int> L, R;
vector<ll> H;
ll n;
ll ans;

void cartesian_tree() {
    L = vector<int>(n+1, 0); R = vector<int>(n+1, 0);
    stack<int> s;
    for (int i = 1; i <= n; ++i) {
        int last_popped = 0;
        while(!s.empty() && H[s.top()] < H[i]) {
            last_popped = s.top(); s.pop();
        }
        L[i] = last_popped;
        if(!s.empty()) {
            R[s.top()] = i;
        }
        s.push(i);
    }
}
// 각각의 간선을 보면서 서브트리의 개수를 세며 값을 계산
// 간선의 이용수를 보고 계산하지 않으면 -> 각각의 노드를 보면 O(N^2)
ll dfs(ll node) {
    if (node == 0) return 0;
    ll my_sz = 1;
    if(L[node] != 0) {
        ll sub_tree = dfs(L[node]) % MOD;
        ll w = (H[node] - H[L[node]]) * (H[node] - H[L[node]]) % MOD;
        ll used_cnt = (sub_tree) * (n - sub_tree);
        ans += ((w % MOD) * (used_cnt % MOD)) % MOD;
        my_sz += sub_tree;
    }
    if (R[node] != 0) {
        ll sub_tree = dfs(R[node]) % MOD;
        ll w = (H[node] - H[R[node]]) * (H[node] - H[R[node]]) % MOD;
        ll used_cnt = (sub_tree) * (n - sub_tree);
        ans += ((w % MOD) * (used_cnt % MOD)) % MOD;
        my_sz += sub_tree;
    }
    return my_sz;
}

void solve() {
    cin >> n;
    H = vector<ll>(n+1);
    ll m = 0;
    int mi = -1;
    for (int i = 1; i <= n; ++i) {
        ll t; cin >> t;
        if (t > m) {
            m = t;
            mi = i;
        }
        H[i] = t;
    }
    ans = 0;
    cartesian_tree();
    dfs(mi);
    cout << ans % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}