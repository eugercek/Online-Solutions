#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the 'getTotalX' function below.
// Can't use std::gcd or std:lcm because C++17 is not a choice of version in
// hackerank. Also can't use boost

// This code is true but I don't know why it won't work.
// It just doen't work on
// 10 10
// 100 99 98 97 96 95 94 93 92 91
// 1 2 3 4 5 6 7 8 9 10

// Problem is in main not in mine solution
// TODO

int getTotalX(vector<int> a, vector<int> b) {
  auto gcd = [](int a, int b) {
    while (a != b) {
      if (a > b)
        a -= b;
      else
        b -= a;
    }
    return a;
  };

  int lcm_value = 1;
  for (const auto &a_i : a)
    lcm_value = (lcm_value * a_i) / gcd(lcm_value, a_i);

  int gcd_value = b[0];
  for (const auto &b_i : b)
    gcd_value = gcd(gcd_value, b_i);

  int time = 0;
  for (int i = 1; i <= (gcd_value / lcm_value); i++)
    if (gcd_value % (lcm_value * i) == 0)
      time++;

  return time;
}
int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int m = stoi(first_multiple_input[1]);

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  string brr_temp_temp;
  getline(cin, brr_temp_temp);
  cout << "Hello";

  vector<string> brr_temp = split(rtrim(brr_temp_temp));

  vector<int> brr(m);

  for (int i = 0; i < m; i++) {
    int brr_item = stoi(brr_temp[i]);

    brr[i] = brr_item;
  }

  int total = getTotalX(arr, brr);

  fout << total << "\n";

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

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
