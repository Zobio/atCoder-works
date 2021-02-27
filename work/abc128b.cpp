#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<tuple<string, int, int>> r(n);
	for(int i = 0; i < n; i++) {
		int a; string s;
		cin >> s >> a;
		r[i] = make_tuple(s, -a, i + 1); 
	}
	sort(r.begin(), r.end());
	for(int i = 0; i < n; i++) {
		cout << get<2>(r[i]) << endl;
	}
}