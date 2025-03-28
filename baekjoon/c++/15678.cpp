#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, d;
    cin >> n >> d;

    vector<long long> ki(n);
    for (int i = 0; i < n; i++) {
        cin >> ki[i];
    }

    vector<long long> dp(ki);
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        long long nowNum = ki[i];
        
        if (!dq.empty() && dq.front() < i - d)
            dq.pop_front();

        if (!dq.empty()) {
            nowNum += dp[dq.front()];
            nowNum = max(nowNum, ki[i]);
        }

        while (!dq.empty() && dp[dq.back()] < nowNum)
            dq.pop_back();
        
        dp[i] = nowNum;
        dq.push_back(i);
    }

    long long ans = dp[0];
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}
