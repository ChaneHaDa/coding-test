#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n;
    cin>>m;

    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int ans=0;
    
    for(int left=0; left<n; left++) {
        for(int right=left+1; right<n; right++) {
            if(arr[left]+arr[right] == m) ans++;
        }
    }

    cout<<ans<<'\n';

    return 0;
}