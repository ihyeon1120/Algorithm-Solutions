// Problem: BOJ 1422

/*
아이디어1: 맨 앞에 나와야하는 수는 가장 큰 자리수의 수가 가장 크면서 (1순위), 숫자의 길이가 가장 긴 것 (2순위)
아이디어2: 맨 앞이 아닌 수를 채울 때는 숫자의 길이가 가장 긴 것 (1순위), 숫자의 가장 큰 자리수가 가장 큰 것(2순위)
아이디어3: 모든 수를 다 한번 써야하기 때문에 아이디어2를 따라 정렬 후 가장 순위가 높은 것을 먼저 채우되 모든 숫자를 1번씩 쓸 수 있게 반복을 조절
*/

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> nums; for(int i = 0; i < n; i++) cin >> nums[i];
    sort(all(nums), greater<>());

    string n = "";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}