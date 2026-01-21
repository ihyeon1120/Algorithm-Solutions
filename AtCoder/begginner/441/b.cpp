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


void solve() {
    int n, m; cin >> n >> m;
    vector<int> sc(26, 0);
    vector<int> tc(26, 0);
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        sc[c-'a'] ++;
    }
    for (int i = 0; i < m; ++i) {
        char c; cin >> c;
        tc[c-'a'] ++;
    }
    int q; cin >> q;
    while(q--) {
        int scount = 0;
        int tcount = 0;
        string temp; cin >> temp;
        for (char c : temp) {
            if (sc[c-'a'] != 0) scount ++;
            if (tc[c-'a'] != 0) tcount ++;
        }
        if (scount == tcount) cout << "Unknown" << endl;
        else if (scount < tcount) cout << "Aoki" << endl; 
        else cout << "Takahashi" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}