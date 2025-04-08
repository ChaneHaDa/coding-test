#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(m, vector<int>(n, 0));
    for(int i=0; i<m; i++) {
        string s;
        cin>>s;
        for(int j=0; j<n; j++) {
            v[i][j] = s[j]-'0';
        }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> visit(m, vector<int>(n, INT_MAX));
    pq.push({0, {0, 0}});
    visit[0][0] = 0;

    while(!pq.empty()) {
        auto [cCost, cPoint] = pq.top();
        auto [cX, cY] = cPoint;
        cCost *= -1;
        pq.pop();
        
        if(cX == m - 1 && cY == n - 1) {
            break;
        }

        for(int i=0; i<4; i++) {
            int nX = cX+dx[i];
            int nY = cY+dy[i];
            int nCost = cCost;

            if(nX<0||nX>=m||nY<0||nY>=n) continue;

            if(v[nX][nY] == 1) nCost+=1;

            if(visit[nX][nY] > nCost) {
                visit[nX][nY] = nCost;
                pq.push({-nCost, {nX, nY}});
            }
        }
    }

    cout<<visit[m-1][n-1]<<'\n';

    return 0;
}