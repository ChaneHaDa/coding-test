#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> v;
vector<int> tree;

int init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = v[start];
    }

    int mid = (start+end)/2;

    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

void update(int start, int end, int node, int idx, int diff) {
    if(idx < start || end < idx) return;

    if(start == end) {
        v[idx] = diff % 2;
        tree[node] = v[idx];
        return;
    } 

    int mid = (start+end)/2;

    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int start, int end, int node, int left, int right) {
    if(right<start || end<left) return 0;

    if(left<=start&&end<=right) {
        return tree[node];
    }

    int mid = (start+end)/2;

    return query(start, mid, node*2, left, right) + query(mid+1, end, node*2+1, left, right);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    v.assign(n, 0);
    for(int i=0; i<n; i++) {
        int i1;
        cin>>i1;
        v[i] = i1%2;
    }

    tree.assign(n*4, 0);
    init(0, n-1, 1);

    int m;
    cin>>m;
    
    vector<int> ans;
    while(m--) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;
        
        switch (i1) {
            case 1:
                update(0, n-1, 1, i2-1, i3);
                break;
            case 2:
                ans.push_back((i3-i2+1)-(query(0, n-1, 1, i2-1, i3-1)));
                break;
            case 3:
                ans.push_back(query(0, n-1, 1, i2-1, i3-1));
                break;
        }
    }

    for(auto i : ans) cout<<i<<'\n';

    return 0;
}