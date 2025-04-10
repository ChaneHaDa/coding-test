#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dfs(int cx, vector<int>& v, vector<vector<int>>& g, vector<int>& dp) {
    if (dp[cx] != -1) return dp[cx];

    dp[cx] = v[cx];

    for(auto nx:g[cx]) {
        dp[cx] = max(v[cx]+dfs(nx, v, g, dp), dp[cx]);
    }

    return dp[cx];
}

int solve() {
    int n, k;
    cin>>n>>k;

    vector<int> v(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>v[i];
    }

    vector<vector<int>> g(n+1, vector<int>());
    while(k--) {
        int i1, i2;
        cin>>i1>>i2;

        g[i2].push_back(i1);
    }

    vector<int> dp(n+1, -1);
    int w;
    cin>>w;

    dfs(w, v, g, dp);

    return dp[w];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    vector<int> ans;
    while(t--) {
        ans.push_back(solve());
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}