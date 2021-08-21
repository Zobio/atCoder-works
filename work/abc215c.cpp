#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 1LL << 60

int main() {
	string s; ll k;
	cin >> s >> k;
	sort(s.begin(), s.end());
	vector<char> ss(s.size());
	for(int i = 0; i < s.size(); i++) ss.at(i) = s[i];
	ll cnt = 1;
	do {
    if(cnt == k) {rep(i, ss.size()) cout << ss[i]; cout << endl; return 0;}
	else cnt++;
  } while (std::next_permutation(ss.begin(), ss.end()));
}