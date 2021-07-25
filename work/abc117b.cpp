#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int sum = 0;
	for(int i = 0; i < n - 1; i++) sum += a[i];
	if(sum > a[a.size() - 1]) cout << "Yes" << endl;
	else cout << "No" << endl;
}