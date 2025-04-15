#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

struct line {
	long long x1, x2, y1, y2;
};

int FindPar(int a, vector<int> &par) {
	if (par[a] == a) {
		return a;
	}
	return par[a] = FindPar(par[a], par);
}


long long CCW(pair<long long, long long> a, pair<long long, long long> b) {
	return a.first * b.second - a.second * b.first;
}

bool Meet(line a, line b) 
{
	pair<long long, long long> aV, bV;
	aV = make_pair(a.x2 - a.x1, a.y2 - a.y1);
	bV = make_pair(b.x2 - b.x1, b.y2 - b.y1);
	long long ACCW = CCW(aV, make_pair(b.x1 - a.x2, b.y1 - a.y2))* CCW(aV, make_pair(b.x2 - a.x2, b.y2 - a.y2));
	long long BCCW = CCW(bV, make_pair(a.x1 - b.x2, a.y1 - b.y2))* CCW(bV, make_pair(a.x2 - b.x2, a.y2 - b.y2));
	if (ACCW <= 0 && BCCW <= 0) {
		if (ACCW == 0 && BCCW == 0) {
			if (a.x1 == a.x2&& b.x2 == b.x1&&a.x2==b.x1) {
				return (min(a.y1, a.y2) <= max(b.y1, b.y2)) && (max(a.y1, a.y2) >= min(b.y1, b.y2));
			}
			return (min(a.x1, a.x2) <= max(b.x1, b.x2)) && (max(a.x1, a.x2) >= min(b.x1, b.x2));
		}
		return true;
	}

	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	
	vector<int> par(n);
	vector<line> lineV(n);
	for (int i = 0; i < n; i++) {
		par[i] = i;
		cin>>lineV[i].x1>>lineV[i].y1>>lineV[i].x2>>lineV[i].y2;
		for (int j = 0; j < i; j++) {
			if (Meet(lineV[i], lineV[j])) {
				int a = FindPar(i, par), b = FindPar(j, par);
				par[b] = min(a, b);
				par[a] = min(a, b);
			}
		}
	}
	set<int> parents;
	vector<int> groups(n,0);
	int maxAns = 0;
	for (int i = 0; i < n; i++) {
		int a = FindPar(i, par);
		parents.insert(a);
		groups[a] += 1;
		maxAns = max(maxAns, groups[a]);
	}
	cout << parents.size() << "\n" << maxAns;

	return 0;
}