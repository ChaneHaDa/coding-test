#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    string str;
    cin>>str;

    unordered_map<char, int> charIdx;
    charIdx['A'] = 0;
    charIdx['C'] = 1;
    charIdx['G'] = 2;
    charIdx['T'] = 3;

    int p[4];
    cin>>p[0]>>p[1]>>p[2]>>p[3];

    int c[4] = {0};
    for(int i=0; i<m; i++) {
        c[charIdx[str[i]]]++;
    }

    int ans=0;
    for(int i=m; i<n; i++) {
        if(c[0]>=p[0]&&c[1]>=p[1]&&c[2]>=p[2]&&c[3]>=p[3]) ans++;
        c[charIdx[str[i-m]]]--;
        c[charIdx[str[i]]]++;
    }
    if(c[0]>=p[0]&&c[1]>=p[1]&&c[2]>=p[2]&&c[3]>=p[3]) ans++;

    cout<<ans<<'\n';
    

    return 0;
}