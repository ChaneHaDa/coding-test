#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<vector<int>> dp(101, vector<int>(101, 0));
    vector<vector<int>> v(101, vector<int>(101, 0));

    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int i1, i2;
        cin>>i1>>i2;

        v[i1][i2] = 1;
        v[i2][i1] = 1;
    }

    for (int i=1; i<=100; i++) {
        for (int j=i; j>=1; j--) {
            for (int k=j; k<i; k++) {
                dp[j][i] = max(dp[j][i], dp[j][k] + dp[k][i] + v[i][j]);
            }
        }
    }
        

    
    cout<<dp[1][100]<<'\n';

    return 0;
}