#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> ball;
	int iti = 0;
	int minus = 0;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ball.push_back(make_pair(b, a));
	}
	sort(ball.begin(), ball.end());
	vector<pair<int, int>> top();
	ll ans = ball[0].second;
	for(int i = 1; i < n; i++) {
		ans += abs(ball[i - 1].second - ball[i].second);
	}
	int now = ball[0].first;
	for(int i = 1; i < n; i++) {
		if(ball[i - 1].first == ball[i].first) continue;
		if(ball[i - 1].second >= ball[i].second) {
			ans -= ball[i - 1].second - ball[i].second;
		}
	}
	ans += abs(ball[n - 1].second);
	cout << ans << endl;
}