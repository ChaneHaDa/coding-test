#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<long long, int>>> graph;
vector<vector<long long>> dis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    
    graph.assign(n+1, vector<pair<long long, int>>());
    dis.assign(n+1, vector<long long>(k+1, LONG_LONG_MAX));

    while(m--) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;

        graph[i1].push_back({i2, i3});
        graph[i2].push_back({i1, i3});
    }

    priority_queue<tuple<long long, int, int>> pq;
    pq.push({0, 1, 0});

    while(!pq.empty()) {
        auto [cd, cx, cm] = pq.top();
        cd *= -1;
        pq.pop();

        if(dis[cx][cm] < cd) continue;

        for(auto [nx, nd]:graph[cx]) {
            if(dis[nx][cm] > nd+cd) {
                dis[nx][cm] = nd+cd;
                pq.push({-(nd+cd), nx, cm});
            }

            if(cm+1 <= k && dis[nx][cm+1] > cd){
                dis[nx][cm+1] = cd;
                pq.push({-cd, nx, cm+1});
            }
        }
    }

    long long ans=LONG_LONG_MAX;
    for(auto i:dis[n]) {
        ans = min(ans, i);
    }

    cout<<ans<<'\n';

    return 0;
}