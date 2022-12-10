#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#pragma region Template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvvi = vector<vector<vector<int>>>;
using vpi = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T = int> using spq = priority_queue<T, vector<T>, greater<T>>;
template<typename T = int> using gpq = priority_queue<T>;
#define fi first
#define se second
#define pb push_back
#define fore(p,a) for (auto p : a)
#define overload4(a,b,c,d,name,...) name
#define rep1(n) for (int i = 0; i < int (n); ++i)
#define rep2(i,n) for (int i = 0; i < int (n); ++i)
#define rep3(i,a,b) for (int i = a; i < int (b); ++i)
#define rep4(i,a,b,c) for (int i = a; i < int (b); i += c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for (int i = n; i--;)
#define rrep2(i,n) for (int i = n; i--;)
#define rrep3(i,a,b) for (int i = b; i-- > (a);)
#define rrep4(i,a,b,c) for (int i = (a) + ((b) - (a) - 1) / (c) * (c); i >= (a); i -= c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define all(container) begin(container), end(container)
#define rall(container) rbegin(container), rend(container)
#define mvvi(name, row, column) vvi name(row, vi(column))
#define mvvll(name, row, column) vvll name(row, vll(column))
#define mvvb(name, row, column) vvb name(row, vb(column))
#define Max(...) max({__VA_ARGS__})
#define Min(...) min({__VA_ARGS__})
#define fin exit(0)
#define popc __builtin_popcount
#define inrange(x, l, r) ((l) <= (x) && (x) < (r))
#define sq(x) ((x) * (x))
#ifdef LOCAL
template<typename T> string internal_vectostr(vector<T> v) { string ret; for (int i = 0; i < (int) v.size(); i++) ret += (i ? ", " : "") + to_string(v[i]); return ret; }
#define dbg(x) cerr << "[DEBUG] " << __LINE__ << ": " << #x << " = " << x << endl
#define dbv(x) cerr << "[DEBUG] " << __LINE__ << ": " << #x << " = { " << internal_vectostr(x) << " }" << endl
#define tabout(tab, n, m) cout << "[DEBUG]\n"; for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cout << tab[i][j] << ' '; cout << endl; }
#else
template<typename T> void internal_vectostr(vector<T> v) {}
#define dbg(x) ((void) 0)
#define dbv(x) ((void) 0)
#define tabout(tab, n, m) ((void) 0)
#endif
constexpr int INF = 1001001001;
constexpr ll LINF = 1LL << 60;
constexpr double EPS = 1e-10;
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll fact(ll x) { return x == 0 ? 1 : x * fact(x - 1); }
ll comb(ll n, ll r) { if (r < 0 || n < r) return 0; ll ret = 1; for (ll i = 1; i <= r; i++) { ret *= n; n--; ret /= i; } return ret; }
int Yes(bool f=1) { cout << (f ? "Yes" : "No") << '\n'; return 0; }
int No() { Yes(0); return 0; }
int YES(bool f=1) { cout << (f ? "YES" : "NO") << '\n'; return 0; }
int NO() { YES(0); return 0; }
int yes(bool f=1) { cout << (f ? "yes" : "no") << '\n'; return 0; }
int no() { yes(0); return 0; }
template<class T> int printvec(vector<T> v) { for (int i = 0; i < (int) v.size(); i++) cout << (i ? " " : "") << v[i]; cout << '\n'; return 0; }
struct IoInit { IoInit() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << setprecision(15) << fixed; cerr << setprecision(15) << fixed; } } io_init;
#pragma endregion

#include<atcoder/modint>
#line 1 "math/matrix/square-matrix.hpp"
/**
 * @brief Square-Matrix(正方行列)
 */
template< class T, size_t N >
struct SquareMatrix {
  array< array< T, N >, N > A;

  SquareMatrix() : A{{}} {}

  size_t size() const { return N; }

  inline const array< T, N > &operator[](int k) const {
    return (A.at(k));
  }

  inline array< T, N > &operator[](int k) {
    return (A.at(k));
  }

  static SquareMatrix add_identity() {
    return SquareMatrix();
  }

  static SquareMatrix mul_identity() {
    SquareMatrix mat;
    for(size_t i = 0; i < N; i++) mat[i][i] = 1;
    return mat;
  }

  SquareMatrix &operator+=(const SquareMatrix &B) {
    for(size_t i = 0; i < N; i++) {
      for(size_t j = 0; j < N; j++) {
        (*this)[i][j] += B[i][j];
      }
    }
    return *this;
  }

  SquareMatrix &operator-=(const SquareMatrix &B) {
    for(size_t i = 0; i < N; i++) {
      for(size_t j = 0; j < N; j++) {
        (*this)[i][j] -= B[i][j];
      }
    }
    return *this;
  }

  SquareMatrix &operator*=(const SquareMatrix &B) {
    array< array< T, N >, N > C;
    for(size_t i = 0; i < N; i++) {
      for(size_t j = 0; j < N; j++) {
        for(size_t k = 0; k < N; k++) {
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        }
      }
    }
    A.swap(C);
    return (*this);
  }

  SquareMatrix &operator^=(uint64_t k) {
    SquareMatrix B = SquareMatrix::mul_identity();
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return *this;
  }

  SquareMatrix operator+(const SquareMatrix &B) const {
    return SquareMatrix(*this) += B;
  }

  SquareMatrix operator-(const SquareMatrix &B) const {
    return SquareMatrix(*this) -= B;
  }

  SquareMatrix operator*(const SquareMatrix &B) const {
    return SquareMatrix(*this) *= B;
  }

  SquareMatrix operator^(uint64_t k) const {
    return SquareMatrix(*this) ^= k;
  }

  friend ostream &operator<<(ostream &os, SquareMatrix &p) {
    for(int i = 0; i < N; i++) {
      os << "[";
      for(int j = 0; j < N; j++) {
        os << p[i][j] << (j + 1 == N ? "]\n" : ",");
      }
    }
    return os;
  }
};

using mint=atcoder::modint998244353;
int main(){
    ll n;
    cin>>n;
    SquareMatrix<mint,2>mat;
    mat[0][0]=mat[0][1]=mat[1][0]=1;
    mat^=n;
    cout<<(mat[0][1]+mat[1][1]-1).val()<<endl;
}