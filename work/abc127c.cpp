#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	//1枚だけで全てのゲートを通過できる ID カードの枚数⇔それで通過できないゲートが存在しないIDカードの枚数
	//じゃなくてそれぞれの制限の積集合⇔下限の最高値と上限の最低値の間
	int n,m;
	cin >> n >> m;
	int a = 0, b = 1e5 + 100;
	for(int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		if(t1 > a) a = t1;
		if(t2 < b) b = t2;
	}
	cout << max(b - a + 1, 0) << endl;
}