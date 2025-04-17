#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <climits>
using namespace std;

int dis(pair<int, int> p1, pair<int, int> p2) {
    return pow((p1.first-p2.first),2) + pow((p1.second-p2.second),2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;

    vector<pair<int, int>> p;
    for(int i=0; i<n; i++) {
        int i1, i2;
        cin>>i1>>i2;

        p.push_back({i1, i2});
    }

    sort(p.begin(), p.end());

    set<pair<int, int>> s;
    s.insert({p[0].second, p[0].first});
    s.insert({p[1].second, p[1].first});

    int mini = dis(p[0], p[1]);
    int idx = 0;

    for(int i=2; i<n; ++i) {
        while (idx < i) {
            int d = p[i].first - p[idx].first;
            if (d * d <= mini) break;
            else
            {
                s.erase({ p[idx].second, p[idx].first });
                idx++;
            }
        }

        auto start = s.lower_bound({ p[i].second - sqrt(mini), -INT_MAX });
        auto end = s.upper_bound({ p[i].second + sqrt(mini), INT_MAX });
        for (auto it = start; it != end; it++)
            mini = min(mini, dis({ it->second, it->first }, p[i]));
        s.insert({ p[i].second, p[i].first });
    }

    cout<<mini<<'\n';

    return 0;
}