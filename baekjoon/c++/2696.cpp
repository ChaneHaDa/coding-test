#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve() {
    int m;
    cin >> m;
    vector<long long> ans;
    priority_queue<long long> maxH; // 왼쪽: 작은 절반 (최대 힙)
    priority_queue<long long, vector<long long>, greater<long long>> minH; // 오른쪽: 큰 절반 (최소 힙)

    for (int i = 0; i < m; i++) {
        long long n;
        cin >> n;

        // 1. 값 삽입
        if (maxH.empty() || n <= maxH.top()) {
            maxH.push(n);
        } else {
            minH.push(n);
        }

        // 2. 균형 맞추기
        if (maxH.size() > minH.size() + 1) {
            minH.push(maxH.top());
            maxH.pop();
        } else if (minH.size() > maxH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }

        // 3. 홀수번째마다 중앙값 기록
        if (i % 2 == 0) {
            ans.push_back(maxH.top());
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
