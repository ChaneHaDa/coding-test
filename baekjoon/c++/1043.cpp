#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x) {
    if(x != parent[x]){
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

    parent.assign(n+1, 0);
    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }

    int numKnow;
    cin>>numKnow;
    for(int i=0; i<numKnow; i++){
        int input1;
        cin>>input1;
        merge(0, input1);
    }

    int ans=m;
    vector<vector<int>> g;
    for(int i=0; i<m; i++) {
        int input1;
        cin>>input1;
        vector<int> tempVec;
        for(int i=0; i<input1; i++) {
            int input2;
            cin>>input2;

            tempVec.push_back(input2);
        }
        g.push_back(tempVec);
    }

    // 그룹 union
    for(int i=0; i<m; i++) {
        int baseX = g[i][0];
        for(auto j:g[i]) {
            merge(baseX, j);
        }
    }

    for(int i=0; i<m; i++) {
        for(auto j:g[i]) {
            if(is_unions(0, j)){
                ans--;
                break;
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}