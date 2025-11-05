// Problem: BOJ 11049

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> mat(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        int r, c; cin >> r >> c;
        mat[i] = {r, c};
    }
    vector<int> dp(n+1);
    

    return 0;
}