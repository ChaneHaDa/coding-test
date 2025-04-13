#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m;
    cin>>m;

    vector<vector<int>> sp(m+1, vector<int>(20, 0));
    for(int i=1; i<=m; i++) {
        cin>>sp[i][0];
    }

    for(int j=1; j<20; j++) {
        for(int i=1; i<=m; i++) {
            sp[i][j] = sp[sp[i][j-1]][j-1];
        }
    }

    int q;
    cin>>q;

    vector<int> ans;
    while(q--) {
        int i1, i2;
        cin>>i1>>i2;

        for(int j=20-1; j>=0; j--) {
            if(i1 & (1<<j)){
                i2 = sp[i2][j];
            }
        }

        ans.push_back(i2);
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}