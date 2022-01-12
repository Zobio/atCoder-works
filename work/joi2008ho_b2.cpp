#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
short dp[4002][4002], ans;
int main(){
    string s, t;
    cin >> s >> t;
    rep(i, s.size()) rep(j, t.size()){
        if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
        ans = max(ans, dp[i+1][j+1]);
		cout << i+1 << " " << j+1 << " " << dp[i + 1][j + 1] << endl;
    }
    cout << ans << "\n";
}