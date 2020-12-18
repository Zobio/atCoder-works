#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;
	long long num = __gcd(a, b);
	cout << "start: " << num << endl;
	long long cnt = 1;
	for (long long i = 2; i <= 1e6; i++)
	{
		if (num % i == 0)
		{
			cnt++;
			cout << i << endl;
			while (num % i == 0)
			{
				num /= i;
			}
		}
	}
	cout << "num: " << num << endl;
	cout << "cnt: " << cnt << endl;
}