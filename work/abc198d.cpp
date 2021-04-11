#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

vector<int> numLst(10);
vector<vector<int>> key(3, vector<int>(10));
string s1, s2, s3;
bool finish = false;

int contain(vector<char> lst, char c) {
	for(int i = 0; i < lst.size(); i++) {
		if(lst[i] == c) return i;
	}
	return lst.size();
}
int contain(vector<int> lst, char c) {
	for(int i = 0; i < lst.size(); i++) {
		if(lst[i] == c) return i;
	}
	return lst.size();
}

void solve(int now, int num) {
	cout << now << " " << num << endl;
	if(finish) return;
	numLst[now] = num;
	if(now != 9) {
		for(int i = 0; i < 10; i++) {
			if(contain(numLst, i) == numLst.size()) solve(now + 1, i);
		}
	}else{
		vector<ll> check(3);
		for(int i = 0; i < s1.size(); i++) {
			check[0] += (ll)(pow(10, s1.size() - i - 1) * numLst[key[0][i]]);
		}
		for(int i = 0; i < s2.size(); i++) {
			check[1] += (ll)(pow(10, s2.size() - i - 1) * numLst[key[1][i]]);
		}
		for(int i = 0; i < s3.size(); i++) {
			check[2] += (ll)(pow(10, s3.size() - i - 1) * numLst[key[1][i]]);
		}
		if(check[0] + check[1] == check[2]) {
			for(int i = 0; i < s1.size(); i++) {
				cout << numLst[s1[i] - '0'];
			}cout << endl;
			for(int i = 0; i < s2.size(); i++) {
				cout << numLst[s2[i] - '0'];
			}cout << endl;
			for(int i = 0; i < s3.size(); i++) {
				cout << numLst[s3[i] - '0'];
			}cout << endl;
			finish = true;
			return;
		}
	}
}

int main() {
	cin >> s1 >> s2 >> s3;
	int cnt = 0;
	vector<char> lst;
	for(int i = 0; i < s1.length(); i++) {
		if(contain(lst, s1[i]) == lst.size()) {
			lst.push_back(s1[i]);
			key[0][i] = cnt;
			cnt++;
		}else{
			key[0][i] = contain(lst, s1[i]);
		}
	}
	for(int i = 0; i < s2.length(); i++) {
		if(contain(lst, s2[i]) == lst.size()) {
			lst.push_back(s2[i]);
			key[1][i] = cnt;
			cnt++;
		}else{
			key[1][i] = contain(lst, s2[i]);
		}
	}
	for(int i = 0; i < s3.length(); i++) {
		if(contain(lst, s3[i]) == lst.size()) {
			lst.push_back(s3[i]);
			key[2][i] = cnt;
			cnt++;
		}else{
			key[2][i] = contain(lst, s3[i]);
		}
	}
	if(cnt > 10) {
		cout << "UNSOLVABLE" << endl;
	}
	solve(0, 0);
	if(!finish) cout << "UNSOLVABLE" << endl;
}