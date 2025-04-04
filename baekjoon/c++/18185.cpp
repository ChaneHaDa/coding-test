#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<int> v(n+3, 0);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    int ans=0;

    for(int i=0; i<n; i++){
        if(v[i+1] > v[i+2]) {
            int c = min(v[i], v[i+1]-v[i+2]);
            ans += 5*c;
            v[i] -= c;
            v[i+1] -= c;

            int c1 = min(v[i], min(v[i+1], v[i+2]));
            ans += 7*c1;
            v[i] -= c1;
            v[i+1] -= c1;
            v[i+2] -= c1;
        }else {
            int c = min(v[i], min(v[i+1], v[i+2]));
            ans += 7*c;
            v[i] -= c;
            v[i+1] -= c;
            v[i+2] -= c;

            int c1 = min(v[i], v[i+1]);
            ans += 5*c1;
            v[i] -= c1;
            v[i+1] -= c1;
        }

        ans += 3*v[i];
        v[i] = 0;
    }  

    cout<<ans<<'\n';

    return 0;
}