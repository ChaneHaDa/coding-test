#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;

    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x;
            cin>>x;
            graph[i][j] = (x == 1);
        }
    }


    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<graph[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}