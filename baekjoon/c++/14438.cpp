#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<int> arr;
vector<int> tree;

int init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start+end)/2;

    return tree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

void update(int start, int end, int node, int idx, int diff) {
    if(idx<start||end<idx) return;

    if(start == end) {
        tree[node] = diff;
        return;
    }

    int mid = (start+end)/2;
    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int query(int start, int end, int node, int left, int right) {
    if(right<start || left>end) return INT_MAX;

    if(left<=start&&end<=right) {
        return tree[node];
    }

    int mid = (start+end)/2;

    return min(query(start, mid, node*2, left, right), query(mid+1, end, node*2+1, left, right));
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

    int m;
    cin>>m;

    tree.assign(n*4+1, INT_MAX);
    init(0, n-1, 1);

    vector<int> ans;
    while(m--) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;

        if(i1 == 1) {
            update(0, n-1, 1, i2-1, i3);
        }else {
            ans.push_back(query(0, n-1, 1, i2-1, i3-1));
        }
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}