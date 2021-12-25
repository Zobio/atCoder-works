#include <bits/stdc++.h>

using namespace std;

int main() {
	string x;
	cin >> x;
	int s = 0, c = 0; 
	//sが各桁に対応する数(2桁の可能性有)、cが実際に当てはめる数(1桁)
	for (auto &nx : x) s += (nx - '0');
	string res;
	for (int i = x.size() - 1;; i--) {
		c += s;
		res.push_back('0' + (c % 10));
		c /= 10;
		cout << s << endl;
		if (i >= 0) {
			s -= (x[i] - '0');
		}
		//a + b + c → a + b(桁数変化)
		if (i <= 0 && c == 0) break;
		cout << x.size() -1 - i << " " << s << " " << c << endl;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
}
