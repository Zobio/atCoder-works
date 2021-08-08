#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<pair<pair<ll, ll> , ll>> li(n);
	rep(i, n) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		li[i] = make_pair(make_pair(a, b), i);
	}
	sort(li.begin(), li.end());
	vector<pair<pair<ll, ll>, ll>> cp = li;
	ll minus = cp[0].first.first;
	for(int i = 0; i < n; i++) {
		if(i && cp[i].first.first - cp[i - 1].first.first != 0) minus += cp[i].first.first - cp[i - 1].first.first - 1;
		li[i].first.first -= minus;
		//cout << li[i].first.first << " " << li[i].first.second << " " << li[i].second << endl;
	}
	//cout << endl;
	cp = li;
	for(int i = 0; i < n; i++) {
		swap(cp[i].first.first, cp[i].first.second);
		//cout << cp[i].first.first << " " << cp[i].first.second << " " << cp[i].second << endl;
	}

	sort(cp.begin(), cp.end());
	li = cp;
	minus = cp[0].first.first;
	//cout << endl;
	for(int i = 0; i < n; i++) {
		if(i && cp[i].first.first - cp[i - 1].first.first != 0) minus += cp[i].first.first - cp[i - 1].first.first - 1;
		//cout << li[i].first.first << " " << li[i].first.second << " " << li[i].second <<  "-->";
		li[i].first.first -= minus;
		//cout << li[i].first.first << " " <<  li[i].first.second << " " << li[i].second <<  endl;
	}
	for(int i = 0; i < n; i++) {
		swap(li[i].first.first, li[i].second);
		//cout << "second; " << li[i].first.first << endl;
	}
	sort(li.begin(), li.end());
	for(int i = 0; i < n; i++) {
		cout << li[i].first.second + 1 << " " << li[i].second + 1 << endl;
		//first.secondに行の情報、secondに列の情報
	}
}