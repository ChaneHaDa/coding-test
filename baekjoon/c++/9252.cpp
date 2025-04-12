#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1, s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int lenLcs = dp[n][m];
    cout<<lenLcs<<'\n';
    if(lenLcs==0){
        return 0;
    }

    string strLcs = "";
    int i=n, j=m;
    while(i>0 && j>0) {
        if(s1[i-1] == s2[j-1]) {
            strLcs = s1[i-1] + strLcs;
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }else {
            j--;
        }
    }

    cout<<strLcs<<'\n';

    return 0;
}