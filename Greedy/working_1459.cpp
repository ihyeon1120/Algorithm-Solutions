// Problem: BOJ 1459

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

    ll c, r;
    int straight, cross;
    cin >> c >> r >> straight >> cross;
    if (c > r) swap(c, r);
    if (straight * 2 <= cross) {
        cout << (c + r) * straight << endl;
        return 0;
    }

    else if (straight <= cross){
        cout << c * cross + (r - c) * straight;
        return 0;
    }
    else {
        // r-c = 직선구간이 짝수면 그냥 r * cross만에 갈 수 있고 홀수면 r-1* cross로 가고 마지막을 직선거리로 가기
        cout << (r - ((r-c) % 2)) * cross + ((r-c) % 2) * straight << endl;
    }

    return 0;
}