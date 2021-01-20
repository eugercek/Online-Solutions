#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
// lower(p /2) is from_front
// lower(n/2 - p/2 ) is from_back
// It is more like x/2 is absolute position of a page(x)
// | Index |Page Number  |
// |-------+------+------|
// |     0 |    x |    1 |
// |     1 |    2 |    3 |
// |     2 |    4 |    5 |
// |     3 |    6 |    7 |

// If you start from back, you first go 3 step then minus page step
int pageCount(int n, int p) { return min(p / 2, (n / 2 - p / 2)); }

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int p;
  cin >> p;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int result = pageCount(n, p);

  fout << result << "\n";

  fout.close();

  return 0;
}
