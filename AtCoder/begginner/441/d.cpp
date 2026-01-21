// Problem: BOJ 

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#ifndef ONLINE_JUDGE
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << "{" << p.first << ", " << p.second << "}";
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    return os << "]";
}

#define debug(...) cerr << "[DEBUG] " << #__VA_ARGS__ << ": ", DBG(__VA_ARGS__)
template<typename T> void DBG(const T& v) { cerr << v << endl; }
template<typename T, typename... Args> void DBG(const T& v, const Args&... args) { cerr << v << ", "; DBG(args...); }
#else
#define debug(...)
#endif

ll n, m, l, s, t; 
vector<vector<pll>> adj;
set<int> ans;

void dfs(int node, int depth, ll cost) {
    if (depth == l) {
        if (s <= cost && cost <= t) { 
            ans.insert(node);
        }
        return;
    }
    for (auto[next, c] : adj[node]) {
        dfs(next, depth + 1, cost + c);
    }
}

void solve() {
    cin >> n >> m >> l >> s >> t;
    adj.resize(n+1);
    while(m--) {
        ll u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    dfs(1, 0, 0);
    if (ans.empty()) {
    } else {
        for (int node : ans) {
            cout << node << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}