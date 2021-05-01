#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		cout << bitset<8>(s[i]);
	}cout << endl;
}
