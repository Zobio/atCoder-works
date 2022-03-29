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
	string ans;
	if(n == 1) ans = "Since this weekend, I will give the title sound in both Britain and Japan and AtCoder will be an international programming competition!";
	if(n == 2) ans = "If you don't know what you're doing, you can't do it.";
	if(n == 3) ans = "Turning to the carriage of the carriage of the carriage of the carriage of the carriage of the carriage";
	if(n == 4) ans = "The berserk of Wo Yayuzuris, the quiet ruler of the floating world of innocent souls, hence the treachery... Our adventure has only just begun and within it is sealed the blue flame of the Flame Queen Dragon.";
	if(n == 5) ans = "666**99999222*977000222*22222000444433344444→448888999900033*666*444444222";
	if(n == 6) ans = "laugh";
	if(n == 7) ans = "Beko, Zamdun, Segazadaan, Vikazkubo, Okozukaidjol.";
	if(n == 8) ans = "Poisoned cookies";
	cout << ans << endl;
}