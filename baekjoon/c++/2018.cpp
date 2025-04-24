#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    int left=1, right=1;
    int ans=1;
    int sum=1;
    while(right!=n) {
        if(sum==n){
            ans++;
            right++;
            sum += right;
        }else if(sum>n) {
            sum -= left;
            left++;
        }else {
            right++;
            sum += right;
        }
    }

    cout<<ans<<'\n';

    return 0;
}