#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int parent[500001] = {0};

int find(int x) {
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

bool is_unions(int x, int y) {
    return find(x) == find(y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }

    int ans = 0;
    bool cycle = false;
    for(int i=0; i<m; i++) {
        int i1, i2;
        cin>>i1>>i2;

        if(is_unions(i1, i2) && cycle==false){
            ans=i+1;
            cycle = true;
        }

        merge(i1, i2);
    }

    cout<<ans<<endl;

	return 0;
}