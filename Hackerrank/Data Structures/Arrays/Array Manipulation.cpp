#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
|   1 |   2 |    3 |   4 |    5 |      |
|-----+-----+------+-----+------+------|
| 100 |     | -100 |     |      |      |
|     | 100 |      |     |      | -100 |
|     |     |  100 |     | -100 |      |
|-----+-----+------+-----+------+------|
| 100 | 100 |    0 |   0 | -100 |      |//Sum in colums
| 100 | 200 |  200 | 200 |  100 |      |//Sum from left to right
The biggest value(s) is 200
*/
long arrayManipulation(int n, vector<vector<int>> queries) {
  vector<long> delta(n, 0);
  for (const auto &cur_array : queries) {
    delta[cur_array[0] - 1] += cur_array[2];
    if (cur_array[1] < delta.size()) {
      // If cur_array[i] 9 and size is 10 enters
      delta[cur_array[1]] -= cur_array[2];
    }
  }
  long maximum_value = delta[0];
  long cur_value = 0;
  for (int i = 0; i < delta.size(); i++) {
    cur_value += delta[i];
    if (cur_value > maximum_value)
      maximum_value = cur_value;
  }
  return maximum_value;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nm_temp;
  getline(cin, nm_temp);

  vector<string> nm = split_string(nm_temp);

  int n = stoi(nm[0]);

  int m = stoi(nm[1]);

  vector<vector<int>> queries(m);
  for (int i = 0; i < m; i++) {
    queries[i].resize(3);

    for (int j = 0; j < 3; j++) {
      cin >> queries[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  long result = arrayManipulation(n, queries);

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
