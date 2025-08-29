#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long x, y;
    cin>>x>>y;

    long long ans = -1;
    long long start=0, end=x, mid;

    int z = y*100/x;

    while(start<=end) {
        mid = (start+end)/2;
        int tempZ = (y+mid) *100/(x+mid);

        if(tempZ-z > 0) {
            ans = mid;
            end = mid - 1;
        }else {
            start = mid + 1;
        }

    }
    
    cout<<ans<<'\n';

    return 0;
}