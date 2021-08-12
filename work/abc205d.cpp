#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(i) cout << i << endl

vector<pair<ll, ll>> a;
vector<ll> k;
vector<ll> rui;

int main() {
	int n, q;
	cin >> n >> q;
	a.resize(n);
	k.resize(q);
	rui.resize(n);
	rep(i, n) cin >> a[i].first, a[i].second = a[i].first - i - 1;
	rep(i, q) cin >> k[i];
	rep(i, q) {
		if(k[i] > a[a.size() - 1].second) {
			cout << k[i] + n << endl;
			continue;
		}
		else if(k[i] <= a[0].second) {
			cout << k[i] << endl;
			continue;
		}
		ll left = 0, right = n + 1;
		while(right - left > 1) {
			ll mid = (right + left) / 2;
			if(a[mid].second > k[i]) right = mid;
			else left = mid;
		}
		while(left) {if(a[left].second == a[left - 1].second) left--; else break;}
		cout << a[left].first + (a[left].second - k[i]) - 1 << endl;
	}
}