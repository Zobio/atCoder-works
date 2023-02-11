#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  K--;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  int s = 0;
  deque<int> dq = {N - 1};
  for (int i = N - 2; i >= 0; i--){
    if (A[i] < A[i + 1]){
      s = 0;
    }
    if (A[i] > A[i + 1]){
      s = 1;
    }
    if (s == 0){
      dq.push_back(i);
    } else {
      dq.push_front(i);
    }
  }
  A.erase(A.begin() + dq[K]);
  for (int i = 0; i < N - 1; i++){
    cout << A[i];
    if (i < N - 2){
      cout << ' ';
    }
  }
  cout << endl;
}