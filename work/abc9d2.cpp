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
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for (long long i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define PI acos(-1.0)
#define YesNo(flag) if(flag) { cout << "Yes" << endl; } else { cout << "No" << endl; }
constexpr long long MOD = 998244353LL;
constexpr long long INF = (1LL << 60);
template<class T> void setcout(T n) {cout << setprecision(n) << fixed;}
template<class T> void arrcout(T &a) { for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl; }
template<class T> void arrcout2(T &a) { for(size_t i = 0; i < a.size(); i++) { for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} }
template<class... T> constexpr auto min(T... a){return min(initializer_list<common_type_t<T...>>{a...});}
template<class... T> constexpr auto max(T... a){return max(initializer_list<common_type_t<T...>>{a...});}
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

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
		  C[i][j] = (C[i][j] ^ (*this)[i][k] & B[k][j]);
		}
	  }
	}
	A.swap(C);
	return (*this);
  }

  SquareMatrix &operator^=(uint64_t k) {
	SquareMatrix B = SquareMatrix::mul_identity();
	while(k > 0) {
	  if(k & 1) B &= *this;
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

const ll ma = 3;

int main() {
	ll k, m; cin >> k >> m;
	vll a(k); rep(i, k) cin >> a[i];
	vll c(k); rep(i, k) cin >> c[i];
	SquareMatrix<ll, ma> m1;
	rep(i, k) m1[0][i] = c[i];
	rep(i, k - 1) m1[i + 1][i] = 1;
	cout << m1 << endl;
	m1 ^= m - 1;
	cout << m1 << endl;
	SquareMatrix<ll, ma> m2;
	rep(i, k) m2[i][0] = a[i];
	SquareMatrix<ll, ma> ans = m1 * m2;
	rep(i, k) cout << i << " " << ans[i][0] << endl;
	cout << ans[k - 1][0] << endl;
}