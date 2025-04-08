#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

long long solve(vector<long long> &v, int n) {
    // idx, height
    long long mM = 0;
    stack<pair<int, long long>> s;
    for (int i = 0; i < n; i++) {
        int start = i;
        while (!s.empty() && s.top().second > v[i]) {
            int idx = s.top().first;
            long long height = s.top().second;
            s.pop();
            mM = max(mM, (long long)(i - idx) * height);
            start = idx;
        }
        s.push({start, v[i]});
    }

    while (!s.empty()) {
        int idx = s.top().first;
        long long height = s.top().second;
        s.pop();
        mM = max(mM, (long long)(n - idx) * height);
    }

    return mM;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<long long> ans;

    while(1) {
        int n;
        cin>>n;

        if(n==0) break;

        vector<long long> v(n, 0);
        for(int i=0; i<n; i++) {
            cin>>v[i];
        }

        ans.push_back(solve(v, n));
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}