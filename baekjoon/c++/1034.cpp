#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;
    
    vector<string> lamp(n, "");
    for(int i=0; i<n; i++) {
        cin>>lamp[i];
    }

    int k;
    cin>>k;

    int ans=0;
    for(int i=0;i<n;i++){
        auto s = lamp[i];
        int cnt=0;
        for(int j=0;j<m;j++) 
            if(s[j]=='0') cnt++;

        if(cnt > k || cnt%2 != k%2) 
            continue;
            
        int sameCnt=0;
        for(int j=0;j<n;j++) 
            if(s==lamp[j]) 
                sameCnt++; 

        ans=max(ans,sameCnt);
    }

    cout<<ans<<'\n';

    return 0;
}