#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<string> maps;
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;
        maps.push_back(s);
    }

    int dp[1001][1001] = {0,};
    int ans = 0;

    for(int i=1 ; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(maps[i-1][j-1] == '1') {
                int minV = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                dp[i][j] = minV+1;
                ans = max(dp[i][j], ans);
            }
        }
    }

    cout<<ans*ans<<'\n';


    return 0;
}