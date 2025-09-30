// Problem: BOJ 1543

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

    string s; getline(cin, s);
    int n = s.length();
    string target; getline(cin, target);
    int tn = target.length();
    int i = 0;
    int ans = 0;
    while (i < n - tn) {
        string t = s.substr(i, tn);
        if (t == target) {
            ans ++;
            i += tn;
            continue;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}