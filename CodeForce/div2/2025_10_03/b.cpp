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
        ll n, rk, ck, rd, cd; cin >> n >> rk >> ck >> rd >> cd;
        // 같은 행에 있을 경우
        if (rk == rd) {
            // 도란이 왼쪽에 있으면, 오른쪽 벽으로 몰아감
            if (ck > cd) {
                cout << n - cd << endl;
            }
            // 도란이 오른쪽에 있으면, 왼쪽 벽으로 몰아감
            else { // ck < cd
                cout << cd << endl;
            }
        }
        // 같은 열에 있을 경우
        else if (ck == cd) {
            // 도란이 위쪽에 있으면, 아래쪽 벽으로 몰아감
            if (rk > rd) {
                cout << n - rd << endl;
            }
            // 도란이 아래쪽에 있으면, 위쪽 벽으로 몰아감
            else { // rk < rd
                cout << rd << endl;
            }
        }
        else {
            // rd, cd 기준으로 사분면 만들기
            // 1사분면
            if (rk < rd && ck < cd) {
                cout << max(rd, cd) << endl;
            }
            // 크럭이 도란보다 위쪽 & 오른쪽에 있는 경우
            else if (rk < rd && ck > cd) {
                cout << max(rd, n - cd) << endl;
            }
            // 크럭이 도란보다 아래쪽 & 왼쪽에 있는 경우
            else if (rk > rd && ck < cd) {
                cout << max(n - rd, cd) << endl;
            }
            // 크럭이 도란보다 아래쪽 & 오른쪽에 있는 경우
            else if (rk > rd && ck > cd) {
                cout << max(n - rd, n - cd) << endl;
            }
        }
    }
    return 0;
}