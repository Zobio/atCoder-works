#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> word;
	vector<string> f;
	string now;
	for(int i = 0; i < n; i++) {
		cin >> now;
		if(now[0] == '!')
		word.push_back(now);
		else
		f.push_back(now);
	}
	for(int i = 0; i < f.size(); i++) {
		if (find(word.begin(), word.end(), "!" + f[i]) != word.end()) {
			cout << f[i] << endl;
			return 0;
		}
	}
	cout << "satisfiable" << endl;
}