#include <bits/stdc++.h>

using namespace std;

/*
** Tricky parts:
** 1-> 12:00AM and 12:00PM
** Digits needs 0 in front of them
*/
// 12:01:00PM
// 0123456789
string timeConversion(string s) {
  int hour = stoi(s.substr(0, 3));
  string period = s.substr(8), hour_string;

  if (period == "AM")
    hour = hour % 12;
  else if (period == "PM" && hour != 12)
    hour += 12;

  if (hour < 10)
    hour_string = '0' + to_string(hour);
  else
    hour_string = to_string(hour);

  return s.replace(0, 2, hour_string).erase(s.size() - 2, 2);
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = timeConversion(s);
  std::cout << result << std::endl;

  fout << result << "\n";

  fout.close();

  return 0;
}
