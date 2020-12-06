#include <bits/stdc++.h>

using namespace std;

/*
** Be careful with comparing negative values of sum with result
*/
int hourglassSum(vector<vector<int>> arr) {
  int result = INT_MIN;
  for (int i = 0; i < arr.size() - 2; ++i) {
    for (int j = 0; j < arr[i].size() - 2; ++j) {
      int sum = 0;
      // Top row
      sum += arr[i][j];
      sum += arr[i][j + 1];
      sum += arr[i][j + 2];
      // Middle
      sum += arr[i + 1][j + 1];
      // Bottom
      sum += arr[i + 2][j];
      sum += arr[i + 2][j + 1];
      sum += arr[i + 2][j + 2];
      result = max(result, sum);
    }
  }
  return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  vector<vector<int>> arr(6);
  for (int i = 0; i < 6; i++) {
    arr[i].resize(6);

    for (int j = 0; j < 6; j++) {
      cin >> arr[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int result = hourglassSum(arr);
  std::cout << result << std::endl;

  fout << result << "\n";

  fout.close();

  return 0;
}
