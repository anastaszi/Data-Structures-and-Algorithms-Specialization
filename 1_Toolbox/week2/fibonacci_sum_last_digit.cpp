#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//last digit of the sum of all previous fibonacci numberts repeats every 60 numbers;
const int gSUM_PERIOND = 60;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

/* void fibonacci(int n) {
    vector<long long> numbers(n);
    numbers[0] = 0;
    numbers[1] = 1;
    long long sum = 1;
    for (int i = 2; i < n; i++) {
        numbers[i] = numbers[i-1] + numbers[i-2];
        sum += numbers[i];
        cout << "[" << i << "]" << numbers[i] << " => " << sum << " (" << (sum %10)<< ")" << endl;
    }
} */

int fibonacci_sum_fast(long long n) {
    //create vector of last digits of sums for first 60 fib numbers. the rule here is that last digit of the sum equels (sum[i - 1] + sum[i-2] + 1) % 10
    vector<int> sums(gSUM_PERIOND);
    
    //calculate the index of nth number in period table = reminder of n / 60
    int index = n % gSUM_PERIOND;
    
    sums[0] = 0;
    sums[1] = 1;
    
    for (int i = 2; i < gSUM_PERIOND; i++) {
     sums[i] = (sums[i-1] + sums[i-2] + 1) % 10;
    }
    return sums[index];
}

void test_algo() {
    for (int i = 0; i < 20; i++) {
        int n = rand() % 30 + 1;
        assert(fibonacci_sum_fast(n) == fibonacci_sum_naive(n));
    }
    assert(fibonacci_sum_fast(3) == 4);
    assert(fibonacci_sum_fast(100) == 5);
}

int main() {
    long long n = 0;
    
    test_algo();
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
