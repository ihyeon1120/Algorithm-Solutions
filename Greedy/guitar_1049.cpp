// Problem: BOJ 1049

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

    int n, m; cin  >> n >>  m;
    int min6 = INT_MAX;
    int min1 = INT_MAX;
    while (m--) {
        int a6, a1; cin >> a6 >> a1;
        min6 = min(min6, a6);
        min1 = min(min1, a1);
    }
    // 1개당 가격이 min1이 더 싸면 min1으로만 구매하는게 최적
    if (min6 / 6.0 >= min1) {
        cout << n * min1;
    } 
    // 1개당 가격이 min6가 좋으면 min6로 전부 구매하는 것과 min6로 최대로 구매하고 나머지를 낱개로 구매 했을 때 가격 비교
    else {
        int k = n / 6;
        int i = 0;
        // 6으로 나눠 떨어질 떄랑 떨어지지 않을 때도 고려
        if (n % 6 != 0) {i++;}
        int r1 = (k + i) * min6;
        int r2 = k * min6 + (n % 6) * min1;
        cout << min(r1, r2) << endl;
    }

    return 0;
}