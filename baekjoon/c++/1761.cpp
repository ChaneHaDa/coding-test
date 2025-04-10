#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> depth;
vector<int> dis;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> parent;

void dfs(int x) {
    for(auto [nx, nd]:graph[x]) {
        if(depth[nx] == 0) {
            depth[nx] = depth[x] + 1;
            dis[nx] = dis[x] + nd;
            parent[nx][0] = x;
            dfs(nx);
        }
    }
}

void sparse() {
    for(int i=1; i<17; i++) {
        for(int j=1; j<=n; j++) {
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    for(int j=17-1; j>=0; j--) {
        if((depth[a] - depth[b]) >= (1<<j)) {
            a = parent[a][j];
        }
    }

    if(a == b) {
        return a;
    }

    for (int j=17-1; j>=0; j--) {
        if (parent[a][j]!=parent[b][j]) {
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

    // 배열 초기화
    depth.assign(n+1, 0);
    dis.assign(n+1, 0);
    graph.assign(n+1, vector<pair<int, int>>());
    parent.assign(n+1, vector<int>(17, 0));
    
    for(int i=0; i<n-1; i++) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;

        graph[i1].push_back({i2, i3});
        graph[i2].push_back({i1, i3});
    }

    depth[1] = 1;
    dfs(1);
    sparse();

    int m;
    cin>>m;

    vector<int> ans;
    while(m--) {
        int i1, i2;
        cin>>i1>>i2;

        int p = lca(i1, i2);
        int d = dis[i1] + dis[i2] - (dis[p]*2);

        ans.push_back(d);
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }
    
    return 0;
}