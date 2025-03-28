#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void dfs(int x, vector<int> &node, vector<vector<int>>& dp, vector<bool> &visit, vector<vector<int>> &graph) {
    visit[x] = true;

    dp[x][0] = 0;
	dp[x][1] = node[x];

    for(auto i:graph[x]) {
        if(visit[i] == false){
            dfs(i, node, dp, visit, graph);
            dp[x][0] += max(dp[i][0], dp[i][1]);
            dp[x][1] += dp[i][0];
        }
    }

} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> node(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>node[i];
    }

    vector<vector<int>> graph(n+1, vector<int>());
    for(int i=0; i<n-1; i++) {
        int i1, i2;
        cin>>i1>>i2;
        graph[i1].push_back(i2);
        graph[i2].push_back(i1);
    }

    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    vector<bool> visit(n+1, false);
    dfs(1, node, dp, visit, graph);

    cout << max(dp[1][0], dp[1][1]);

	return 0;
}