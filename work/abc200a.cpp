#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	int ans = 1;
	int n;
	cin >> n;
	if(n % 100 == 0) ans--;
	ans += n / 100;
	cout << ans << endl;
}