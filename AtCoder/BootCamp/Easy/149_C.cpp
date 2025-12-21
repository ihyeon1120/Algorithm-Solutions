#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN =1000001;
vector<bool> prime;

void solve() {
    prime = vector<bool>(MAXN, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        for (int j = 2; j * i < MAXN; ++j) {
            prime[i*j] = false;
        }
    }
    int n; cin >> n;
    for (int i = n; ; ++i) {
        if (prime[i]) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}