#include <iostream>
using namespace std;

long long get_depth(long long x, long long k) {
    long long d = 0;
    while (x != 1) {
        x = (x - 2) / k + 1;
        d++;
    }
    return d;
}

long long lca(long long a, long long b, long long k) {
    while (a != b) {
        if (a > b) a = (a - 2) / k + 1;
        else       
        b = (b - 2) / k + 1;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, k, q;
    cin >> n >> k >> q;

    while (q--) {
        long long a, b;
        cin >> a >> b;

        if (k == 1) {
            cout << abs(a - b) << '\n';        
        }else {
            long long l = lca(a, b, k);
            long long d1 = get_depth(a, k);
            long long d2 = get_depth(b, k);
            long long dl = get_depth(l, k);
            cout << d1 + d2 - 2 * dl << '\n';
        }
    }

    return 0;
}
