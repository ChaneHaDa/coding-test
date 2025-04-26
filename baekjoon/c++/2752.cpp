#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v(3, 0);
    cin>>v[0]>>v[1]>>v[2];

    sort(v.begin(), v.end());
    cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<'\n';

    return 0;
}