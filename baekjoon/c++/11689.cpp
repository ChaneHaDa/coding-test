#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, ans;
	cin>>n;
	ans = n;

	for(long long i=2; i*i<=n; i++) {
		if (n%i != 0) continue;
		ans -= ans/i;
		while (n%i == 0) n/=i;
	}

	if(n>1) ans -= ans/n;
	cout<<ans;

	return 0;
}
