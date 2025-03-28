#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> node;
vector<int> dp;
vector<bool> visit;

void dfs(int x) {
    visit[x] = true;
    for(int next:node[x]) {
        if(visit[next] == false){
            dp[next] += dp[x];
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    dp.assign(n+1, 0);
    node.assign(n+1, vector<int>());
    visit.assign(n+1, false);
    for(int i=1; i<=n; i++) {
        int input;
        cin>>input;

        if(input == -1) continue;
        node[input].push_back(i);
    }

    while(m--) {
        int i1, i2;
        cin>>i1>>i2;
        dp[i1] += i2;
    }

    dfs(1);

    for(int i=1; i<=n; i++) {
        cout<<dp[i]<<" ";
    }
    cout<<"\n";

    return 0;
}