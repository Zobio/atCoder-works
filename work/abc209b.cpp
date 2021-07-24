#include <bits/stdc++.h>
#define MAX_ELEMENT 300000 //要変更
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		if(i & 1) sum--;
	}
	cout << (sum <= x ? "Yes" : "No") << endl;
}