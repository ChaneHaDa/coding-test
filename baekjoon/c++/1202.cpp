#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewels(n);
    for(int i=0; i<n; i++){
        cin >> jewels[i].first >> jewels[i].second;
    }
    vector<int> bags(k);
    for(int i=0; i<k; i++){
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    long long ans = 0;
    int idx = 0;
    for (int bag : bags) {
        while(idx < n && jewels[idx].first <= bag){
            pq.push(jewels[idx].second);
            idx++;
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}
