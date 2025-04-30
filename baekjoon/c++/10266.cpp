#include <iostream>
#include <vector>
#include <string>
#define MAX 360000

using namespace std;

vector<int> getpi(vector<bool> pattern) {

	vector<int> pi(pattern.size(), 0);
	int j = 0;

	for (int i = 1; i < pattern.size(); i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

string kmp(vector<bool> text, vector<bool> pattern) {

	vector<int> pi = getpi(pattern);
	int j = 0;

	for (int i = 0; i < text.size(); i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				return "possible\n";
			}
			else
				j++;
		}
	}
	return "impossible\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
	vector<bool> clock1(MAX * 2, 0);
	vector<bool> clock2(MAX, 0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		clock1[num] = clock1[MAX+num] = 1;
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		clock2[num] = 1;
	}

	cout << kmp(clock1, clock2)<<'\n';

    return 0;
}