#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> node;
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<bool> visit;
vector<int> ans;

void dfs(int x) {
    visit[x] = true;
    dp[x][1] = node[x];

    for(int nx:graph[x]) {
        if(visit[nx] == false) {
            dfs(nx);
			dp[x][0] += max(dp[nx][0], dp[nx][1]);
			dp[x][1] += dp[nx][0];
        }
    }
}

void tracing(int x, int px) {
    if(dp[x][1] > dp[x][0] && !visit[px]) {
        ans.push_back(x);
        visit[x] = true;
    }

    for(int nx:graph[x]) {
        if(nx == px) continue;
        tracing(nx, x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    node.assign(n+1, 0);
    for(int i=1; i<=n; i++){
        cin>>node[i];
    }

    graph.assign(n+1, vector<int>());
    for(int i=0; i<n-1; i++){
        int input1, input2;
        cin>>input1>>input2;

        graph[input1].push_back(input2);
        graph[input2].push_back(input1);
    }

    dp.assign(n+1, vector<int>(2, 0));
    visit.assign(n+1, false);
    dfs(1);

    fill(visit.begin(), visit.end(), false);
    tracing(1, 0);

    cout<<max(dp[1][1], dp[1][0])<<'\n';
    sort(ans.begin(), ans.end());

    for(int i:ans) {
        cout<<i<<" ";
    }
    cout<<'\n';

    return 0;
}