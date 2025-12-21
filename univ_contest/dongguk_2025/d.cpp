// Problem: D

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

    int r, c; cin >> r >> c;
    vector<vector<int>> graph(r, vector<int>(c, 0));
    for (int i = 0; i < r; ++i) {
        string s; cin >> s;
        for (int j = 0; j < c; ++j) {
            int t = s[j] - '0';
            graph[i][j] = t;
        }
    }
    for (int i = 0; i < r - 1; ++i) {
        for (int j = 0; j < c - 1; ++j) {
            int t = graph[i][j] + graph[i][j+1] + graph[i+1][j] + graph[i+1][j+1];
            if (t == 4) {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;

    return 0;
}