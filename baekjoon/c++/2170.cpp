#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    
    vector<pair<long long, long long>> v;
    for(int i=0; i<n ;i++) {
        int i1, i2;
        cin>>i1>>i2;

        v.push_back({i1, i2});
    }

    sort(v.begin(), v.end());
    long long start=v[0].first, end=v[0].second;
    long long ans = 0;
    for(int i=1; i<n; i++) {
        auto [nStart, nEnd] = v[i];

        if(nStart <= end){
            end = max(nEnd, end);
        }else {
            ans += end-start;
            start = nStart;
            end = nEnd;
        }
    }

    ans += end-start;
    cout<<ans<<'\n';

    return 0;
}