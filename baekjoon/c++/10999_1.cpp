#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> arr;
vector<long long> tree;
vector<long long> lazy;

long long init(int start, int end, int node){
    if(start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start+end)/2;

    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

void update_lazy(int start, int end, int node) {
    if(lazy[node] != 0) {
        tree[node] += (end-start+1) * lazy[node];
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int start, int end, int node, int left, int right, long long diff) {
    update_lazy(start, end, node);
    
    if(right < start || end < left) return;

    if(left <= start && end <= right) {
        tree[node] += (end-start+1) * diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }

    int mid = (start+end) / 2;
    update_range(start, mid, node*2, left, right, diff);
    update_range(mid+1, end, node*2+1, left, right, diff);

    tree[node] = tree[node*2] + tree[node*2+1];
}

long long query(int start, int end, int node, int left, int right) {
    update_lazy(start, end, node);
    if(right < start || end < left) return 0;
    
    if(left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start+end) / 2;
    
    return query(start, mid, node*2, left, right) + query(mid+1, end, node*2+1, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    arr.assign(n+1, 0);
    tree.assign((n+1)*4, 0);
    lazy.assign((n+1)*4, 0);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    init(0, n-1, 1);

    vector<long long> ans;
    for(int i=0; i<m+k; i++) {
        int i1, i2, i3;
        long long i4;
        cin>>i1;

        if(i1 == 1) {
            cin>>i2>>i3>>i4;
            update_range(0, n-1, 1, i2-1, i3-1, i4);
        }else {
            cin>>i2>>i3;
            ans.push_back(query(0, n-1, 1, i2-1, i3-1));
        }
    }

    for(long long i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}