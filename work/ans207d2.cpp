#include <bits/stdc++.h> 
#define  rep(i,n) for(int i=0;i<n;++i) 
#define  reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using Pd = pair<double, double>;

using namespace std;

const double e = 0.001;

int main()
{
	int n;
	cin >> n;
	//doubleのペアを用いる
	vector<Pd> s(n), t(n);
	rep(i, n) cin >> s[i].first >> s[i].second;
	rep(i, n) cin >> t[i].first >> t[i].second;

	//コーナーケース
	if (n == 1)
	{
		cout << "Yes" << endl;
		return 0;
	}
	//S0を原点に平行移動
	//変数に一旦保持しておく
	double tsx = s[0].first;
	double tsy = s[0].second;

	rep(i, n)
	{
		s[i].first -= tsx;
		s[i].second -= tsy;
	}

	//S1の偏角を求めておく
	double thetaS = atan2(s[1].second, s[1].first);

	//Tを全探索
	rep(i, n)rep(j, n)
	{
		//Ti=Tjだったら計算しない
		if (i == j) continue;
		//tは汚せないので保持
		vector<Pd> v = t;

		//平行移動（Sと同様に保持）
		double ttx = v[i].first;
		double tty = v[i].second;

		rep(k, n)
		{
			v[k].first -= ttx;
			v[k].second -= tty;
		}

		//Tの偏角の計算
		double thetaT = atan2(v[j].second, v[j].first);
		//偏角の差分を計算
		double thetaD = thetaS - thetaT;
		//回転
		rep(k, n)
		{
			double tmp_x = v[k].first;
			double tmp_y = v[k].second;

			v[k].first = tmp_x * cos(thetaD) - tmp_y * sin(thetaD);
			v[k].second = tmp_x * sin(thetaD) + tmp_y * cos(thetaD);
		}

		//一致しているかの判定
		bool same = true;
		for (auto [sx, sy] : s)
		{
			bool ok = false;
			for (auto [tx, ty] : v)
			{
				//各点がTに含まれているかの判定
				if (abs(sx - tx) < e && abs(sy - ty) < e)
				{
					ok = true;
					break;
				}
			}
			//もし１点でも含まれていなければsame=false
			if (!ok)
			{
				same = false;
				break;
			}
		}
		//全ての点が含まれていたら一致している
		if (same)
		{
			cout << "Yes" << endl;
			return 0;
		}

	}

	cout << "No" << endl;
	return 0;
}