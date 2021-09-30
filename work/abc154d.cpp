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

int main() {
	ll n, k; cin >> n >> k;
	vector<double> p(n); rep(i, n) cin >> p[i];
	vector<double> ave_tousaSum(n); rep(i, n) ave_tousaSum[i] = (p[i] * (p[i] + 1) / 2) / p[i];
	vector<double> rui(n + 1); rui[0] = 0;
	reps(i, n) rui[i] = rui[i - 1] + ave_tousaSum[i - 1];
	double ans = 0;
	for(ll i = 0; i + k <= n; i++) ans = max(ans, rui[i + k] - rui[i]);
	printf("%.12f\n", ans);
}