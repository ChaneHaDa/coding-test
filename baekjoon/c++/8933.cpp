#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

string map_to_str(unordered_map<char, int> &charCnt) {
    string str = "";

    for(auto p:charCnt) {
        char c = p.first;
        int i = p.second;

        str+= c;
        str += to_string(i);
    }


    return str;
}

int find_mcs(int k, string w) {
    if(w.size() < k) {
        return 0;
    }

    unordered_map<char, int> charCnt = {
        {'A', 0},
        {'G', 0},
        {'T', 0},
        {'C', 0}
    };
    unordered_map<string, int> strCnt;

    for(int i=0; i<k; i++) {
        charCnt[w[i]]++;
    }
    strCnt[map_to_str(charCnt)]++;

    for(int i=0; i<w.size(); i++) {
        if(i+k >= w.size()) break;

        char removeCh = w[i];
        char addCh = w[i+k];

        charCnt[removeCh]--;
        charCnt[addCh]++;

        strCnt[map_to_str(charCnt)]++;
    }

    int ans = 0;

    for(auto p:strCnt) {
        ans = max(ans, p.second);
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int T;
    cin>>T;

    vector<int> ans;
    while(T--) {
        int k;
        string w;
        cin>>k>>w;

        ans.push_back(find_mcs(k, w));
    }

    for(auto i:ans) {
        cout<<i<<endl;
    }

	return 0;
}