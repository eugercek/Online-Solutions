#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
//  #
// ##
//###
void staircase(int n) {
  for (int i = 0; i < n; ++i) {
    int space = n - i - 1;
    int hashtag = n - space;
    for (int j = 0; j < space; ++j) {
      cout << ' ';
    }
    for (int j = 0; j < hashtag; ++j) {
      cout << '#';
    }
    cout << '\n';
  }
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  staircase(n);

  return 0;
}
