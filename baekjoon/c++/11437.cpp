#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<int>> parent;
vector<int> depth;

void dfs(int x) {
    for(auto nx:graph[x]) {
        if(depth[nx] == 0) {
            depth[nx] = depth[x]+1;
            parent[nx][0] = x;
            dfs(nx);
        }
    }
}

void dp() {
    for(int i=1; i<17; i++) {
        for(int j=1; j<=n; j++) {
            if (parent[j][i-1] != 0)
                parent[j][i] = parent[parent[j][i-1]][i-1];
            else
                parent[j][i] = 0;
        }
    }
}


int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int j = 17 - 1; j >= 0; j--) {
        if (depth[a] - depth[b] >= (1 << j)) {
            a = parent[a][j];
        }
    }

    if (a == b) return a;

    for (int j = 17 - 1; j >= 0; j--) {
        if (parent[a][j] != parent[b][j]) {
            a = parent[a][j];
            b = parent[b][j];
        }
    }

    return parent[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    graph.assign(n+1, vector<int>());

    for(int i=0; i<n-1; i++) {
        int i1, i2;
        cin>>i1>>i2;
        
        graph[i1].push_back(i2);
        graph[i2].push_back(i1);
    }

    int m;
    cin>>m;
    
    depth.assign(n+1, 0);
    parent.assign(n+1, vector<int>(17, 0));
    depth[1] = 1;
    dfs(1);
    dp();

    vector<int> ans;
    while(m--) {
        int i1, i2;
        cin>>i1>>i2;
        ans.push_back(lca(i1, i2));
    }

    for(auto i : ans) {
        cout<<i<<'\n';
    }

    return 0;
}