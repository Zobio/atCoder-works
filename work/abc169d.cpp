#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

bool isPrime(ll n) {
	for(ll i = 2; i * i <= n; i++) if(n % i == 0) return false;
	return true;
}

int main() {
	ll n; cin >> n;
	map<ll,ll> div;
	while(n > 1) {
		if(isPrime(n)) {div[n]++; break;}
		for(ll i = 2; i <= n; i++) {
			if(n % i == 0) {
				div[i]++;
				n /= i;
				break;
			}
		}
	}
	ll ans = 0;
	for(auto au : div) {
		ll l = 0, r = 10010;
		while(r - l > 1) {
			ll mid = (l + r) / 2;
			if(mid * (mid + 1) / 2 > au.second) r = mid;
			else l = mid;
		}
		ans += l;
	}
	cout << ans << endl;
}