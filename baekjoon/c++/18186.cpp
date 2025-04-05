#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, b, c;
    cin>>n>>b>>c;
    
    vector<long long> v(n+3, 0);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    long long ans=0;

    if(b<=c) {
        for(auto i:v) {
            ans += i*b;
        }
    }else {
        for(int i=0; i<n; i++) {
            if(v[i+1]>v[i+2]) {
                long long cnt = min(v[i], v[i+1]-v[i+2]);
                ans += (b+c)*cnt;
                v[i] -= cnt;
                v[i+1] -= cnt;

                long long cnt1 = min(v[i], min(v[i+1], v[i+2]));
                ans += (b+2*c)*cnt1;
                v[i] -= cnt1;
                v[i+1] -= cnt1;
                v[i+2] -= cnt1;
            }else {
                long long cnt = min(v[i], min(v[i+1], v[i+2]));
                ans += (b+2*c)*cnt;
                v[i] -= cnt;
                v[i+1] -= cnt;
                v[i+2] -= cnt;

                long long cnt1 = min(v[i], v[i+1]);
                ans += (b+c)*cnt1;
                v[i] -= cnt1;
                v[i+1] -= cnt1;
            }

            ans += b*v[i];
            v[i] = 0;
        }
    }

    cout<<ans<<'\n';

    return 0;
}