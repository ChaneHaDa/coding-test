#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    long long ans = 0;
    stack<pair<int, int>> s;
    for(int i=0; i<n; i++) {
       int h;
       cin>>h;

       int cnt=1;

       while(!s.empty() && s.top().first < h) {
            ans += s.top().second;
            s.pop();
       }

        if(!s.empty()) {
            if(s.top().first == h) {
                ans += s.top().second;
                cnt += s.top().second;

                if(s.size() > 1) ans++;

                s.pop();
            }else {
                ans++;
            }
        }
        s.push({h, cnt});
    }

    cout<<ans<<'\n';

    return 0;
}