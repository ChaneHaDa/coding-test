#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int>> g;
vector<vector<int>> p;
vector<int> depth;

void dfs(int x) {
    for(auto nx:g[x]) {
        if(depth[nx] != 0) continue;
        
        p[nx][0] = x;
        depth[nx] = depth[x]+1;
        dfs(nx);
    }
}

void init() {
    for(int j=1; j<17; j++) {
        for(int i=1; i<=n; i++) {
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    for(int j=17-1; j>=0; j--) {
        if((depth[a]-depth[b]) >= (1<<j)) {
            a = p[a][j];
        }
    }

    if(a==b) return a;

    for(int j=17-1; j>=0; j--) {
        if(p[a][j] != p[b][j]) {
            a = p[a][j];
            b = p[b][j];
        }
    }

    return p[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    g.assign(n+1, vector<int>());

    for(int i=0; i<n-1; i++) {
        int i1, i2;
        cin>>i1>>i2;
        g[i1].push_back(i2);
        g[i2].push_back(i1);
    }

    depth.assign(n+1, 0);
    p.assign(n+1, vector<int>(17, 0));
    depth[1]=1;
    dfs(1);
    init();

    int m;
    cin>>m;

    vector<int> ans;
    while(m--) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;

        int l1 = lca(i2, i3);
        int l2 = lca(i1, i2);
        int l3 = lca(i1, i3);

        int a = depth[l1]>depth[l2]?l1:l2;
        a = depth[a]>depth[l3]?a:l3;

        ans.push_back(a);
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }


    return 0;
}