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

vector<vector<int>> adj;
vector<int> v;
vector<int> matched;

bool dfs(int node) {
    for (int next : adj[node]) {
        if (v[next]) continue;
        v[next] = 1;
        if (matched[next] == 0 || dfs(matched[next])) {
            matched[next] = node;
            return true;
        }
    }
    return false;
}


void solve() {
    int n; cin >> n;
    vector<vector<ll>> sharks(n+1);
    adj.resize(n+1);
    matched.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        sharks[i] = {a, b, c};
    }
    // O(N^2)
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (sharks[i][0] <= sharks[j][0] && sharks[i][1] <= sharks[j][1] && sharks[i][2] <= sharks[j][2] ) 
                adj[j].push_back(i);
            else if (sharks[i][0] >= sharks[j][0] && sharks[i][1] >= sharks[j][1] && sharks[i][2] >= sharks[j][2] ) 
                adj[i].push_back(j);
        }
    }
    for (vector<int> i : adj) debug(i);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        v.assign(n+1, 0);
        if (dfs(i)) ans ++;
        v.assign(n+1, 0);
        if (dfs(i)) ans++;
    }
    cout << n - ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}