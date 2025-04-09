#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> tree;
vector<int> lazy;

void update_lazy(int start, int end, int node)  {
    if(lazy[node] != 0) {
        tree[node] = (end-start+1) - tree[node];
        if(start != end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        
        lazy[node] = 0;
    }
}

void update_range(int start, int end, int node, int left, int right)  {
    update_lazy(start, end, node);
    
    if(right<start||end<left) return;

    if(left<=start&&end<=right) {
        tree[node] = (end-start+1) - tree[node];
        if(start != end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        return;
    }

    int mid = (start+end)/2;

    update_range(start, mid, node*2, left, right);
    update_range(mid+1, end, node*2+1, left, right);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int start, int end, int node, int left, int right) {
    update_lazy(start, end, node);

    if(right<start||end<left) return 0;

    if(left<=start&&end<=right) {
        return tree[node];
    }

    int mid = (start+end)/2;

    return query(start, mid, node*2, left, right) + query(mid+1, end, node*2+1, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    tree.assign(n*4, 0);
    lazy.assign(n*4, 0);

    vector<int> ans;
    while(m--) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;

        if(i1 == 0) {
            update_range(0, n-1, 1, i2-1, i3-1);
        }else {
            ans.push_back(query(0, n-1, 1, i2-1, i3-1));
        }
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}