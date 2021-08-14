#include <bits/stdc++.h>
using namespace std;

int main() {
    tuple<int, int, int> tp = make_tuple(0, 1, 2);
    cout << get<2>(tp) << endl;
}