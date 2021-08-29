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
	ll n; cin >> n;
	string ans;
	while(n) {
		if(n & 1) ans.push_back('A'), n--;
		else ans.push_back('B'), n /= 2;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}