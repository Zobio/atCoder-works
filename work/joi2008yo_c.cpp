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
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	vll t(n); vll h;
	rep(i, n) cin >> t[i];
	sort(all(t));
	reps(i, 2 * n) if(!binary_search(all(t), i)) h.push_back(i);
	ll card = 0; //机に置かれているカード
	bool tturn = true;
	while(t.size() && h.size()) {
		if(tturn) {
			vll::iterator it = upper_bound(all(t), card);
			if (it == t.end()) card = 0;
			else {
				card = *it;
				t.erase(it);
			}
		}else{
			vll::iterator it = upper_bound(all(h), card);
			if (it == h.end()) card = 0;
			else {
				card = *it;
				h.erase(it);
			}
		}
		tturn = !tturn;
	}
	cout << h.size() << endl << t.size() << endl; //"相手の"残り枚数だからtとhは逆
}