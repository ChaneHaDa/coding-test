#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> dp(100001, 100000);
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;

    for(int i=6; i<100001; i++) {
        dp[i] = min(dp[i-2]+1, dp[i-5]+1);
    }

    int n;
    cin>>n;
    if(dp[n] >= 100000) {
        cout<<-1<<'\n';
    } else {
        cout<<dp[n]<<'\n';
    }
    
    return 0;
}