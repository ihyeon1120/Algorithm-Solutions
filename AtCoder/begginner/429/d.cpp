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

void solve() {
    ll n, m, c; cin >> n >> m >> c;
    // key의 위치에 value명
    unordered_map<ll, ll> pos(n);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        pos[t]++;
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}