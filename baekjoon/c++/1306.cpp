#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int *arr;
int *segTree;

int init(int start, int end, int node) {
    if(start == end) {
        return segTree[node] = arr[start];
    }
    int mid = (start+end)/2;

    return segTree[node] = max(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

int find_max(int start, int end, int node, int left, int right) {
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) {
        return segTree[node];
    }
    int mid = (start+end)/2;

    return max(find_max(start, mid, node*2, left, right), find_max(mid+1, end, node*2+1, left, right));
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    arr = new int[n];
    segTree = new int[n*4];
    vector<int> ans;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    init(0, n-1, 1);

    for (int i = m - 1; i <= n - m; i++) {
        int left = i - (m - 1);        
        int right = i + (m - 1);
        ans.push_back(find_max(0, n - 1, 1, left, right));
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] segTree;

	return 0;
}