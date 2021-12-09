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
	ll n, a, b; cin >> n >> a >> b;
	ll p, q, r, s; cin >> p >> q >> r >> s;//[p, q], [r, s]
	pair<ll, ll> one = {-1,-1}, two;
	vector<vector<char>> ans(q - p, vector<char>(s - r));
	if(p <= r + a - b && r + a - b <= q) one = {r - 1, r + a - b - 1};
	else if(r <= p - a + b && p - a + b <= s) one = {p - a + b - 1, p - 1};
	cout << one.first << " " << one.second << endl;
	if(p <= -r + n - a - b && -r + n - a - b <= q) two = {r - 1, -r + n - a - b - 1};
	else if(r <= -p + n - a - b && -p + n - a - b <= s) two = {-p + n - a - b - 1, p - 1};
	cout << two.first << " " << two.second << endl;
}