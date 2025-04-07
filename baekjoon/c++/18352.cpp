#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k, x;
    cin>>n>>m>>k>>x;

    vector<vector<int>> graph(n+1, vector<int>());
    while(m--) {
        int i1, i2;
        cin>>i1>>i2;

        graph[i1].push_back(i2);
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dis(n+1, INT_MAX); 

    pq.push({0, x});
    while(!pq.empty()) {
        auto [cd, cx] = pq.top();
        cd *= -1;
        pq.pop();
        
        if(dis[cx]<cd) {
            continue;
        }

        for(auto nx:graph[cx]) {
            if(dis[nx]>cd+1) {
                pq.push({-(cd+1), nx});
                dis[nx] = cd+1;
            } 
        }
    }
    
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(dis[i] == k) {
            ans.push_back(i);
        }
    }

    if(ans.size() == 0) {
        cout<<-1<<'\n';
        return 0;
    }
    
    sort(ans.begin(), ans.end());

    for(auto i : ans) {
        cout<<i<<'\n';
    }

    return 0;
}