#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> dp(50001, 50000);
    for(int i=1; i<50001; i++) {
        if(i*i > 50000) {
            break;
        }
        dp[i*i] = 1;
    }

    for (int i=1; i<=50000; i++) {
        for (int j=1; j*j<=i; j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }

    int n;
    cin>>n;

    cout<<dp[n]<<'\n';

    return 0;
}