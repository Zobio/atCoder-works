#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

vector<vector<ll>> fix(vector<vector<ll>> a) {
	ll leftMin = 2000, upMin = 2000;
	int siz = a.size();
	rep(i, siz) {
		ll cnt = 0;
		while(cnt < siz) {if(!a[cnt][i]) cnt++; else break;}
		upMin = min(upMin, cnt);
	}
	rep(i, siz) {
		ll cnt = 0;
		while(cnt < siz) {if(!a[i][cnt]) cnt++; else break;}
		leftMin = min(leftMin, cnt);
	}
	vector<vector<ll>> ret(siz, vector<ll>(siz));
	for(ll i = upMin; i < siz; i++) {
		for(ll j = leftMin; j < siz; j++) {
			ret[i - upMin][j - leftMin] = a[i][j];
		}
	}
	return ret;
}
vector<vector<ll>> kaiten(vector<vector<ll>> b) {
	int siz = b.size();
	vector<vector<ll>> c(siz, vector<ll>(siz));
	rep(i, siz) rep(j, siz) c[i][j] = b[j][siz - i - 1];
	return c;
}

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> a(n, vector<ll>(n));
	vector<vector<ll>> b(n, vector<ll>(n));
	rep(i, n) {
		string s; cin >> s;
		rep(j, n) a[i][j] = s[j] == '#' ? 1 : 0;
	}
	rep(i, n) {
		string s; cin >> s;
		rep(j, n) b[i][j] = s[j] == '#' ? 1 : 0;
	}
	rep(i, 4) {
		bool flag = true;
		vector<vector<ll>> aa = fix(a);
		vector<vector<ll>> bb = fix(b);
		rep(ii, n) rep(jj, n) if(aa[ii] != bb[ii]) flag = false;
		if(flag) {cout << "Yes" << endl; return 0;}
		b = kaiten(b);
	}
	cout << "No" << endl; return 0;
}