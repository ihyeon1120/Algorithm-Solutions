// Problem: BOJ 5597

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

    vector<int> arr(31, 0);
    for (int i = 0; i < 28; ++i) {
        int k; cin >> k;
        arr[k] = 1;
    }

    for (int i = 1; i < 31; ++i) {
        if (!arr[i]) cout << i << endl;
    }

    return 0;
}