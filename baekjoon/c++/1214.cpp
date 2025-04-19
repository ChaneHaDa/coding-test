#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long d, p, q;
    cin>>d>>p>>q;

    if(p<q) swap(p, q);

    long long ans=p;
    for(int i=0; i<=min(d/p, q); i++) {
        ans = min(ans, (q-(d-p*i)%q)%q);
    }
    ans = min(ans, (p-(d%p))%p);

    cout<<ans+d<<'\n';

    return 0;
}