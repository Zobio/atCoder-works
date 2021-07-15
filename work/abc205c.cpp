#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	if(!(c & 1)) {
		if(abs(a) > abs(b)) {
			cout << ">" << endl;
		}
		else if(abs(a) < abs(b)) {
			cout << "<" << endl;
		}else{
			cout << "=" << endl;
		}
	}else{
		if(a > b) {
			cout << ">" << endl;
		}
		else if(a < b) {
			cout << "<" << endl;
		}else{
			cout << "=" << endl;
		}
	}
}