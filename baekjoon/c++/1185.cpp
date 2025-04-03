#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> parent;

int find(int x){
    if(x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y) {
    int pX = find(x);
    int pY = find(y);

    if(pX != pY) {
        parent[pX] = pY;
    }
}

bool is_samet(int x, int y) {
    return find(x) == find(y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, p;
    cin>>n>>p;

    vector<int> cost(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>cost[i];
    }

    vector<tuple<int, int, int>> t;
    while(p--) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;
        int c = i3*2+cost[i1]+cost[i2];
        t.push_back({c, i1, i2});
    }

    parent.assign(n+1, 0);
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }

    sort(t.begin(), t.end());
    int cnt=0;
    int ans=0;
    for(auto [c, x, y]:t) {
        if(!is_samet(x, y)){
            merge(x, y);
            cnt++;
            ans += c;
        }
        if(cnt == n-1) break;
    }

    sort(cost.begin(), cost.end());

    cout<<ans+cost[1]<<'\n';

    return 0;
}