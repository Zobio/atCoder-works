#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

bool isPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
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

int main() {
	int q;
	cin >> q;
	vector<int> primeList(100001, 0);
	for(int i = 0; i < primeList.size(); i++) {
		if(isPrime(i) && isPrime((i + 1) / 2)) primeList[i] = 1;
	}
	vector<int> sum (primeList.size() + 1, 0);
	for(int i = 0; i < primeList.size(); i++) {
		sum[i + 1] = sum[i] + primeList[i];
	}
	vector<int> ans;
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		r++;
		ans.push_back(sum[r] - sum[l]);
	}
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}