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
	ll cnt = 0;
	vector<pair<char, char>> pt;
	rep(i, a.size()) {
		if(a[i] != b[i]) {
			cnt++;
			pt.push_back(make_pair(a[i], b[i]));
		}
	}
	if(cnt == 0) {
		cout << "Yes" << endl; return 0;
	}
	else if(cnt == 2){
		if(pt[0].first == pt[1].second && pt[0].second == pt[1].first) {
			rep(i, a.size() - 1) {
				if(a[i] == pt[0].first && a[i + 1] == pt[1].first) {
					cout << "Yes" << endl; return 0;
				}
			}
			cout << "No" << endl; return 0;
		}else{
			cout << "No" << endl; return 0;
		}
	}else{
		cout << "No" << endl; return 0;
	}
}