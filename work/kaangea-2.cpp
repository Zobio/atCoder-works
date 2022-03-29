#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	if(n == 1) cout << "35.62066952227138" << endl << "134.45284299703508" << endl;
	if(n == 2) cout << "34.82974157563629" << endl << "137.67268453510624" << endl;
	if(n == 3) cout << "35.632131062678376" << endl << "140.08510163513222" << endl; //ok
	if(n == 4) cout << "34.26880112340781" << endl << "135.40751530722915" << endl;
	if(n == 5) cout << "35.62487738030991" << endl << "139.77625607322864" << endl; //ok
	if(n == 6) cout << "35.716671252709986" << endl << "139.77207944439567" << endl;
	if(n == 7) cout << "35.902202963325344" << endl << "139.72193914625385" << endl;
	if(n == 8) cout << "34.98998128443666" << endl << "135.77221753729054" << endl;
	if(n == 9) cout << "35.36678209736351" << endl << "136.1567281608965" << endl;
	if(n == 10) cout << "35.10597025791135" << endl << "139.0820826269839" << endl;
	if(n == 11) cout << "35.626876264509114" << endl << "139.88655794364524" << endl; //ok
	if(n == 12) cout << "35.79045373101917" << endl <<  "139.25873101979334" << endl; //ok
}