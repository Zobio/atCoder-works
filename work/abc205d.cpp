#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ll> k(q);
	for(int i = 0; i < q; i++) {
		cin >> k[i];
	}
	for(int i = 0; i < q; i++) {
		ll cc = 0;
		for(int j = 0; j < n; j++) {
			if(a[j] <= k[i]) cc++;
			else break;
		}
		cout << "cc: " << cc << endl;
		int ans = k[i] + cc;
		cout << "ans: " << ans << endl;
		while(binary_search(a.begin(), a.end(), ans)) ans++;
		cout << ans << endl;
	}
}