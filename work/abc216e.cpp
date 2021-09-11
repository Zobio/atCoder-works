#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll n, k; cin >> n >> k;
	vector<ll> a;
	rep(i, n) {
		ll tmp; cin >> tmp; a.push_back(tmp); 
	}
	sort(a.rbegin(), a.rend());
	ll ans = 0;
	auto it = a.begin();
	while(k && it != a.end() - 1) {
		//S = num * (n / 2) * (A + L) 公差1の等差数列
		ll num = it - a.begin() + 1; //何個動かすか
		ll N = *it - *(it + 1); //項数
		ll A = *(it + 1) + 1; //初項(楽しさがi + 1のアトラクションにのった後の楽しさはiなので+1しとく)
		ll L = *it; //末項
		ans += num * N * (A + L) / 2;
		k -= num * (*it - *(it + 1));
		//cout << it - a.begin() << " " << k << " " << ans << endl;
		if(k < 0) {
			// S = num * (n / 2) * (A + L) + (A + N) * (k % num)
			ll num = it - a.begin() + 1; //動かす数
			ll N = -k / (num); //項数
			ll A = *(it + 1) + 1; //初項
			ll L = A-1 + N; //末項
			ans -= num * N * (A + L) / 2;
			ans -= (A + N) * ((-k) % num);
			k = 0;
		}
		//cout << it - a.begin() << " " << k << " " << ans << endl;
		*it = *(it + 1);
		it++;
	}
	if(k) {
		// S = num * ((k / num) / 2) * (2a + (k / num) - 1) + (a * k / num) * (k % num)
		ll num = n; //動かすのは全部
		ll N = min(k / n, *it); //項数
		ll A = max(1ll, *it - N + 1); //初項
		ll L = A-1 + N; //末項
		ans += num * N * (A + L) / 2;
		ans += (L - N) * (k % num);
	}
	cout << ans << endl;
}