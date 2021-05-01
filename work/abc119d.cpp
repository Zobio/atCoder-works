#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	int a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a);
	vector<ll> t(b);
	vector<ll> c(q);
	for(int i = 0; i < a; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < b; i++) {
		cin >> t[i];
	}
	for(int i = 0; i < q; i++) {
		cin >> c[i];
	}
	for(int i = 0; i < q; i++) {
		ll ans = INF;
		ll sa, sb, ta, tb;
		bool done = false;
		for(int j = c[q]; j >= 0; j--) {
			if(binary_search(s.begin(), s.end(), j)) {
				sa = j;
				done = true;
				break;
			}
		}
		if(!done) sa = -INF; done = false;
		for(int j = c[q]; j <= s[a - 1] ; j++) {
			if(binary_search(s.begin(), s.end(), j)) {
				sb = j;
				done = true;
				break;
			}
		}
		if(!done) sb = INF; done = false;
		for(int j = c[q]; j >= 0; j--) {
			if(binary_search(t.begin(), t.end(), j)) {
				ta = j;
				done = true;
				break;
			}
		}
		if(!done) ta= -INF; done = false;
		for(int j = c[q]; j <= t[b - 1]; j++) {
			if(binary_search(t.begin(), t.end(), j)) {
				tb = j;
				done = true;
				break;
			}
		}
		if(!done) tb= INF; done = false;
		for(int bits = 0; bits < 8; bits++) {
			int tt, ss;
			if((bits << 2) & 1) tt = ta;
			else tt = tb;
			if((bits << 1) & 1) ss = sa;
			else ss = sb;
			ll sum = 0;
			if(bits & 1) {
				sum += abs(c[q] - tt) + abs(tt - ss);
			}else{
				sum += abs(c[q] - ss) + abs(ss - tt);
			}
			if(ans > sum) ans = sum;
		}
		cout << sa << " " << sb << " " << ta << " " << tb << endl;
		cout << ans << endl;
	}
}