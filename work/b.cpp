#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a;
	cin >> n >> a;
	a -= 1;
	vector<char> s(n);
	int sharpCnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		if (s[i] == '#')
		{
			sharpCnt++;
		}
	}
	list<int> sPlace;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '#')
		{
			sPlace.push_back(i); //.size()つかえる
		}
	}
	long long cnt = 0;
	bool right = true;
	bool done = false;
	int aCopy = a;
	int old = a;
	int tmp = 0;
	while (sharpCnt > 0)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%s", &s[i]);
		}
		cout << endl;
		cout << "first a :" << a << endl;
		cout << "direction :" << (right ? "right" : "left") << endl;
		cout << "cnt :" << cnt << endl;
		aCopy = a;
		if (a == 0 && !right)
		{
			cnt += 2;
			right = !right;
			old = a;
			continue;
		}
		else if (a == n - 1 && right)
		{
			cnt += 2;
			right = !right;
			old = a;
			continue;
		}
		if (right)
		{
			for (int i = aCopy; i < n - 1; i++)
			{
				if (s[a + 1] == '#')
				{
					cnt += 2;
					sharpCnt--;
					right = false;
					done = true;
					s[a + 1] = '.';
					cout << "AAright a: " << a << " "
						 << "old: " << old << endl;
					cnt += abs(old - a);
					tmp = a;
					a = old;
					old = tmp;
					break;
				}
				else if (s[a + 1] == '.')
				{
					a++;
					cnt++;
				}
				cout << "right a: " << a << " "
					 << "cnt: " << cnt << endl;
			}
		}
		else
		{
			for (int i = aCopy; i > 0; i--)
			{
				if (s[a - 1] == '#')
				{
					cnt += 2;
					sharpCnt--;
					right = true;
					done = true;
					s[a - 1] = '.';
					cout << "AAleft a: " << a << " "
						 << "old: " << old << endl;
					cnt += abs(old - a);
					tmp = a;
					a = old;
					old = tmp;
					break;
				}
				else if (s[a - 1] == '.')
				{
					a--;
					cnt++;
				}
				cout << "left a: " << a << " "
					 << "cnt: " << cnt << endl;
			}
		}
		done = false;
	}
	cout << cnt - 1 - abs(a - old) << endl; //最後はターンしないから
}