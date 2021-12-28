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
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	string x; cin >> x;
	ll len = x.size(), sum = 0, cur = 0;
	rep(i, len) sum += x[i] - '0';
	string res;
	for(ll i = len - 1;;i--) {
		cur += sum; //(len - i)桁目は(first_)sum - (Σj=len-1 ~ len-i x[j]) + (下の桁の繰り上がり分)
		res.push_back('0' + cur % 10);
		cur /= 10; //次の桁に残しておく数
		if (i >= 0) sum -= (x[i] - '0');
		if(i <= 0 && cur == 0) break; //最後の桁まで使っている(i <= 0)かつ全ての数を消費し終えている(cur == 0)である事が終了条件
	}
	reverse(all(res));
	cout << res << endl;
}