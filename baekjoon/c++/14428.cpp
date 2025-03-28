#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

vector<int> arr;
vector<pair<int, int>> segTree;

pair<int, int> initTree(int start, int end, int node) {
    if(start == end) {
        return segTree[node] = {arr[start], start};
    }

    int mid = (start+end)/2;

    return segTree[node] = min(initTree(start, mid, node*2), initTree(mid+1, end, node*2+1));
}

pair<int, int> findMinIndex(int start, int end, int node, int left, int right) {
    if(right < start || left > end) return {INT_MAX, INT_MAX};

    if(left<=start && end<=right) return segTree[node];
    
    int mid=(start+end) / 2;
    return min(findMinIndex(start, mid, node*2, left, right), findMinIndex(mid+1, end, node*2+1, left, right));
}

void update(int start, int end, int node, int idx, int val) {
    if(start > idx || end < idx) return;
    if(start == end) {
        segTree[node] = {val, idx};
        return;
    }
    int mid = (start+end)/2;
    update(start, mid, node*2, idx, val);
    update(mid+1, end, node*2+1, idx, val);

    segTree[node] = min(segTree[node*2], segTree[node*2+1]);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    arr.assign(n+1, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    segTree.assign(n*4, {0, 0});
    initTree(0, n-1, 1);

    int m;
    cin>>m;
    
    vector<int> ans;
    for(int i=0; i<m; i++) {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;
        if(i1 == 1)
        {
            update(0, n-1, 1, i2-1, i3);
        }
        else
        {
            ans.push_back(findMinIndex(0, n-1, 1, i2-1, i3-1).second);
        }
    }

    for(int i:ans){
        cout<<i+1<<'\n';
    }

	return 0;
}