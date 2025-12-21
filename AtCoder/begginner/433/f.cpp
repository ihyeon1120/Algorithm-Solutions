#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int MAXN = 1000005;

ll fact[MAXN], invFact[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    ll total_ans = 0;

    for (int d = 0; d < 9; d++) {
        char c1 = d + '0';
        char c2 = (d + 1) + '0';

        int count_right = 0;
        for (char c : s) {
            if (c == c2) count_right++;
        }

        int count_left = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == c1) {               
                if (count_right >= 1) {
                    ll ways = nCr(count_left + count_right, count_right - 1);
                    total_ans = (total_ans + ways) % MOD;
                }
                
                count_left++;
            } 
            else if (s[i] == c2) {
                count_right--;
            }
        }
    }

    cout << total_ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    solve();
    return 0;
}