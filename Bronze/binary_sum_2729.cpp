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

    int t; cin >> t;
    while(t--) {
        string s1; cin >> s1;
        string s2; cin >> s2;
        if (s1.length() < s2.length()) swap(s1, s2);
        int n = s1.length() - s2.length();
        s2 = string(n, '0') + s2;
        string s3 = string(s1.length(), '0');
        string res = string(s1.length(), '0');
        for (int i = n - 1; i > 0; --i) {
            int a = s1[i] - '0'; int b = s2[i] - '0'; int c = s3[i] - '0';
            if (a + b+ c == 1) res[i] = '1';
            else if (a + b+ c == 2) {
                res[i] = '0';
                s3[i - 1] = 1;
            }
            else if (a + b+ c == 3) {
                res[i] = '0';
                s3[i - 1] = 1;
            }
        }
        int a = s1[0] - '0'; int b = s2[0] - '0'; int c = s3[0] - '0';
        if (a + b+ c == 1) res[0] = '1';
        else if (a + b+ c == 2) {
            res[0] = '0';
            res = string(1, '1') + res;
        }
        else if (a + b+ c == 3) {
            res[0] = '1';
            res = string(1, '1') + res;
        }
        cout << res << endl;
    }

    return 0;
}