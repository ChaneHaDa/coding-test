#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> v(n);
    long long max_val = 0;
    long long total_sum = 0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        max_val = max(max_val, v[i]);
        total_sum += v[i];
    }

    long long ans = total_sum;
    long long start = max_val;
    long long end = total_sum;
    long long mid = 0;

    while(start <= end) {
        mid = start + (end - start) / 2;

        long long sum = 0;
        long long cnt = 1;
        bool possible = true;

        for (int i = 0; i < n; i++) {
            if (v[i] > mid) {
                possible = false;
                break;
            }

            if (sum + v[i] > mid) {
                cnt++;
                sum = v[i];
            } else {
                sum += v[i];
            }
        }
        if (cnt <= m) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}