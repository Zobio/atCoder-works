#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int n;

vector<vector<ll>> sk;
vector<bool> exist(1 << 5);

int getMsk(int ii, int lim) {
	int res = 0;
	for(int i = 0; i < 5; i++) {
		if(sk[ii][i] >= lim) res += 1 << i;
	}
	return res;
}

bool check(int lim) {
	for(int i = 0; i < 1 << 5; i++) exist[i] = false;
	for(int i = 0; i < n; i++) {
		exist[getMsk(i, lim)] = true;
	}
	for(int i = 0; i < 1 << 5; i++)
		for(int j = 0; j < 1 << 5; j++)
			for(int k = 0; k < 1 << 5; k++) {
				if((i | j | k) == (1 << 5) - 1 && exist[i] && exist[j] && exist[k]) return true;
			}
	return false;
}

int main() {
	const ll inf = 1000000000;
	cin >> n;
	sk.resize(n, vector<ll>(5));
	for(int i = 0; i < n; i++) {
		cin >> sk[i][0] >> sk[i][1] >> sk[i][2] >> sk[i][3] >> sk[i][4];
	}
	int ok = 0, ng = INT_MAX;
	while (ok + 1 != ng) {
        int md = (ok + ng) / 2;
        if (check(md)) ok = md;
        else ng = md;
    }
	cout << ok << endl;
}