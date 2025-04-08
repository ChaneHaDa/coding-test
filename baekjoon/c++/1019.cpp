#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, cnt[10] = {}, add = 0;
    cin>>n;

    for(int i=1; n!=0; i*=10) {
        int curr = n%10;
        n /= 10;

        cnt[0] -= i;
        for(int j=0; j<curr; j++) cnt[j] += (n+1)*i;
        cnt[curr] += n*i + 1 + add;
        for(int j=curr+1; j<=9; j++) cnt[j] += n*i;

        add += curr*i;
    }

    for(int i=0; i<=9; i++) cout << cnt[i] << " ";

    return 0;
}
