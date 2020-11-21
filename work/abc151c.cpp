#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<bool> AC(n + 1, false);
	vector<int> WaCount(n + 1, 0);
	int AcCount = 0;
	int tmpNum = 0;
	string tmpResult;
	for(int i = 0; i < m; i++) {
		cin >> tmpNum >> tmpResult;
		if(!AC[tmpNum] && tmpResult == "AC") {
			AC[tmpNum] = true;
			AcCount++;
		}
		else if(!AC[tmpNum] && tmpResult == "WA") {
			WaCount[tmpNum]++;
		}
	}
	int ansWa = 0;
	for(int i = 0; i <= n; i++) {
		if(AC[i])
		ansWa += WaCount[i];
	}
	cout << AcCount << " " << ansWa << endl;
}