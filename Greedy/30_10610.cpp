// Problem: BOJ 10610

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

    // 문제는 30을 묻고 있지만 숫자에 0의 유무를 판별한 후에 3의 배수 판단인지만 확인하면 된다.
    // N의 개수는 10만개의 구성이기에 NloN 안으로 수행

    string s; cin >> s;
    int n = s.length();
    bool zero = false;
    ll ans = 0;
    for (char c : s) {
        int i = c - '0';
        if (i == 0) zero = true;
        ans += i;
    }
    if (zero == true && ans % 3 == 0) {
        sort(all(s), greater<>());
        cout << s << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}