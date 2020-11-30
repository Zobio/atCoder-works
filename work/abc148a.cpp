#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> num = {1, 2, 3};
	int tmp1, tmp2;
	cin >> tmp1 >> tmp2;
	num.erase(remove(num.begin(), num.end(), tmp1), num.end());
	num.erase(remove(num.begin(), num.end(), tmp2), num.end());
		cout << num[0] << endl;
}