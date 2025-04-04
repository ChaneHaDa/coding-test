#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m;
vector<int> arr;
set<vector<int>> s;
void dfs(int x, int cnt, vector<int> vec) {
    if(cnt == m) {
        s.insert(vec);
        return;
    }
    vec[cnt] = arr[x];

    for(int i=x; i<n; i++) {
        dfs(i, cnt+1, vec);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    arr.assign(n, 0);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    n=arr.size();
    for(int i=0; i<n; i++) {
        vector<int> vec(m, 0);
        dfs(i, 0, vec);
    }

    for(auto v:s) {
        for(auto i:v) {
            cout<<i<<' ';
        }
        cout<<'\n';
    }


    return 0;
}