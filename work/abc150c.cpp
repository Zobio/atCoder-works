#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> q(n);
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> q[i];
	}
	vector<int> pCopy(n);
	vector<int> qCopy(n);
	for(int i = 1; i <= n; i++) {
		pCopy[i - 1] = i;
		qCopy[i - 1] = i;
	}
	int pCount = 0, qCount = 0;
	do {
		if(pCopy == p) {
			break;
		}else{
			pCount++;
		}
	} while (next_permutation(pCopy.begin(), pCopy.end()));
	do
	{
		if (qCopy == q)
		{
			break;
		}else{
			qCount++;
		}
	} while (next_permutation(qCopy.begin(), qCopy.end()));
	cout << abs(pCount - qCount) << endl;
}