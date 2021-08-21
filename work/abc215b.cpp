#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 1LL << 60

int main() {
	ll n; cin >> n;
	ll ans = 0;
	ll now = 2;
	while(n >= now) now *= 2, ans++;
	cout << ans << endl;
}