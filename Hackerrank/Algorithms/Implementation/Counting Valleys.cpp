#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 */
// Being on valley means having negative altitude
// Finishing the valley means ending ne negativeness
int countingValleys(int steps, string path) {
  int altitude = 0;
  int count = 0;
  for (const auto &i : path) {
    if (i == 'U') {
      if (altitude == -1)
        count++;
      altitude++;
    } else
      altitude--;
  }
  return count;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string steps_temp;
  getline(cin, steps_temp);

  int steps = stoi(ltrim(rtrim(steps_temp)));

  string path;
  getline(cin, path);

  int result = countingValleys(steps, path);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
