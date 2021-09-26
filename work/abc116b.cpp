#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll s; cin >> s;
	map<ll, bool> mp;
	mp[s] = true;
	ll cnt = 1, now = s;
	while(true) {
		cnt++;
		if(now & 1) now = 3ll * now + 1;
		else now /= 2;
		if(mp[now]) {cout << cnt << endl; return 0;}
		mp[now] = true;
	}
}