#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, l;
    cin>>n>>l;

    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> ans;
    deque<pair<int, int>> dq;

    for(int i=0; i<n; i++) {
        while (!dq.empty() && (dq.front().first < i-l+1))
            dq.pop_front();

        while (!dq.empty() && (dq.back().second >= arr[i]))
            dq.pop_back();
        
        dq.push_back({i, arr[i]});

        ans.push_back(dq.front().second);
    }

    for(auto p:ans){
        cout<<p<<' ';
    }
    cout<<'\n';

    return 0;
}