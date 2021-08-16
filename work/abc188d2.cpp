#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n; cin >> n;
	ll C; cin >> C;
	map<ll, ll> imo;
	rep(i, n) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		imo[a] += c;
		imo[b] -= c;
	}
	ll ans = 0, price = 0, now = 0;
	for(auto i = imo.begin(); i != imo.end(); i++) {
		ans += (i->first - now) * min(price, C); //1個前から今回の区間分の料金を足す(初回は0)
		price += i -> second;
		now = i->first;
		//最後はprice == 0になるはずなので一番最後の区間について考える必要はない
	}
	cout << ans << endl;
}