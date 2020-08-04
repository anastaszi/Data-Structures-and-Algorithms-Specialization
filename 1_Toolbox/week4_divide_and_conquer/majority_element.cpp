#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using std::vector;

bool is_major(vector<int> &a, int left, int right, int element) {
    if (element == -1)
        return false;
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (a[i] == element)
            count++;
        if (count > (right - left + 1) / 2)
            return true;
    }
    return false;
}

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return a[left];
    int middle =  floor((right - left) / 2) + left;
    
    int major_left = get_majority_element(a, left, middle);
    int major_right = get_majority_element(a, middle + 1, right);
    if (is_major(a, left, right, major_left))
        return major_left;
    if (is_major(a, left, right, major_right))
        return major_right;
  //write your code here
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
