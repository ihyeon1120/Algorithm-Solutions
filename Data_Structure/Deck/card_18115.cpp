// Problem: BOJ 18115

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
    int n; cin >> n;
    int cards[n];
    int top = 0; int bottom = n-1; int temp = 0;
    for (int i = n; i > 0; --i) {
        int s; cin >> s;
        if (s == 1) {
            cards[top++] = i;
            if (temp) {
                top += temp;
                temp = 0;
            }
        }
        else if (s == 3) cards[bottom--] = i;
        else {
            temp++;
            cards[top + temp] = i;
        }
    }
    for (int i : cards) cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}