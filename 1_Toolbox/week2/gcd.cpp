#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
    int largest = (a > b) ? a : b;
    int smallest = (a < b) ? a : b;
    if (largest % smallest == 0)
        return smallest;
    return (gcd_fast(smallest, largest % smallest));
}

void test_algo() {
    assert(gcd_fast(18, 35) == 1);
    assert(gcd_fast(28851538,1183019) == 17657);
    for (int i = 0; i < 20; i++) {
        int a = rand();
        int b = rand();
        cout << "a: " << a << " b: " << b << endl;
        assert(gcd_fast(a, b) == gcd_naive(a, b));
    }
}

int main() {
  int a, b;
  cin >> a >> b;
    //test_algo();
  cout << gcd_fast(a, b) << endl;
  return 0;
}
