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

bool isPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

bool checkk(ll num) {
	ll c;
	bool ok = false;
	for(ll i = 2; i < num; i++) {
		if(num % i == 0) {
			c = i;
			ok = true;
			break;
		}
	}
	cout << "num: " << num << " c: " << c << endl;
	if(!ok) return true;
	while(num % c == 0) num /= c;
	if(num == 1) { cout << "NOOOOOOOOOOOO" << endl;return false; }
	else return true;
	return true;
}

int main() {
	ll n, now = 2;
	cin >> n;
	ll ans = 0;
	ll fix = 0;
	vector<ll> yet;
	for(ll i = 2; i <= sqrt(n); i++) {
		while((ll)pow(i, now) <= n) {
			if (vector_finder(yet, (ll)pow(i, now))) {cout << "FIND!!! " << (ll)pow(i, now) << endl,now++; continue; }
			cout << pow(i, now) << endl;
			ans++; now++; yet.push_back((ll)pow(i, now));
		}
		now = 2;
	}
	cout << n - ans + fix << endl;
}