#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	k--;
	s[k] += 'a' - 'A';
	cout << s << endl;
}