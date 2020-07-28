#include <iostream>
#include <cassert>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;
    
    std::vector<int> digits(n + 1);
    digits[0] = 0;
    digits[1] = 1;
    for (int i = 2; i <= n; i++) {
        digits[i] = (digits[i - 1] + digits[i - 2]) % 10;
    }
    return digits[n];
}

void test_algo() {
    assert(get_fibonacci_last_digit_fast(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for (int n = 0; n < 20; ++n) {
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
    }
}

int main() {
    int n;
    std::cin >> n;
    //test_algo();
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
