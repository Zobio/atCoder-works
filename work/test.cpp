#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for(long long i = a; i < b; i++)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define dll deque<long long>
#define ddll deque<dque<long long>>
#define dddll deque<deque<deque<long long>>>
#define ddddll deque<deque<deque<deque<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


bool check(vll arr) {
	ll cnt = 0;
	rep(i, 8) cnt += arr[i] == 4 ? 1 : arr[i] == 5 ? -1 : 0;
	return cnt == 0;
}

bool calc(vll arr, ll p, ld cur_sum) {
	ll c = p + 2;
	if(arr[p] == 0) cur_sum += c;
	else if(arr[p] == 1) cur_sum -= c;
	else if(arr[p] == 2) cur_sum *= c;
	else if(arr[p] == 3) cur_sum /= c;
	else if(arr[p] == 4) cur_sum += calc(arr, p + 1, 0);
	else if(arr[p] == 5) cur_sum += calc(arr, p + 1, 0);
}

int main() {
	vvll ans;
	rep(i, pow(6LL, 8)) {
		vll op;
		ll t = i;
		rep(j, 8) {
			op.push_back(t % 6);
			t /= 6;
		}
		if(!check(op)) continue;
		if(calc(op, 0, 9) == 2022) ans.push_back(op);
	}
	map<ll, char> mp = {{0, '+'}, {1, '-'}, {2, '*'}, {3, '/'}, {4, '('}, {5, ')'}};
	rep(i, ans.size()) {
		cout << 1 << " ";
		rep(j, 8) cout << mp[ans[i][j]] << j + 2 << " ";
		cout << endl;
	}
}