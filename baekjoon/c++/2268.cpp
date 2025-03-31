#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
vector<long long> tree;

long long init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = arr[start];
    }
    int mid=(start+end)/2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

long long query(int start, int end, int node, int left, int right) {
    if(right<start || left > end) return 0;
    if(left<=start&&end<=right) return tree[node];
    int mid=(start+end)/2;
    return query(start, mid, node*2, left, right) + query(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int idx, int diff) {
    if(idx<start || end<idx) return;
    if(start == end) {
       tree[node] += diff;
       return;
    }
    int mid=(start+end)/2;
    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);
    tree[node] = tree[node*2]+tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    arr.assign(n, 0);
    tree.assign(n*4, 0);
    init(0, n-1, 1);

    vector<long long> ans;
    while(m--) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;

        if(i1 == 0) {
            int sIdx = min(i2, i3);
            int eIdx = max(i2, i3);
            ans.push_back(query(0, n-1, 1, sIdx - 1, eIdx - 1));
        }else {
            int diff = i3-arr[i2-1];
            arr[i2-1] = i3;
            update(0, n-1, 1, i2-1, diff);
        }
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }
    
    return 0;
}