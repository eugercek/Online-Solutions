#include <bits/stdc++.h>

using namespace std;

/*
** It is O(S + Q)
*/
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
  unordered_map<string, int> hash_strings;
  vector<int> ret;

  for (const auto &i : strings)
    if (hash_strings.count(i))
      hash_strings[i]++;
    else
      hash_strings[i] = 1;

  for (const auto &i : queries)
    if (hash_strings.count(i))
      ret.push_back(hash_strings[i]);
    else
      ret.push_back(0);
  return ret;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int strings_count;
  cin >> strings_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> strings(strings_count);

  for (int i = 0; i < strings_count; i++) {
    string strings_item;
    getline(cin, strings_item);

    strings[i] = strings_item;
  }

  int queries_count;
  cin >> queries_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> queries(queries_count);

  for (int i = 0; i < queries_count; i++) {
    string queries_item;
    getline(cin, queries_item);

    queries[i] = queries_item;
  }

  vector<int> res = matchingStrings(strings, queries);

  for (int i = 0; i < res.size(); i++) {
    fout << res[i];

    if (i != res.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}
