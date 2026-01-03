#pragma GCC optimize("O3,unroll-loops")
#include <iostream> 
#include <bitset>
#include <string>
using namespace std;

bitset <3000> S[3000]; 
int n; 
 
int main () {
  cin >> n; 
  for (int i = 0; i < n; i++) {
    string s;  
    cin >> s;  
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        S[i].set(j, 1); 
      }
    }
  }
  long long ans = 0LL; 
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) { 
      int cnt = (S[i] & S[j]).count(); 
      ans += cnt * (cnt - 1) / 2;
    }
  }           
  cout << ans;
  return 0;
}