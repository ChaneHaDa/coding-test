#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p;
vector<int> v;
vector<int> c;

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
        c[pY] = min(c[pX], c[pY]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;

    v.assign(n+1, 0);
    p.assign(n+1, 0);
    c.assign(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>v[i];
        p[i] = i;
        c[i] = v[i];
    }

    while(m--) {
        int i1, i2;
        cin>>i1>>i2;
        merge(i1, i2);
    }

    long long ans=0;
    for (int i=1; i<=n; i++) {
        if (p[i] == i) {
            ans += c[i];
        }
    }
    
    if(ans > k) {
        cout<<"Oh no"<<'\n';
    }else {
        cout<<ans<<'\n';
    }

    return 0;
}