#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n;
    cin>>m;

    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());
    vector<int> node(n+1, INT_MAX);
    while(m--) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;
        graph[i1].push_back({i2, i3});
    }

    int start, end;
    cin>>start>>end;

    priority_queue<pair<int, int>> pq;
    node[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int cx = pq.top().second;
        int cc = -pq.top().first;
        pq.pop();

        if (node[cx] < cc) continue;

        for(auto i:graph[cx]) {
            int nx = i.first;
            int nc = i.second;

            if(nc+cc<node[nx]) {
                node[nx] = nc+cc;
                pq.push({-(nc+cc), nx});
            }
        }
    }

    cout<<node[end]<<'\n';

    return 0;
}