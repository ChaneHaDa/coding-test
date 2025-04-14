#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int blankCnt = 0;

bool is_complete(vector<vector<int>>& maps) {
    for(auto row : maps) {
        for(auto col : row) {
            if(col == 0) return false;
        }
    }
    return true;
}

int bfs(int n, vector<vector<int>> maps, vector<pair<int, int>> virus) {
    int time = 0;

    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visit(n, vector<bool>(n, false));

    for(auto [x, y]:virus) {
        q.push({x, y, 1});
        visit[x][y] = true;
    }

    int cnt=0;
    while(!q.empty()) {
        auto [cx, cy, ct] = q.front();
        q.pop();

        if(blankCnt == cnt) {
            break;
        }

        time = max(time, ct);

        for(int i=0; i<4; i++) {
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(visit[nx][ny]) continue;

            if(maps[nx][ny] == 0 || maps[nx][ny] == 2) {
                visit[nx][ny] = true;
                q.push({nx, ny, ct + 1});
                if(maps[nx][ny] == 0) cnt++;
            }
        }
    }

    if(cnt == blankCnt) {
        return time;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<pair<int, int>> virus; 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>v[i][j];
            if(v[i][j] == 2) {
                virus.push_back({i, j});
            }else if(v[i][j] == 0) {
                blankCnt++;
            }
        }
    }

    int ans = -1;
    vector<int> t(virus.size(), 0);
    fill(t.end()-m, t.end(), 1);
    do {
        vector<pair<int, int>> selectVirus;
        for(int i=0; i<t.size(); i++) {
            if(t[i]) {
                selectVirus.push_back(virus[i]);
            }
        }
        int t = bfs(n, v, selectVirus);
        if(t != -1) {
            if(ans == -1) {
                ans = t;
            }else {
                ans = min(ans, t);
            }
        }
    } while(next_permutation(t.begin(), t.end()));

    cout<<ans<<'\n';

    return 0;
}