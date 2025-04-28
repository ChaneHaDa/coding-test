#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int solve() {

    int n;
    cin>>n;

    if(n==0) return -1;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
    priority_queue<tuple<int, int, int>> pq;
    pq.push({-arr[0][0], 0, 0});

    int ans=0;
    while(!pq.empty()) {
        auto [cd, cx, cy] = pq.top();
        pq.pop();
        cd *= -1;

        if (cd > dis[cx][cy]) continue;

        if(cx==n-1 && cy==n-1) {
            ans = cd;
            break;
        }

        for(int i=0; i<4; i++) {
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx<0||nx>=n||ny<0||ny>=n) continue;

            if(dis[nx][ny]<=cd+arr[nx][ny]) continue;

            dis[nx][ny] = cd+arr[nx][ny];
            pq.push({-dis[nx][ny], nx, ny});
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> ans;
    while(1) {
        int rAns = solve();

        if(rAns==-1) {
            break;
        }
        ans.push_back(rAns);
    }

    for(int i=1; i<=ans.size(); i++) {
        cout<<"Problem "<<i<<": "<< ans[i-1]<<'\n';
    }

    return 0;
}