#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    double a, b;
    cin>>a>>b;

    cout<<fixed;
    cout.precision(9);
    cout<<a/b<<'\n';

    return 0;
}