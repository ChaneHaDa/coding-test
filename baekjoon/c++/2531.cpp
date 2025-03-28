#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int ans=0;

    int n, d, k, c;
    cin>>n>>d>>k>>c;
    
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    unordered_map<int, int> numCount;
    unordered_set<int> numSet;
    numSet.insert(c);

    for(int i=0; i<k; i++){
        numSet.insert(arr[i]);
        numCount[arr[i]]++;
    }

    ans = numSet.size();

    for(int i=0; i<n; i++){
        int addNum = arr[(i+k)%n];
        int removeNum = arr[i];
        
        numSet.insert(addNum);
        numCount[addNum]++;

        if(removeNum != c) {
            numCount[removeNum]--;
            if(numCount[removeNum] == 0) {
                numSet.erase(removeNum);
            }
        }

        ans = ans > numSet.size() ? ans : numSet.size();
    }

    cout<<ans;

    delete[] arr;

	return 0;
}