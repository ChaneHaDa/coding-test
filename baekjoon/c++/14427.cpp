#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<int> arr;
vector<pair<int, int>> tree;

pair<int, int> init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = {arr[start], start};
    }
    int mid = (start+end) / 2;

    return tree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

void update(int start, int end, int node, int idx, int diff) {
    if(idx < start || end < idx) return;

    if(start == end) {
        tree[node] = {diff, idx};
        return; 
    }


    int mid = (start+end) / 2;
    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    arr.assign(n, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    tree.assign(4*n, {INT_MAX, 0});
    init(0, n-1, 1);

    int m;
    cin>>m;

    vector<int> ans;
    while(m--) {
        int i1, i2, i3;
        cin>>i1;
        
        if(i1 == 1) {
            cin>>i2>>i3;
            update(0, n-1, 1, i2-1, i3);
        }else { 
            ans.push_back(tree[1].second+1);
        }
    }

    for(int i : ans) {
        cout<<i<<'\n';
    }

    return 0;
}