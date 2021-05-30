#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n; ll k;
	cin >> n >> k;
	vector<pair<ll, ll>> fri;
	for(int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		fri.push_back(make_pair(a, b));
	}
	sort(fri.begin(), fri.end());
	ll now = 0;
	bool bre = false;
	for(int i = 0; i < n; i++) {
		if(fri[i].first - now > k) {
			now += k;
			bre = true;
			break;
		}
		k -= fri[i].first - now;
		k += fri[i].second;
		now = fri[i].first;
	}
	if(!bre) now += k;
	cout << now << endl;
}