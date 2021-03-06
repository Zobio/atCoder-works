#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	int same = 300000;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		if(same > a[i] + b[i]) same = a[i] + b[i];
	}
	int nos = 300000;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(nos > max(a[i], b[j])) nos = max(a[i], b[j]);
		}
	}
	cout << min(same, nos) << endl;
}