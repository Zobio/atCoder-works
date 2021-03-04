#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	//1枚だけで全てのゲートを通過できる ID カードの枚数⇔それで通過できないゲートが存在しないIDカードの枚数
	int n,m;
	cin >> n >> m;
	vector<bool> ok(n, true);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		for(int j = 0; j < a; j++) {
			ok[j] = false;
		}
		for(int j = b + 1; j < n; j++) {
			ok[j] = false;
		}
	}
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		if(ok[i]) ans++;
	}
	cout << ans << endl;
}