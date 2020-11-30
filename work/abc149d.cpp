#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, r, s, p;
	string t;
	cin >> n >> k >> r >> s >> p;
	cin >> t;
	vector<string> way(k);
	int count = 0;
	for(int i = 0; i < n; i++) {
		way[count] += t[i];
		count++;
		count %= k;
	}
	long long point = 0;
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < way[i].length(); j++) {
			if(j == 0) {
				if(way[i][0] == 'r') {
					point += p;
				}
				else if(way[i][0] == 's') {
					point += r;
				}
				else if(way[i][0] == 'p') {
					point += s;
				}
				continue;
			}
			if(way[i][j] != way[i][j - 1]) {
				if (way[i][j] == 'r')
				{
					point += p;
				}
				else if (way[i][j] == 's')
				{
					point += r;
				}
				else if (way[i][j] == 'p')
				{
					point += s;
				}
			}else{
				if (j != way[i].length() - 1) { //最後なのにつぎにアクセスすると範囲外アクセスになる(最後で一個前と同じなら0)
					vector<char> v = {'r', 's', 'p'};
					v.erase(remove(v.begin(), v.end(), way[i][j - 1]));
					v.erase(remove(v.begin(), v.end(), way[i][j + 1]));
					way[i][j] = v[0];
					if (way[i][j] == 'r')
					{
						point += p;
					}
					else if (way[i][j] == 's')
					{
						point += r;
					}
					else if (way[i][j] == 'p')
					{
						point += s;
					}
				}
			}
		}
	}
	cout << point << endl;
}