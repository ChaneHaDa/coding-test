    #include <iostream>
    #include <algorithm>
    #include <vector>
    using namespace std;

    vector<int> parent;

    int find(int x) {
        if(parent[x] != x) {
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

        int n, m;
        cin>>n>>m;

        parent.assign(n+1, 0);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }

        vector<tuple<int, int, int>> cost;
        while(m--) {
            int i1, i2, i3;
            cin>>i1>>i2>>i3;

            cost.push_back({i3, i1, i2});
        }
        sort(cost.begin(), cost.end());

        int ans = 0;
        int cnt = 0;
        for(auto [c, p1, p2] : cost) {
            if(!is_same_tree(p1, p2)) {
                ans += c;
                merge(p1, p2);
                cnt++;
            }
            if(cnt == n-2){
                break;
            }
        }

        if(n == 2){
            ans = 0;
        }

        cout<<ans<<'\n';

        return 0;
    }