#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd(int a, int b) {
    int smallest = (a < b) ? a : b;
    int largest = (a > b) ? a : b;
    
    if (largest % smallest == 0)
        return smallest;
    return (gcd(smallest, (largest % smallest)));
}

long long lcm_fast(int a, int b) {
    if (a * b == 0)
        return 0;
    long long common = gcd(a, b);
    return common * (a / common) * (b / common);
}

void test_algo() {
    assert(lcm_fast(6,8) == 24);
    assert(lcm_fast(761457,614573) == 467970912861);
    for (int i = 0; i < 20; i++) {
        int a = rand() % 10000 + 1;
        int b = rand() % 10000 + 1;
        std::cout << "a: " << a << " b: " << b;
        assert(lcm_fast(a,b) == lcm_naive(a, b));
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //test_algo();
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
