#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
const ll INF = numeric_limits<ll>::max() / 4;

int main() {
	int n;
	cin >> n;
	vector<pair<ll, ll>> a(n);
	for(int i = 0; i < n; i++) {
		ll tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		a[i] = make_pair(tmp1, tmp2);
	}
	int q;
	cin >> q;
	vector<ll> x(q);
	for(int i = 0; i < q; i++) {
		cin >> x[i];
	}
	for(int i = 0; i < n - 1; i++) {
		if(a[i].second != a[i + 1].second) continue;
		if(a[i].second == 1) {
			a[i + 1].first += a[i].first;
			a[i].second = 4;
		}
		else if(a[i].second == 2) {
			a[i + 1].first = max(a[i].first, a[i + 1].first);
			a[i].second = 4;
		}
		else if(a[i].second == 3) {
			a[i + 1].first = min(a[i].first, a[i + 1].first);
			a[i].second = 4;
		}
	}
	vector<pair<ll, ll>> aa;
	for(int i = 0; i < n; i++) {
		if(a[i].second != 4)
			aa.push_back(make_pair(a[i].first, a[i].second));
	}
	n = aa.size();
	vector<pair<ll, bool>> ansLst(n);
	for(int i = n - 1; i >= 0; i--) {
		int anst = aa[i].first;
		if(aa[i].second == 1) continue;
		for(int j = i; j < n; j++) {
			if(j == n - 1) {
				ansLst[i].first = anst;
				ansLst[i].second = true;
				break;
			}
			if(aa[j + 1].second == 1) {
				anst += aa[j + 1].first;
				continue;
			}
			else if(aa[j + 1].second == 2) {
				if(anst <= aa[j + 1].first && ansLst[j + 1].second) {
					ansLst[i].first = ansLst[j + 1].first;
					ansLst[i].second = true;
					break;
				}
			}
			else if (aa[j + 1].second == 3) {
				if(anst >= aa[j + 1].first && ansLst[j + 1].second) {
					ansLst[i].first = ansLst[j + 1].first;
					ansLst[i].second = true;
					break;
				}
			}
		}
	}
	for(int i = 0; i < q; i++) {
		bool ok = false;
		ll ans = x[i];
		for(int j = 0; j < n; j++) {
			if(aa[j].second == 1) {
				ans += a[j].first;
			}
			else if(aa[j].second == 2 && aa[j].first >= ans) {
				cout << ansLst[j].first << endl;
				ok = true;
				break;
			}
			else if(aa[j].second == 3 && aa[j].first <= ans) {
				cout << ansLst[j].first << endl;
				ok = true;
				break;
			}
		}
		if(!ok) cout << ans << endl;
	}
}