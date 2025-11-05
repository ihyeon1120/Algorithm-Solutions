// Problem: BOJ 10815

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
    unordered_set<ll> cards;
    for (int i = 0; i < n; ++i) {
        ll t; cin >> t;
        cards.insert(t);
    }

    int m; cin >> m;
    while(m--) {
        int i; cin >> i;
        cout << cards.count(i) << " ";
    }


    return 0;
}