#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

int binary_search(const vector<int> &a, int x, int l, int r) {
    int middle = floor((r - l) / 2) + l;
    if (x == a[middle])
        return middle;
    if (!(l < r))
        return -1;
    if (x < a[middle])
        return binary_search(a, x, l, middle - 1);
    else
        return binary_search(a, x, middle + 1, r);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i], 0, a.size() - 1) << ' ';
  }
}
