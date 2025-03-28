#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    int n, s, m;
    cin >> n >> s >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = -1;
    vector<unordered_set<int>> dp(51, unordered_set<int>());

    dp[0].insert(s);
    
    for(int i=0; i<n; i++) {
        for(int j:dp[i]){
            if(j+arr[i]<=m)
                dp[i+1].insert(j+arr[i]);
            
            if(j-arr[i]>=0)
                dp[i+1].insert(j-arr[i]);
        }
    }

    for(int j:dp[n]){
        ans = max(ans, j);
    }
    
    cout << ans << endl;
    return 0;
}


// int main() {
//     int n, s, m;
//     cin >> n >> s >> m;
    
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
    
//     // visited[i][j] : i번째 단계에서 볼륨이 j인 상태를 이미 방문했는지 체크
//     vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    
//     queue<pair<int, int>> q;
//     q.push({0, s});
//     visited[0][s] = true;
    
//     int ans = -1;
    
//     while (!q.empty()) {
//         int ind = q.front().first;
//         int vol = q.front().second;
//         q.pop();
        
//         // 마지막 단계라면 최대값 갱신
//         if (ind == n) {
//             ans = max(ans, vol);
//             continue;
//         }
        
//         // 현재 스테이지에서 볼륨 증가
//         int volUp = vol + arr[ind];
//         if (volUp <= m && !visited[ind + 1][volUp]) {
//             q.push({ind + 1, volUp});
//             visited[ind + 1][volUp] = true;
//         }
        
//         // 볼륨 감소
//         int volDown = vol - arr[ind];
//         if (volDown >= 0 && !visited[ind + 1][volDown]) {
//             q.push({ind + 1, volDown});
//             visited[ind + 1][volDown] = true;
//         }
//     }
    
//     cout << ans << endl;
//     return 0;
// }
