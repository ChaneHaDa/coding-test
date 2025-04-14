#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define X first
#define Y second

vector<pll> v;

ll ccw(pll a, pll b, pll c) {
    ll res = a.X * b.Y + b.X * c.Y + c.X * a.Y;
    res -= (b.X * a.Y + c.X * b.Y + a.X * c.Y);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

void findIntersection(pll a, pll b, pll c, pll d) {
    double px = (a.X * b.Y - a.Y * b.X) * (c.X - d.X) - (a.X - b.X) * (c.X * d.Y - c.Y * d.X);
    double py = (a.X * b.Y - a.Y * b.X) * (c.Y - d.Y) - (a.Y - b.Y) * (c.X * d.Y - c.Y * d.X);
    double denom = (a.X - b.X) * (c.Y - d.Y) - (a.Y - b.Y) * (c.X - d.X);

    if (denom == 0) {
        if (b == c && a <= c) cout << b.X << " " << b.Y << '\n';
        else if (a == d && c <= a) cout << a.X << " " << a.Y << '\n';
    } else {
        double x = px / denom;
        double y = py / denom;
        cout << fixed;
        cout.precision(9);
        cout << x << " " << y;
    }
}

void solve(pll a, pll b, pll c, pll d) {
    ll chk1 = ccw(a, b, c) * ccw(a, b, d);
    ll chk2 = ccw(c, d, a) * ccw(c, d, b);

    if (chk1 == 0 && chk2 == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        if (a <= d && b >= c) {
            cout << 1 << '\n';
            findIntersection(a, b, c, d);
        } else {
            cout << 0 << '\n';
        }
    } else {
        if (chk1 <= 0 && chk2 <= 0) {
            cout << 1 << '\n';
            findIntersection(v[0], v[1], v[2], v[3]);
        } else {
            cout << 0 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 4; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    solve(v[0], v[1], v[2], v[3]);
    return 0;
}
