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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {300, 60, 10};
    vector<int> ans(301, 0);
    int n; cin >> n;
    for (int i : arr) {
        int k = n / i;
        ans[i] += k;
        n -= k * i;
    }
    if (n != 0) cout << -1 << endl;
    else  printf("%d %d %d\n", ans[300], ans[60], ans[10]);    
    return 0;
}