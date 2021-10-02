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
	string a, b; cin >> a >> b;
	string ans = "No";
	if(a == b) ans = "Yes";
	rep(i, a.size() - 1) {
		if(i > 0) {
			swap(a[i], a[i - 1]);
			if(a == b) ans = "Yes";
			swap(a[i], a[i - 1]);
		}
		if(i + 1 < a.size()) {
			swap(a[i], a[i + 1]);
			if(a == b) ans = "Yes";
			swap(a[i], a[i + 1]);
		}
	}
	cout << ans << endl;
}