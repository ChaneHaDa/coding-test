#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<long long> dp(1000001, 0);
    dp[1] = 1;
    // 1+1, 2
    dp[2] = 2;
    // 1+1+1 1+2 2+1 3 
    dp[3] = 4;
    
    for(int i=4; i<=1000000; i++) {
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]) %  1000000009;
    }

    vector<long long> ans;
    for(int i=0; i<n; i++) {
        int i1;
        cin>>i1;
        ans.push_back(dp[i1]);
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}