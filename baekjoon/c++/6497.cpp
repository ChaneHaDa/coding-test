#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p;

int find(int x) {
    if(p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

void merge(int x, int y) {
    int pX = find(x);
    int pY = find(y);

    if(pX != pY) {
        p[pX] = pY;
    }
}

bool is_merge(int x, int y) {
    return find(x) == find(y);
}

long long sol() {
    int n, m;
    cin>>n>>m;

    if(n+m==0) return -1;

    p.assign(n, 0);
    for(int i=0; i<n; i++) {
        p[i]=i;
    }

    long long total=0;
    vector<tuple<int, int, int>> g;
    while(m--) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;
        g.push_back({i3, i1, i2});
        total += i3;
    }
    sort(g.begin(), g.end());

    long long ans=0;
    int cnt=0;
    for(auto [c, x, y]:g) {
        if(!is_merge(x, y)) {
            merge(x, y);
            ans += c;
            cnt++;
        }
        if(cnt == n-1) break;
    }

    return total-ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<long long> ans;
    while(true) {
        long long a = sol();
        if(a==-1) break;
        ans.push_back(a);
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}