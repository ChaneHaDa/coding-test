#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int col[15];
int n, ans = 0;

bool check(int level) {
    for(int i = 0; i < level; i++)
        if(col[i]==col[level] || abs(col[level]-col[i])==level-i) return false;
    return true;
}

void nqueen(int x) {
    if(x==n) ans++;
    else {
        for(int i=0; i<n; i++){
            col[x]=i;
            if(check(x)) nqueen(x+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    nqueen(0);

    cout<<ans<<'\n';

    return 0;
}