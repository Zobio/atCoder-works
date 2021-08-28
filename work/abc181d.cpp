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
	string s; cin >> s;
	if(s.size() == 1) {cout << (s == "8" ? "Yes" : "No") << endl; return 0;}
	if(s.size() == 2) {
		if(stoi(s) % 8 == 0){cout << "Yes" << endl; return 0;}
		reverse(s.begin(), s.end());
		if(stoi(s) % 8 == 0) {cout << "Yes" << endl; return 0;}
		else cout << "No" << endl; return 0;
	}
	map<ll, ll> mp;
	ll even = 0, odd = 0;
	rep(i, s.size()) {mp[s[i] - '0']++; if((s[i] - '0') % 2 == 0) even++; else odd++;}
	for(ll i = 12; i <= 96; i+=4) {
		if(!mp[i / 10] || !mp[i % 10]) continue;
		else if(i / 10 == i % 10 && mp[i / 10] < 2) continue;
		if(i % 8 == 0) {
			if (even - ((i / 10) % 2 == 0) - ((i % 10) % 2 == 0) > 0) {
				cout << "Yes" << endl; return 0;
			}
		}else{
			if (odd - ((i / 10) % 2) - ((i % 10) % 2) > 0) {
				cout << "Yes" << endl; return 0;
			}
		}
	}
	cout << "No" << endl;
}