#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

template <typename VV>
VV rotate(VV a) {
	/*2次元グリッドを反時計回りに90°回転させる関数 (2回回せば逆さまになる)
	(例)
	000     011
	001 --> 000
	101     001
	注意 : 縦と横のサイズが同じでないとバグる
	*/
	size_t siz = a.size();
	VV b(siz);
	for(size_t i = 0; i < siz; i++) for(size_t j = 0; j < siz; j++) b[i].push_back(a[j][siz - i - 1]);
	return b;
}

int main() {

}