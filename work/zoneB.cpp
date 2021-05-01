#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	int n;
	double d, h;
	cin >> n >> d >> h;
	vector<double> a(n);
	vector<double> b(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	double ans = 0;
	for(int i = 0; i < n; i++) {
		if(ans < h - (h - b[i]) / (d - a[i]) * d) {
			ans = h - (h - b[i]) / (d - a[i]) * d;
		}
	}
	cout << setprecision(15) << ans << endl;
}