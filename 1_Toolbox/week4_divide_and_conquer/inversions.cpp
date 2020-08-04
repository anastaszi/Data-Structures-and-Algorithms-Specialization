#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int>&a, vector<int>&b, size_t left, size_t ave, size_t right) {
    long long number_of_inversions = 0;
    for (int i = ave; i < right; i++) {
        for (int j = ave - 1; j > (int)left - 1; j--) {
            if (b[i] < b[j])
                number_of_inversions++;
            else
                break;
        }
    }
    int i = (int)left;
    int j = (int)ave;
    int m = (int)left;
    while (i < ave && j < right) {
        a[m] = (b[i] < b[j]) ? b[i++] : b[j++];
        m++;
    }
    while (i != ave) {
        a[m++] = b[i++];
    }
    while (j != right) {
        a[m++] = b[j++];
    }
    
    for (int m = (int)left; m < right; m++)
        b[m] = a[m];
    return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
    if (right == left + 1)
        b[left] = a[left];
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
    number_of_inversions += merge(a, b, left, ave, right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
/*    for (size_t i = 0; i < b.size(); i++ ) {
        std::cout << b[i] << " ";
    }*/
}
