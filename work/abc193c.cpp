#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int vector_finder(std::vector<ll> vec, ll number)
{
	auto itr = std::find(vec.begin(), vec.end(), number);
	size_t index = std::distance(vec.begin(), itr);
	if (index != vec.size())
	{ // 発見できたとき
		return 1;
	}
	else
	{ // 発見できなかったとき
		return 0;
	}
}

int main() {
	ll n, now = 2;
	cin >> n;
	ll ans = 0;
	vector<ll> yet;
	for(ll i = 2; i * i <= n; i++) {
		while((ll)pow(i, now) <= n) {
			if (vector_finder(yet, (ll)pow(i, now))) {
				now++;
				continue;
			}
			ans++;
			yet.push_back((ll)pow(i, now));
			now++;
		}
		now = 2;
	}
	cout << n - ans << endl;
}