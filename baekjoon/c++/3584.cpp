#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int solve(vector<vector<int>>& graph, int x, int y) {
    vector<bool> visit(graph.size(), false);

    while(x != 0) {
        visit[x] = true;
        if (!graph[x].empty()) x = graph[x][0];
        else break;
    }

    while(y != 0) {
        if (visit[y]) return y;
        if (!graph[y].empty()) y = graph[y][0];
        else break;
    }

    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    vector<int> ans;
    while(t--) {
        int n;
        cin>>n;

        vector<vector<int>> graph(n+1, vector<int>());
        for(int i=0; i<n-1; i++) {
            int i1, i2;
            cin>>i1>>i2;
            graph[i2].push_back(i1);
        }
        
        int x, y;
        cin>>x>>y;

        ans.push_back(solve(graph, x, y));
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}