// Problem: BOJ 1019

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> ans(10, 0);

// n에 대해서 각 자리수에 있는 숫자 카운트
void cnt(ll n, int digit) {
    while (n > 0) {
        ans[n%10] += digit;
        n /= 10;
    }
}

void solve() {
    ll N; cin >> N;
    int s = 1;
    int e = N;
    int digit = 1;
    while (N > 0) {
        // 시작과 끝점을 0과 9로 맞춰서 개수를 셀 때 용이하게 가공
        while (s % 10 != 0 && s <= e)
        {
            cnt(s, digit);
            s++;
        }
        // s > e보다 커지면 멈추기
        if (s > e) break;
        // 끝점 9로 만들기
        while (e % 10 != 9 && s <= e)
        {
            cnt(e, digit);
            e--;
        }
        
        s /= 10;
        e /= 10;
        // 0과 9로 끝점을 설정하면 e - s + 1로 개수를 셀 수 있음 
        // ex) 20 ~ 39까지의 1의 자리수 개수는 0 ~9 까지 (3 - 2 + 1)개가 등장
        int count = (e - s + 1);
        for (int i = 0; i < 10; i++) ans[i] += (count * digit) ;
        digit *= 10;
        N /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    for (int i : ans) cout << i << " ";
    return 0;
}