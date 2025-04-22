#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int ans = 0;

    for(int idx = 0; idx < n; idx++){
        long long target = v[idx];
        int left = 0, right = n - 1;
        while(left < right){
            if(left == idx){
                left++;
                continue;
            }
            if(right == idx){
                right--;
                continue;
            }

            long long sum = v[left] + v[right];
            if(sum == target){
                ans++;
                break;
            }
            if(sum < target)  
                left++;
            else              
                right--;
        }
    }

    cout << ans << "\n";
    return 0;
}
