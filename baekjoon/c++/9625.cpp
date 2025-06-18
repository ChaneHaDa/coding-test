#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;

    vector<int> v(2, 0);
    v[0] = 1;
    v[1] = 0;

    for(int i=0; i<n; i++) {
        int aN = v[0];
        int bN = v[1];

        v[0] = bN;
        v[1] = aN + bN;
    }

    cout<<v[0]<<" "<<v[1]<<'\n';

    return 0;
}