#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the kangaroo function below.
// x1 + time*v1 = x2 + time*v2
// x1 - x2 + time(v1 - v2) = 0

// time = (x2 - x1) / (v1 - v2)
// time needs to be Greater than 0
// They can meet in air
// |    | x | v |
// | 1. | 1 | 3 |
// | 2. | 4 | 2 |
// They will meet in 1.5 jump but they won't meet in a point so this is not
// valid. They need to meet in a point, so we need modulo.

//(x2 - x1) % (v1 - v2) == 0

// Edge cases come from formula not the problem's itself.
// Edge Cases:
// a) 0 (mod x);If they start from same point
// if (x1 - x2) == 0: then v1 == v2
// b) x (mod 0);If their speed is same
// if (v1 - v2) == 0: then x1 == x2
// c) x (mod negative);If second one is faster than first one
// if v2 > v1: then x1 > x2 && abs(v2 - v1)
string kangaroo(int x1, int v1, int x2, int v2) {
  if (x1 == x2)
    return (v1 == v2) ? "YES" : "NO";

  if (v1 == v2)
    return (x1 == x2) ? "YES" : "NO";

  if (v2 > v1)
    return (x1 > x2 && ((x2 - x1) % abs(v1 - v2)) == 0) ? "YES" : "NO";

  return (((x2 - x1) % (v1 - v2)) == 0) ? "YES" : "NO";
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string x1V1X2V2_temp;
  getline(cin, x1V1X2V2_temp);

  vector<string> x1V1X2V2 = split_string(x1V1X2V2_temp);

  int x1 = stoi(x1V1X2V2[0]);

  int v1 = stoi(x1V1X2V2[1]);

  int x2 = stoi(x1V1X2V2[2]);

  int v2 = stoi(x1V1X2V2[3]);

  string result = kangaroo(x1, v1, x2, v2);

  fout << result << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
