#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int copy = 0, max = 0, min = 0, digit = 1;
	for(int i = 0; i < k; i++) {
		copy = n;
		while (copy >= 10){
			digit++;
			copy /= 10;
		}
		vector<int> num;
		copy = n;
		while (copy >= 10){
			num.push_back(copy % 10);
			copy /= 10;
		}
		num.push_back(copy % 10);
		sort(num.begin(), num.end());
		for(int j = 0; j < num.size(); j++) {
			max += num[j] * pow(10, j);
		}
		sort(num.begin(), num.end(), greater<int>());
		for(int j = 0; j < num.size(); j++) {
			min += num[j] * pow(10, j);
		}
		n = max - min;
		max = 0; min = 0; copy = 0, digit = 1;
	}
	cout << n << endl;
}