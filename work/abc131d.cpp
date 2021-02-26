#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int tmp1, tmp2;
	cin >> n;
	vector<pair<int, int>> w(n);
	for(int i = 0; i < n; i++) {
		cin >> tmp2 >> tmp1;
		w[i] = make_pair(tmp1, tmp2);
	}
	sort(w.begin(), w.end());
	long long now = 0;
	for(int i = 0; i < n; i++) {
		now += w[i].second;
		if(now > w[i].first) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}