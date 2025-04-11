#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<vector<pair<int, int>>> g;
vector<int> depth;
vector<vector<pair<int, int>>> dis;
vector<vector<int>> parent;

void dfs(int x) {
    for(auto [nx, nd]:g[x]) {
        if(depth[nx]==0) {
            depth[nx] = depth[x]+1;
            parent[nx][0] = x;
            dis[nx][0] = {nd, nd};
            dfs(nx);
        }
    }
}

void init_parent() {
    for(int i=1; i<17; i++) {
        for(int j=1; j<=n; j++) {
            parent[j][i] = parent[parent[j][i-1]][i-1];
            dis[j][i] = {max(dis[j][i-1].first, dis[parent[j][i-1]][i-1].first), min(dis[j][i-1].second, dis[parent[j][i-1]][i-1].second)};
        }
    }
}

pair<int, int> lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    int mins = 1000001;
	int maxs = -1;

    for(int i=17-1; i>=0; i--) {
        if((depth[a]-depth[b]) >= (1<<i)){
            mins = min(mins, dis[a][i].second);
			maxs = max(maxs, dis[a][i].first);
            a = parent[a][i];
        }
    }

    if(a==b) return {mins, maxs};

    for(int i=17-1; i>=0; i--) {
        if(parent[a][i] != parent[b][i]) {
            mins = min(mins, min(dis[a][i].second, dis[b][i].second));
			maxs = max(maxs, max(dis[a][i].first, dis[b][i].first));
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    mins = min({mins, dis[a][0].second, dis[b][0].second});
    maxs = max({maxs, dis[a][0].first, dis[b][0].first});

    return {mins, maxs};
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;

    g.assign(n+1, vector<pair<int, int>>());
    for(int i=0; i<n-1; i++) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;

        g[i1].push_back({i2, i3});
        g[i2].push_back({i1, i3});
    }

    depth.assign(n+1, 0);
    dis.assign(n+1, vector<pair<int, int>>(17, {0, 0}));
    parent.assign(n+1, vector<int>(17, 0));

    depth[1] = 1;
    dfs(1);
    init_parent();

    int m;
    cin>>m;

    vector<pair<int, int>> ans;
    while(m--) {
        int i1, i2;
        cin>>i1>>i2;

        ans.push_back(lca(i1, i2));
    }

    for(auto p:ans) {
        cout<<p.first<<' '<<p.second<<'\n';
    }
    return 0;
}   