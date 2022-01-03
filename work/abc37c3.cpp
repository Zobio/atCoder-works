#include <bits/stdc++.h> // {{{
#define ARG4(_1, _2, _3, _4, ...) _4
#define rep(...) ARG4(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define REP(i, a) FOR(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define rrep(...) ARG4(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define RREP(i, a) RFOR(i, 0, a)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (int)(a); --i)
#define ALL(c) (c).begin(), (c).end()
#define TEN(n) ((ll)(1e##n))
#define pb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define let const auto
#define USE1(T) template <typename T>
#define USE2(T, U) template <typename T, typename U>
#define I_ inline
#define mygc(c) (c) = getchar_unlocked()
#define mypc(c) putchar_unlocked(c)

USE1(T) using duo = std::pair<T, T>;
USE1(T) using vec = std::vector<T>;
using ll = long long;
// clang-format off
USE2(T,U) I_ bool chmax(T&x,U a){return x<a&&(x=a,1);}
USE2(T,U) I_ bool chmin(T&x,U a){return a<x&&(x=a,1);}
USE1(T=int) I_ T in(){T x;std::cin>>x;return x;}
USE1(T=int) I_ vec<T> in(int n){vec<T> v;v.reserve(n);rep(i,n)v.pb(in<T>());return v;}
USE1(T) I_ void pr(T x){std::cout<<x<<'\n';}
USE2(T,...Ts) I_ void pr(T x,Ts...xs){std::cout<<x<<' ';pr(xs...);}
I_ int re(){int x=0,m=0,k;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||'9'<k)break;x=x*10+k-'0';}return x;}
I_ void wr(ll x,char c='\n'){int s=0,m=0;char b[32];if(x<0)m=1,x=-x;for(;x;x/=10)b[s++]=x%10;if(!s)b[s++]=0;if(m)mypc('-');for(;s--;)mypc(b[s]+'0');mypc(c);}
// clang-format on
// }}}
using namespace std;
const int inf = 1001001001;
const ll infll = 1001001001001001001ll;
const int dd[] = {0, 1, 0, -1, 0};

signed main() {
  int N = re(), K = re();
  ll tot = 0;
  for (int i = 0; i < N; ++i) {
    int A = re();
    tot += (min(i + 1, N - K + 1) - max(i - K + 1, 0)) * A;
	cout << min(i + 1, N - K + 1) << " " <<  max(i - K + 1, 0) << endl;
  }
  wr(tot);
  return 0;
}
