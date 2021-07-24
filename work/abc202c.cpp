#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	map<int, int> a;
	vector<int> b(n);
	map<int, int> c;
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a[tmp - 1]++;
	}
	for(int i = 0; i < n; i++) cin >> b[i], b[i]--;
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		c[tmp - 1]++;
	}
	ull ans = 0;
	for(int i = 0; i < n; i++) {
		ans += (ull)(c[i] * a[b[i]]); //同数の数(c[i]) * bが示すaの個数(a[b[i]])
	}
	cout << ans << endl;
}