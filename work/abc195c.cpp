#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    if(n <= 999999) {
      ans = n - 999;
    }
    else if(n <= 999999999) {
      ans += 999000;
      ans += (n - 999999) * 2;
    }
    else if(n <= 999999999999) {
      ans += 999000;
      ans += 999000000 * 2;
      ans += (n - 999999999) * 3;
    }
    else if(n <= 999999999999999){
      ans += 999000;
      ans += 999000000 * 2;
      ans += 999000000000 * 3;
      ans += (n - 999999999999) * 4;
    }
    else {
      ans += 999000;
      ans += 999000000 * 2;
      ans += 999000000000 * 3;
      ans += 999000000000000 * 4;
      ans += (n - 999999999999999) * 5;
    }
    cout << max((ll)0, ans) << endl;
}
