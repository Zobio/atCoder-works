#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	string n; cin >> n;
	ll di = n.size();
	sort(n.begin(), n.end());
	ll ans = 0;
	do{
		rep(i, di - 1) {
			string a = n.substr(0, i + 1);
			string b = n.substr(i + 1, di - i);
			sort(all(a)); sort(all(b)); reverse(all(a)); reverse(all(b));
			if(a[0] == 0 || b[0] == 0) continue;
			chmax(ans, stoll(a) * stoll(b));
		}
	}while(next_permutation(all(n)));
	cout << ans << endl;
}