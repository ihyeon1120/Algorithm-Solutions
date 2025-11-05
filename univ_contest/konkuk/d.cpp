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

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    // 2개만 있을 때 -> 2개가 정렬이 되어 있으면 YES
    // 3개 있을 때 중위수가 2번째 인덱스에 있으면 YES
    // 3개 있을 때 중위수가 2번째 인덱스에 없으면 2 1 3 or 2 3 1 or 1 3 2 or 3 1 2 -> 안되는 것 처럼 보이지만
    // 2개로 나누면 정렬이 된 부분배열이 무조건 있기에 2개만 있을 때 조건을 만족
    // 4개 이상이면 길이가 3인 부분 배열로 본다 생각하면 무조건 성립 -> 3 이상이면 무조건 YES
    if (n >= 3) printf("YES");
    else {
        if (a[0] <= a[1]) printf("YES");
        else printf("NO");
    }

    return 0;
}