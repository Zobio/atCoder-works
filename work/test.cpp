#include <bits/stdc++.h>
#include <atcoder/all> // AtCoder
using namespace std;
using namespace atcoder; // AtCoder
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using mint = modint998244353; // AtCoder
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vvvll = vector<vector<vector<long long>>>;
using vvvvll = vector<vector<vector<vector<long long>>>>;
using vbl = vector<bool>;
using vvbl = vector<vector<bool>>;
using vvvbl = vector<vector<vector<bool>>>;
using vvvvbl = vector<vector<vector<vector<bool>>>>;
using dll = deque<long long>;
using ddll = deque<deque<long long>>;
using dddll = deque<deque<deque<long long>>>;
using ddddll = deque<deque<deque<deque<long long>>>>;
using pll = pair<long long, long long>;
using vpll = vector<pair<long long, long long>>;
using vvpll = vector<vector<pair<long long, long long>>>;
#define pb push_back
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for (long long i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define PI acos(-1.0)
#define YES printf("Yes\n"), exit(0)
#define NO printf("No\n"), exit(0)
constexpr long long MOD = 998244353LL;
template<class T> void setcout(T n) {cout << setprecision(n) << fixed;}
template<class T> void arrcout(T &a) { for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl; }
template<class T> void arrcout2(T &a) { for(size_t i = 0; i < a.size(); i++) { for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} }
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
const long long INF=(long long)1e18;

int main(){
	int n,m,q;
	cin >> n >> m >> q;
	
	atcoder::dsu d(n);
	
	vector<vector<array<int,2>>>G(n);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--,b--;
		d.merge(a,b);
		G[a].push_back({b,c});
		G[b].push_back({a,-c});
	}
	
	vector<long long>dist(n,INF);
	vector<bool>negative_loop(n);
	
	for(int i=0;i<n;i++)if(d.leader(i)==i){
		//bfs
		queue<int>q;
		dist[i]=0;
		q.push(i);
		while(!q.empty()){
			int v=q.front();q.pop();
			for(auto[vv,c]:G[v]){
				if(dist[vv]==INF){
					dist[vv]=dist[v]+c;
					q.push(vv);
				}else{
					if(dist[vv]!=dist[v]+c)negative_loop[i]=true;
				}
			}
		}
	}
	
	for(int i=0;i<q;i++){
		int x,y;
		cin >> x >> y;
		x--,y--;
		if(!d.same(x,y)){
			cout << "nan" << endl;
		}else if(negative_loop[d.leader(x)]){
			cout << "inf" << endl;
		}else{
			cout << dist[y]-dist[x] << endl;
		}
	}
	arrcout(negative_loop);
}
