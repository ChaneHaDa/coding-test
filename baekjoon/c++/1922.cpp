    #include <iostream>
    #include <algorithm>
    #include <vector>
    using namespace std;

    vector<int> parent;

    int find(int x) {
        if(x!=parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int pX = find(x);
        int pY = find(y);

        if(pX != pY) {
            parent[pX] = pY;
        }
    }

    bool is_same_tree(int x, int y) {
        return find(x) == find(y);
    }

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        int n;
        cin>>n;
        parent.assign(n+1, 0);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }

        int m;
        cin>>m;

        vector<tuple<int, int, int>> prices;
        while(m--) {
            int i1, i2, i3;
            cin>>i1>>i2>>i3;
            prices.push_back({i3, i1, i2});
        }

        int ans = 0;
        sort(prices.begin(), prices.end());
        int cnt=0;
        for(auto [c, x, y]:prices) {
            if(!is_same_tree(x, y)){
                merge(x, y);
                ans+=c;
                cnt++;
            }
            if(cnt == n-1) break;
        }

        cout<<ans<<'\n';

        return 0;
    }