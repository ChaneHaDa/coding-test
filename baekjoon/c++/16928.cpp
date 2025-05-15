#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    int map[101] = {0,};
    for(int i=0; i<n+m; i++) {
        int i1, i2;
        cin>>i1>>i2;
        map[i1] = i2;
    }

    int visit[101] = {0};
    queue<pair<int, int>> q;
    visit[0] = 1;
    q.push({1, 0});

    int ans = 0;
    while(!q.empty()) {
        auto [cx, cn] = q.front();
        q.pop();

        if(map[cx] != 0) {
            cx = map[cx];
        }

        if(cx == 100) {
            ans = cn;
            break;
        }

        for(int i=1; i<=6; i++) {
            if(cx+i <= 100) {
                if(visit[cx+i] == 0) {
                    q.push({cx+i, cn+1});
                    visit[cx+i] = 1; 
                }
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}