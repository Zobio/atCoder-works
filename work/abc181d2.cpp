#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
    string s; cin>> s;
    sort(s.begin(), s.end());
    if(s.size() <= 10) {
        do{
            if(stoll(s) % 8 == 0) {
                cout << "Yes" << endl; return 0;
            }
        }while(next_permutation(s.begin(), s.end()));
        cout << "No" << endl; return 0;
    }
    vector<ll> cnt(10);
    rep(i, s.size()) cnt[s[i] - '0']++;
    for(ll i = 0; i < 1000; i+=8) {
        vector<ll> cur(10);
        ll i2 = i;
        rep(i3, 3) {
            cur[i2 % 10]++; i2 /= 10;
        }
        bool flag = true;
        rep(i3, 10) if(cur[i3] > cnt[i3]) flag = false;
        if(flag) {
            cout << "Yes" << endl; return 0;
        }
    }
    cout << "No" << endl; return 0;
}