#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(i) cout << i << endl

int binary_search(int arr[], int arr_len, int x) {
    int l = -1;
    int r = arr_len - 1;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (x == arr[mid]) {
            return mid;
        } else if (x < arr[mid]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (x == arr[r]) return r;
    return -1;
}

int main() {
    int arr[] = {1, 4, 5, 8, 10, 24, 55, 66, 190};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    cout << binary_search(arr, arr_len, 55) << endl; // 出力は6
    cout << binary_search(arr, arr_len, 4) << endl; // 出力は1
    cout << binary_search(arr, arr_len, 1000) << endl; // 出力は-1
    return 0;
}

int main2() {
    //左側が条件を満たす
    ll left = 0, right = 1e10;
	while(right - left > 1) {
		ll mid = (right + left) / 2;
		if(ok(mid)) left = mid;
		else right = mid;
	}
	cout << left << endl;

    //右側が条件を満たす
    ll left = 0, right = 1e10;
	while(right - left > 1) {
		ll mid = (left + right) / 2;
		if(ok(mid)) right = mid;
		else left = mid;
	}
	cout << right << endl;
}