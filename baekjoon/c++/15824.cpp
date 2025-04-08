#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const long long MOD = 1000000007;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while(exp > 0) {
        if(exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<long long> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        long long add = modPow(2, i, MOD);
        long long sub = modPow(2, n - 1 - i, MOD);
        long long temp = (v[i] * add % MOD - v[i] * sub % MOD + MOD) % MOD;
        ans = (ans + temp) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
