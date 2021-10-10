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

ll n, m;

int judge(char a, char b) {
	//-1-->引き分け 1-->aの勝ち 0-->bの勝ち
	if(a == b) return -1;
	if ((a == 'G' && b == 'C') || (a == 'C' && b == 'P') || (a == 'P' && b == 'G')) return 1;
	return 0;
}

ll fix(ll num) {return 2 * n - num - 1;}

int main() {
	cin >> n >> m;
	vector<string> a(2 * n);
	rep(i, 2 * n) cin >> a.at(i);
	priority_queue<pair<ll, ll>> pq;
	rep(i, 2 * n) pq.push({0, 2 * n - i - 1});
	rep(i, m) {
		vector<pair<ll, ll>> tmp;
		rep(j, n) {
			pair<ll, ll> fi = pq.top(); pq.pop();
			pair<ll, ll> se = pq.top(); pq.pop();
			cout << a[fix(fi.second)][i] << " " << a[fix(se.second)][i] << endl;
			if(judge(a[fix(fi.second)][i], a[fix(se.second)][i]) == 1) fi.first++, cout << fix(fi.second) + 1 << " won!" << endl;
			else if(judge(a[fix(fi.second)][i], a[fix(se.second)][i]) == 0) se.first++, cout << fix(se.second) + 1 << " won!" << endl;
			else cout << "hikiwake" << endl;
			cout << fix(fi.second) + 1 << " " << fi.first << "  " << fix(se.second) + 1 << " " << se.first << endl;
			tmp.push_back(fi); tmp.push_back(se);
		}
		for(auto a : tmp) pq.push(a);
	}
	while(!pq.empty()) cout << fix(pq.top().second) + 1 << " " << pq.top().first << endl, pq.pop();
}