#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s; //Aは65
	char tmp;
	for(int i = 0; i < s.length(); i++) {
		tmp = s[i] - 65;
		tmp = (tmp + n) % 26;
		s[i] = 65 + tmp;
	}
	cout << s << endl;
}