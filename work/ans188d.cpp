#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
    ll N, C;
    cin >> N >> C;
    vector<pair<ll, ll>> event;
    for(ll i = 0; i < N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        event.emplace_back(a - 1, c);
        event.emplace_back(b, -c);
    }
    sort(event.begin(), event.end());
    ll ans = 0, fee = 0, t = 0;
	for(ll i = 0; i < event.size(); i++) {
		//if(event[i].first != t) {
			cout << "A" << endl;
			ans += min(C, fee) * (event[i].first - t);
			t = event[i].first;
		//}
		cout << event[i].first << " " << event[i].second << " " << fee << endl;
		fee += event[i].second;
	}
    cout << ans << endl;
}
