#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	ll n; int k;
	cin >> n >> k;
	for(int i = 0; i < k; i++) {
		if(n % 200 == 0)
			n /= 200;
		else{
			n = stoll(to_string(n) + "200");
		}
	}
	cout << n << endl;
}