#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

ll n;
vector<ll> memo;

ll f(ll num) {
	if(num == 0) return 0;
	if(memo[num]) return memo[num];
	ll res = INF;
	res = min(res, f(num - 1) + 1);
	ll now = 6ll;
	while(now <= num) res = min(res, f(num - now) + 1), now *= 6;
	now = 9ll;
	while(now <= num) res = min(res, f(num - now) + 1), now *= 9;
	memo[num] = res;
	return res;
}

int main() {
	cin >> n;
	memo.resize(n + 1, 0);
	cout << f(n) << endl;
}