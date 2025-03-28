#include <iostream>
using namespace std;

int main() {

    int n;
    cin>>n;

    int cur=1, pre1=1, ncur=0;

    for(int i=3; i<=n; i++) {
        ncur = pre1+cur;
        pre1 = cur;
        cur = ncur;
    }

    int ans = (n==0) ? 0 : (n==1 || n==2) ? 1 : cur;

    cout<<cur<<endl;

    return 0;
}