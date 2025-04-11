#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int solve() {
    int l;
    cin>>l;

    int sx, sy;
    cin>>sx>>sy;

    int ex, ey;
    cin>>ex>>ey;

    vector<vector<bool>> maps(l, vector<bool>(l, false));
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    maps[sx][sy] = true;

    while(!q.empty()) {
        auto [cx, cy, cd] = q.front();
        q.pop();

        if(cx==ex && cy==ey) return cd; 

        for(int i=0; i<8; i++) {
            int nx = dx[i]+cx;
            int ny = dy[i]+cy;

            if(nx<0||nx>=l||ny<0||ny>=l) continue;
            
            if(!maps[nx][ny]) {
                q.push({nx, ny, cd+1});
                maps[nx][ny] = true;
            }
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    vector<int> ans;
    while(t--) {
        ans.push_back(solve());
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}