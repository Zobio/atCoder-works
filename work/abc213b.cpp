#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

int main() {
	int n;
	cin >> n;
	vector<pair<ll, ll>> a;
	rep(i, n) {
		ll tmp;
		cin >> tmp;
		a.push_back(make_pair(tmp, i));
	}
	sort(a.begin(), a.end());
	cout << a[a.size() - 2].second + 1 << endl;
}