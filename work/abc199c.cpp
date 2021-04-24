#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, q;
	string ss;
	cin >> n >> ss >> q;
	vector<string> s(2);
	for(int i = 0; i < n; i++) {
		s[0] += ss[i];
	}
	for(int i = 0; i < n; i++) {
		s[1] += ss[n + i];
	}
	for(int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		b--; c--;
		if(a == 1) {
			swap(s[b / n][b % n], s[c / n][c % n]);
		}else{
			swap(s[0], s[1]);
		}
	}
	cout << s[0] << s[1] << endl;
}