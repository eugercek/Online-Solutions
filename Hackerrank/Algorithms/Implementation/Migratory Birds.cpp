#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
// No need for hash map constrainst have the limit of 5
int migratoryBirds(vector<int> arr) {
  // 6 is for 5th index. Didn't want to deal with minus 1 in all operations.
  vector<int> num_table(6, 0);
  int max_spot = 0;
  int max_spotted_id = 0;
  static int x = 1;
  for (const auto &i : arr) {
    num_table[i]++;
    if (num_table[i] > max_spot) {
      max_spotted_id = i;
      max_spot = num_table[i];
    } else if (num_table[i] == max_spot && i < max_spotted_id) {
      max_spotted_id = i;
    }
  }

  return max_spotted_id;
}
int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string arr_count_temp;
  getline(cin, arr_count_temp);

  int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(arr_count);

  for (int i = 0; i < arr_count; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int result = migratoryBirds(arr);

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
