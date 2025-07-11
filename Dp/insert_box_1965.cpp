// Problem: BOJ 1965

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int n; cin >> n;
    int arr[n]; for (int i = 0; i < n; i++) cin >> arr[i];
    int dp[n] = {0};
    int nums[n] = {0};
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        // 현재 박스 크기 보다 작은 박스 중에 가장 많은 박스를 넣은 박스에 + 1 한 것과 나 자신 중에 큰 것을 nums에 저장
        for(int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            nums[i] = max(nums[i], nums[j] + 1);
        }
        // nums[i] 에는 현재 내가 넣을 수 있는 박스의 개수
        // 이전 박스 중 최댓값 dp와 nums + 1 중 최대값을 dp에 갱신
        dp[i] = max(dp[i-1], nums[i] + 1);
    }
    cout << dp[n-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}