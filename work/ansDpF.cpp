#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b; cin >> a >> b;
	vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
	for (int i = a.size() - 1; i >= 0; --i)
		for (int j = b.size() - 1; j >= 0; --j)
			dp[i][j] = max({(a[i] == b[j]) + dp[i + 1][j + 1], dp[i][j + 1], dp[i + 1][j]});
			for(int i = 0; i <= a.length(); i++) {
		for(int j = 0; j <= b.length(); j++) {
			cout << dp[i][j];
		}
		cout << endl;
	}
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (dp[i][j] == dp[i][j + 1])j++;
		else if (dp[i][j] == dp[i + 1][j])i++;
		else {
			cout << a[i];
			i++; j++;
		}
	}
}