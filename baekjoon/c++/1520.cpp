#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<vector<int>> dp;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y) {
    if(x==n-1 && y==m-1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];

    dp[x][y] = 0;

    for(int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        
        if(v[nx][ny] < v[x][y]) {
            dp[x][y] = dp[x][y] + dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    
    v.assign(n, vector<int>(m, 0));
    dp.assign(n, vector<int>(m, -1));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>v[i][j];
        }
    }

    dfs(0, 0);

    cout<<dp[0][0]<<'\n';

    return 0;
}