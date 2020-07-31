#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if (n == 1 || n == 2)
      summands.push_back(n);
  else {
      int sum = 1;
      int nextPossible = 0;
      summands.push_back(1);
      while (true) {
          nextPossible = summands.back() + 1;
          if (n - sum - nextPossible > nextPossible)
          {
              summands.push_back(nextPossible);
              sum += nextPossible;
          }
          else
          {
              summands.push_back(n - sum);
              break;
          }
      }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
