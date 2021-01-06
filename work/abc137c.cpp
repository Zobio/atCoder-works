#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, long long> s;
	map<string, long long> sCnt;
	string word;
	for(int i = 0; i < n; i++) {
		cin >> word;
		sort(word.begin(), word.end());
		if (s.count(word)) {
			s.at(word) += sCnt[word];
			sCnt.at(word)++;
		}else{
			s.emplace(word, 0);
			sCnt.emplace(word, 1);
		}
	}
	auto begin = s.begin(), end = s.end();
	long long ans = 0;
	for (auto iter = begin; iter != end; iter++)
	{
		ans += iter->second;
	}
	cout << ans << endl;
}