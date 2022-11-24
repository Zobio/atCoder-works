#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using pll=pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define rrep(i,n) for (ll i=n-1; i>=0; --i)
#define all(c) begin(c),end(c)
#define rall(c) rbegin(c),rend(c)
#define PI acos(-1)
#define oo 2e18
ll MOD = 998244353;
void cincout(){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
ld dist(ld x1,ld x2,ld y1,ld y2){return (sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));}
// https://atcoder.jp/contests/abc228/editorial/2932
// M^(K^N)%MODを求める場合、 K^N%(MOD-1)
ll modpow(ll a, ll n, ll mod){ a %= mod; if (a==0) return 0; if (n==0) return 1; if (n%2==1) return (a * modpow(a, n - 1, mod)) % mod; else { ll t = modpow(a, n / 2, mod) % mod;       return (t * t) % mod; }}
ll modinv(ll n, ll mod){ return modpow(n, mod-2, mod); }
// 逆元（modが素数以外）https://atcoder.jp/contests/abc186/tasks/abc186_e
ll modinv2(ll a, ll m) { // ret = inv(a) mod m
  ll b=m, u=1, v=0; while (b){ ll t=a/b; a-=t*b; swap(a, b); u-=t*v; swap(u, v); } u%=m; if (u<0) u+=m; return u; }
// 座標圧縮
template<typename T>
ll comp(vector<T> &A){ map<T, ll> mp; for(auto p: A) mp[p] = 0; ll sz = 0; for(auto &p: mp) p.second = ++sz; for(auto &a: A) a = mp[a]; return sz; }
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};  
bool is_pop(ll hash, ll d){ return (hash>>d)&1; }
bool isn_field(ll y, ll x, ll H, ll W){
  return (y < 0 || y >= H || x < 0 || x >= W);
}
//priority_queue<ll, vector<ll>, greater<ll>> Q;

//    size_t = 18446744073709551615 (1.8*10^19)
// LLONG_MAX = 9223372036854775807 (9.2*10^18)
//   INT_MAX = 2147483647 (2.1*10^9)

/*
上の桁から見ていく。

101111 +0
011000 +8
010001
010101
*/

ll N, M, K;
vector<pll> A;

int main(){
  cincout();
  cin >> N >> M >> K;
  rep(i, N){
    ll a;
    cin >> a;
    A.emplace_back(0, a);
  }
  // 候補をどんどん減らしていく
  ll ans = 0;
  sort(all(A));
  ll m = M;
  // 上位桁から作れるかを見ていく
  // 作れるとして、それを選んだ時のコスト。
  for(ll i=31; i>=0; --i){
    vector<pll> B;
    for(auto [c, a]: A){
      ll all = (1LL<<i)-1;
      if (is_pop(a, i)){
        B.emplace_back(c, a&all);
      }
      else{
        a &= all;
        ll cost = (1LL<<i)-a + c;
        a = 0;
        B.emplace_back(cost, a);
      }
    }
    bool ok = true;
    sort(all(B));
    if (B.size() < K) ok = false;
    else{
      ll total = 0;
      rep(j, K){
        total += B[j].first;
      }
      if (total > M) ok = false;
    }
    if(ok){
      swap(A, B);
      ans += (1LL<<i);
    }
    cout << A.size() << endl;
  }
  cout << ans << endl;
}
/*

    0110100101
    0110000110
    0011100101
    0011000000
    0001101111
8 256
  0:0010000110
  0:0010100101
 27:0100000000
 64:0100000000
145:0100000000

7 128
  0:0000000110
  0:0000100101
155:0010011011
192:0011000000
273:0100010001

6 64
 27:0001000000
 58:0001000000
192:0000000000
192:0011011011
320:0101010001

4 16
 43:0000101011
 74:0001001010
192:0000001011
208:0011010000
320:0000000001

3 8
 43:0000000011
 74:0000000010
192:0000000011
216:0011011000
327:0101001000

2 4
 44:0000101111
 76:0001001110
193:0011000100
220:0011011100
331:0101001011

1 2
 44:0000000001
 76:0000000000
195:0011000011
222:0011011110
331:0000000001

0 1
 44:0000000000
 77:0001001101
195:0000000000
223:0011011111
331:0000000000



*/