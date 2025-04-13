#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    
    vector<vector<int>> v(n+1, vector<int>(n+1, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>v[i][j];
        }
    }

    vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
    dp[0][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dp[i][j] == 0 || (i==n-1 && j==n-1)) continue;
            if(v[i][j]+i < n) dp[v[i][j]+i][j] += dp[i][j];
            if(v[i][j]+j < n) dp[i][v[i][j]+j] += dp[i][j];
        }
    }

    cout<<dp[n-1][n-1]<<'\n';

    return 0;
}