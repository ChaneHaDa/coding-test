#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        string str;
        cin>>str;
        for(int j=0; j<m; j++) {
            v[i][j] = int(str[j]-'0');
        }
    }

    vector<vector<int>> g(n, vector<int>(m, 0));
    vector<vector<bool>> visit(n, vector<bool>(m, 0));
    unordered_map<int, int> gNum;
    gNum[0]=0;

    int gCnt = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j] == 0 && visit[i][j] == false) {
                int cnt=1;
                queue<pair<int, int>> q;
                q.push({i, j});
                visit[i][j] = true;
                g[i][j] = gCnt;

                while(!q.empty()) {
                    auto [cx, cy] = q.front();
                    q.pop();

                    for(int i=0; i<4; i++) {
                        int nx = cx + dx[i];
                        int ny = cy + dy[i];

                        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                        
                        if(visit[nx][ny] == false && v[nx][ny] == 0) {
                            cnt++;
                            visit[nx][ny] = true;
                            g[nx][ny] = gCnt;
                            q.push({nx, ny});
                        }
                    }
                }
                gNum[gCnt] = cnt;
                gCnt++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j] == 1) {
                int pD = 1;
                unordered_set<int> accG;
                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    accG.insert(g[nx][ny]);
                }

                for(auto group:accG) {
                    pD += gNum[group];
                }

                v[i][j] = pD%10;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<v[i][j];
        }
        cout<<'\n';
    }


    return 0;
}