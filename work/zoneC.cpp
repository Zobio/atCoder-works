#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> sk(n, vector<ll>(5));
	for(int i = 0; i < n; i++) {
		cin >> sk[i][0] >> sk[i][1] >> sk[i][2] >> sk[i][3] >> sk[i][4];
	}
	vector<int> se;
	ll minn = INF;
	for(int i = 0; i < n; i++) {
		vector<ll> maxx(5);
		minn = INF;
		if(se.size() < 3) {
			se.push_back(i);
			for(int ii = 0; ii < se.size(); ii++) {
				for(int j = 0; j < 5; j++) {
					maxx[j] = max(maxx[j], sk[se[ii]][j]);
				}
			}
			for(int j = 0; j < 5; j++) {
					minn = min(minn, maxx[j]);
			}
			for(int ii = 0; ii < se.size(); ii++)
			continue;
		}
		for(int ii = 0; ii < 3; ii++) {
			for(int j = 0; j < 5; j++) {
				maxx[j] = max(maxx[j], sk[se[ii]][j]);
			}
		}
		for(int j = 0; j < 5; j++) {
			minn = min(minn, maxx[j]);
		}

		int del = -1;
		for(int ii = 0; ii < 3; ii++) {
			vector<ll> nmax(5);
			ll nmin = INF;
			for(int j = 0; j < 3; j++) {
				if(ii == j) continue;
				for(int k = 0; k < 5; k++) {
					nmax[k] = max(nmax[k], sk[se[j]][k]);
				}
			}
			for(int k = 0; k < 5; k++) {
				nmax[k] = max(nmax[k], sk[i][k]);
			}
			for(int j = 0; j < 5; j++) {
				nmin = min(nmin, nmax[j]);
			}
			if(nmin > minn) minn = nmin, del = ii;
		}
		vector<int> seCopy = se;
		if(del != -1) {
			se.resize(0);
			for(int j = 0; j < 3; j++) {
				if(j == del) continue;
				se.push_back(seCopy[j]);
			}
			se.push_back(i);
		}
	}


	ll ans = minn;
	vector<vector<ll>> sk2(n, vector<ll>(5));
	for(int i = 0; i < n; i++) {
		sk2[i][0] = sk[n - i - 1][0];
		sk2[i][1] = sk[n - i - 1][1];
		sk2[i][2] = sk[n - i - 1][2];
		sk2[i][3] = sk[n - i - 1][3];
		sk2[i][4] = sk[n - i - 1][4];
	}
	sk = sk2;
	se.resize(0);
	minn = INF;
	for(int i = 0; i < n; i++) {
		vector<ll> maxx(5);
		minn = INF;
		if(se.size() < 3) {
			se.push_back(i);
			for(int ii = 0; ii < se.size(); ii++) {
				for(int j = 0; j < 5; j++) {
					maxx[j] = max(maxx[j], sk[se[ii]][j]);
				}
			}
			for(int j = 0; j < 5; j++) {
					minn = min(minn, maxx[j]);
			}
			for(int ii = 0; ii < se.size(); ii++)
			continue;
		}
		for(int ii = 0; ii < 3; ii++) {
			for(int j = 0; j < 5; j++) {
				maxx[j] = max(maxx[j], sk[se[ii]][j]);
			}
		}
		for(int j = 0; j < 5; j++) {
			minn = min(minn, maxx[j]);
		}

		int del = -1;
		for(int ii = 0; ii < 3; ii++) {
			vector<ll> nmax(5);
			ll nmin = INF;
			for(int j = 0; j < 3; j++) {
				if(ii == j) continue;
				for(int k = 0; k < 5; k++) {
					nmax[k] = max(nmax[k], sk[se[j]][k]);
				}
			}
			for(int k = 0; k < 5; k++) {
				nmax[k] = max(nmax[k], sk[i][k]);
			}
			for(int j = 0; j < 5; j++) {
				nmin = min(nmin, nmax[j]);
			}
			if(nmin > minn) minn = nmin, del = ii;
		}
		vector<int> seCopy = se;
		if(del != -1) {
			se.resize(0);
			for(int j = 0; j < 3; j++) {
				if(j == del) continue;
				se.push_back(seCopy[j]);
			}
			se.push_back(i);
		}
	}
	cout << max(minn, ans) << endl;
}