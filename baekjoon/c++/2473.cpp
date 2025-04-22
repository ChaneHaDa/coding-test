#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<long long> v(n, 0);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    int start=0, end=n-1;
    long long cSum=LONG_LONG_MAX;
    vector<long long> ans(3, 0);

    for(int i=0; i<n-2; i++) {
        int start=i+1, end=n-1;
        while(start<end) {
            long long sum=v[i]+v[start]+v[end];
            
            if(abs(sum) < cSum) {
                ans[0] = v[i];
                ans[1] = v[start];
                ans[2] = v[end];
                cSum = abs(sum);
            }
            if(sum < 0) start++;
            else end--;
        }
    }

    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';

    return 0;
}