#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    string s; cin >> s;
	ll q; cin >> q;
    string s_front;
    bool rev = false;
    s.reserve(q);
    s_front.reserve(q);
	rep(_, q) {
		ll t; cin >> t;
		if(t == 1) rev = !rev;
		else{
			ll f; char c; cin >> f >> c;
			if(f == 1) {
				if(!rev) s_front.push_back(c);
				else s.push_back(c);
			}else{
				if(!rev) s.push_back(c);
				else s_front.push_back(c);
			}
		}
	}
    ll l1 = s_front.size(), l2 = s.size();
    if(!rev) {
        rep(i, l1) cout << s_front[l1 - 1 - i];
        rep(i, l2) cout << s[i];
    }
    else {
        rep(i, l2) cout << s[l2 - 1 - i];
        rep(i, l1) cout << s_front[i];
    }
}