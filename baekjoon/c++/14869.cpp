#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n, m, s, e, t;
    cin>>n>>m>>s>>e>>t;
    
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    vector<int> reject(n);
    for(int i=0; i<n; i++){
        cin>>reject[i];
    }


	return 0;
}