#include <iostream>
#include <vector>
#include <stack>
#include <string>

#define endl "\n"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<int> s;
    string result_ops = ""; // 연산 결과를 저장할 문자열
    int current_num = 1; // 스택에 push할 1부터 오름차순으로 증가하는 수

    for (int i = 0; i < n; ++i) {
        int target_val;
        cin >> target_val;

        while (current_num <= target_val) {
            s.push(current_num);
            current_num++;
            result_ops += "+\n";
        }

        if (s.top() == target_val) {
            s.pop();
            result_ops += "-\n";
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << result_ops;

    return 0;
}