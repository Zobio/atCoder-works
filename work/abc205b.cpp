#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	int n;
	cin >> n;
	vector<bool> done(n, false);
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		done[--a] = true;
	}
	for(int i = 0; i < n; i++) {
		if(!done[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}