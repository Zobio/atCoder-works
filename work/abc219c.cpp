#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	string s; cin >> s;
	ll n; cin >> n;
	vector<pair<string, string>> l(n);
	rep(i, n) cin >> l[i].second;
	map<char, char> mp;
	rep(i, 26) mp[s[i]] = 'a' + i;
	rep(i, n) rep(j, l[i].second.size()) {
		//新しい文字列を作る
		l[i].first.push_back(mp[l[i].second.at(j)]);
	}
	sort(l.begin(), l.end());
	rep(i, n) cout << l[i].second << endl;
}