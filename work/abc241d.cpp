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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template<typename V>
void shrink_coordinates(V& a) {
	/*
	座標圧縮を行う関数
	(例)
	{6, 9, 9, 2, 100} -->  {1, 2, 2, 0, 3}
	*/
	V b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	V res(a.size());
	for(long long i = 0; i < a.size(); i++) {
		res.at(i) = lower_bound(b.begin(), b.end(), a.at(i)) - b.begin();
	}
	a = res;
}

int main() {
	ll q; cin >> q;
	vector<pair<ll, pll>> qs(q);
	vll co;
	rep(i, q) {
		ll t; cin >> t;
		if(t == 1) {
			ll x; cin >> x; qs[i] = {t, {x, -1}};
			co.push_back(x);
		}else{
			ll x, k; cin >> x >> k; qs[i] = {t, {x, k}};
			co.push_back(x);
		}
	}
	vll old = co;
	shrink_coordinates(co);
	map<ll, ll> ch1, ch2;
	rep(i, co.size()) ch1[old[i]] = co[i], ch2[co[i]] = old[i];
	rep(i, q) qs[i].second.first = ch1[qs[i].second.first]; //座圧
	set<ld> s1, s2;
	ld ep = 0;
	vll ans;
	rep(i, q) {
		ep += 1.0 / 300000;
		if(qs[i].first == 1) {
			ld x = qs[i].second.first; s1.insert(x + ep); s2.insert(-(x - ep)); //ムリヤリ重複を許すように調整
		}
		else if(qs[i].first == 2) {
			ld x = qs[i].second.first, k = qs[i].second.second; 
			auto it = s2.lower_bound(-x);
			bool flag = false;
			rep(j, k - 1) {
				if(it == s2.end()) {ans.push_back(-1); flag = true; break;}
				it++;
			}
			if(!flag) {
				if(it == s2.end()) ans.push_back(-1);
				else ans.push_back((ll)-(*it - 1));
			}
		}
		else if(qs[i].first == 3) {
			ld x = qs[i].second.first, k = qs[i].second.second;
			auto it = s1.lower_bound(x);
			bool flag = false;
			rep(j, k - 1) {
				if(it == s1.end()) {ans.push_back(-1); flag = true; break;}
				it++;
			}
			if(!flag) {
				if(it == s1.end()) ans.push_back(-1);
				else ans.push_back((ll)(*it));
			}
		}
	}
	for(auto au : ans) cout << (au == -1 ? -1 : ch2[au]) << endl;
}