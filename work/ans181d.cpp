#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

bool solve(string &S) {
    if (S.size() <= 5) {
        sort(S.begin(), S.end());
        do {
            int val = 0;
            for (auto c : S) val = val * 10 + (int)(c-'0');
            if (val % 8 == 0) return true;
        } while (next_permutation(S.begin(), S.end()));
        return false;
    }
    vector<int> all(10, 0);
    for (const auto c : S) all[c-'0']++;
    for (int i = 0; i < 1000; i += 8) {
        vector<int> num(10, 0);
        int i2 = i;
        for (int iter = 0; iter < 3; ++iter) {
            num[i2 % 10]++;
            i2 /= 10;
        }
        bool ok = true;
        for (int v = 0; v < 10; ++v) if (num[v] > all[v]) ok = false;
        if (ok) return true;
    }
    return false;
}

int main() {
    string S; cin >> S;
    if (solve(S)) cout << "Yes" << endl;
    else cout << "No" << endl;
}