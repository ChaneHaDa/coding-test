#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> v(4, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        cin>>v[0][i]>>v[1][i]>>v[2][i]>>v[3][i];
    }

    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            v1.push_back(v[0][i] +v[1][j]);
            v2.push_back(v[2][i] +v[3][j]);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int start = 0, end = v2.size()-1;
    long long ans=0;
    while(start < v1.size() && end >= 0) {
        int sum = v1[start] + v2[end];
        if(sum == 0) {
            long long cnt1 = 1, cnt2 = 1;
            int val1 = v1[start];
            int val2 = v2[end];
            
            start++;
            end--;
    
            while(start < v1.size() && v1[start] == val1) {
                cnt1++;
                start++;
            }
            while(end >= 0 && v2[end] == val2) {
                cnt2++;
                end--;
            }
            
            ans += cnt1 * cnt2;
        }
        else if(sum < 0) {
            start++;
        }
        else {
            end--;
        }
    }
    

    cout<<ans<<'\n';

    return 0;
}