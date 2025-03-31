#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> ans;

vector<int> parent;
vector<int> gSize;

int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y){
    int pX = find(x);
    int pY = find(y);

    if(pX != pY) {
        parent[pX] = pY;
        gSize[pY] += gSize[pX];
    }
}

void sol(vector<pair<string, string>> p) {
    parent.assign(p.size()*2+1, 0);
    gSize.assign(p.size()*2+1, 1);

    for(int i=0; i<p.size()*2+1; i++) {
        parent[i] = i;
    }

    unordered_map<string, int> m;
    int idx = 0;

    for(auto i:p) {
        string s1 = i.first;
        string s2 = i.second;

        if (m.find(s1) == m.end()) {
            m[s1] = idx++;
        }
        if (m.find(s2) == m.end()) {
            m[s2] = idx++;
        }

        merge(m[s1], m[s2]);

        ans.push_back(gSize[find(m[s1])]);   
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    while(t--) {
        int k;
        cin>>k;
        vector<pair<string, string>> input;
        while(k--) {
            string s1, s2;
            cin>>s1>>s2;
            input.push_back({s1, s2});
        }
        sol(input);
    }

    for(auto i:ans) {
        cout<<i<<'\n';
    }

    return 0;
}