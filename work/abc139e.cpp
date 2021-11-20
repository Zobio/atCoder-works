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
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	vector<queue<ll>> q(n);
	rep(i, n) rep(j, n - 1) {
		ll a; cin >> a; a--;
		q[i].push(a);
	}
	set<pair<ll, ll>> buf;
	rep(cu, n) {
		ll to = q[cu].front();
		if(q[to].front() == to) {
			buf.insert({min(cu, to), max(cu, to)});
		}
	}
	ll ans = 0;
	while(!buf.empty()) {
        ans++;
        set<pair<ll, ll>> buf2;
        fore(p, buf) {
            int a = p.first;
            int b = p.second;
            q[a].pop();
            q[b].pop();
            if(!q[a].empty()) {
                int cu = q[a].front();
                if(!q[cu].empty()) {
                    if(q[cu].front() == a)
                        buf2.insert({min(a, cu), max(a, cu)});
                }
            }
            if(!q[b].empty()) {
                int cu = q[b].front();
                if(!q[cu].empty()) {
                    if(q[cu].front() == b)
                        buf2.insert({min(b, cu), max(b, cu)});
                }
            }
        }
        swap(buf, buf2);
    }
	rep(i, n) if(!q[i].empty()) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}