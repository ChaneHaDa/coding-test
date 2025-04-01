#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> disFromX;
int n, x;

int dks(int start) {
    vector<int> dis(n+1, INT_MAX);
    priority_queue<pair<int, int>> pq;

    pq.push({0, start});
    dis[start] = 0;

    while(!pq.empty()) {
        int cx = pq.top().second;
        int cd = -pq.top().first;
        pq.pop();
        if(dis[cx]<cd) continue;

        for(auto next:graph[cx]) {
            int nx=next.first;
            int nd=next.second;

            if(nd+cd<dis[nx]) {
                dis[nx] = nd+cd;
                pq.push({-(nd+cd), nx});
            }
        }
    }

    if(start == x){
        disFromX.assign(dis.begin(), dis.end());
    }

    return dis[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m;
    cin>>n>>m>>x;
    graph.assign(n+1, vector<pair<int, int>>());

    int i1, i2, i3;
    while(m--) {
        cin>>i1>>i2>>i3;
        graph[i1].push_back({i2, i3});
    }

    dks(x);
    int ans=0;

    for(int i=1; i<=n; i++) {
        if(i==x) continue;
        int disX = dks(i);
        ans = max(ans, disX+disFromX[i]);
    }

    cout<<ans<<'\n';

    return 0;
}