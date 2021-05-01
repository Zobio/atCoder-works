#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	int year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
	int month = (s[5] - '0') * 10 + s[6] - '0';
	int day = (s[8] - '0') * 10 + s[9] - '0';
	bool heisei = false;
	if(year < 2019) heisei = true;
	else if(year == 2019 && month <= 4) heisei = true;
	cout << (heisei ? "Heisei" : "TBD") << endl;
}