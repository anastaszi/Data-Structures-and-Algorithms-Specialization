#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

//pesano period for 10 is 20;
const int gPESANO_TEN = 60;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }
    return sum % 10;
}
//this is slow solution. we need to calculate Fib(n) mod 10 and Fib(n+1) mod 10 fast
// and then return (Fib(n) mod 10 * Fib(n+1) mod 10) mod 10;
int fibonacci_sum_squares_fast(long long n) {
    
    //find the index in pesano table for given Fn;
    int pesanoIndexFirst = n % gPESANO_TEN;
    int pesanoIndexSecond = (n + 1) % gPESANO_TEN;
    
    //fill vector of remainders of 10 for first 20 Fibonacci numbers
    vector<int> digits(gPESANO_TEN);
    digits[0] = 0;
    digits[1] = 1;
    for (int i = 2; i < gPESANO_TEN; i++) {
        digits[i] = (digits[i - 1] + digits[i - 2]) % 10;
    }
    
    //return remainder of product fib(n) and f(n+1) when devided by 10
    return (digits[pesanoIndexFirst] * digits[pesanoIndexSecond]) % 10;
}

void test_algo() {
    for (int i = 0; i < 20; i++) {
        int n = rand() % 30 + 1;
        assert(fibonacci_sum_squares_fast(n) == fibonacci_sum_squares_naive(n));
    }
    assert(fibonacci_sum_squares_fast(1234567890) == 0);
    assert(fibonacci_sum_squares_fast(73) == 1);
}

int main() {
    long long n = 0;
    test_algo();
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
