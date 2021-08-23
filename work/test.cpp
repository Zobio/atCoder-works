#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	vector<pair<ll, ll>> v;
	v.push_back(make_pair(1, 1));
	v.push_back(make_pair(4, 5));
	v.push_back(make_pair(2, 4));
	cout << (distance(v.begin(), lower_bound(v.begin(),v.end(), make_pair(3, 4)))) << endl;
}