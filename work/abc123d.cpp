#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a, b, c;
	ll tmp;
	for(int i = 0; i < x; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	for(int i = 0; i < y; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}
	for(int i = 0; i < z; i++) {
		cin >> tmp;
		c.push_back(tmp);
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());
	vector<ll> lst;
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			for(int l = 0; l < z; l++) {
				if((i + 1) * (j + 1) * (l + 1) > k) break;
				lst.push_back(a[i] + b[j] + c[l]);
			}
		}
	}
	sort(lst.rbegin(), lst.rend());
	for(int i = 0; i < min(k, (int)lst.size()); i++) {
		cout << lst[i] << endl;
	}
}