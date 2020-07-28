#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//last digit of the sum of all previous fibonacci numberts repeats every 60 numbers;
const int gSUM_PERIOND = 60;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }
    return sum % 10;
}


int get_fibonacci_partial_sum_fast(long long from, long long to) {
    //create vector of last digits of sums for first 60 fib numbers. the rule here is that last digit of the sum equels (sum[i - 1] + sum[i-2] + 1) % 10
    vector<int> sums(gSUM_PERIOND);
    
    //calculate the index of nth number in period table = reminder of n / 60
    int indexFrom = from % gSUM_PERIOND - 1;
    int indexTo = to % gSUM_PERIOND;
    int result = 0;
    
    sums[0] = 0;
    sums[1] = 1;
    
    for (int i = 2; i < gSUM_PERIOND; i++) {
        sums[i] = (sums[i-1] + sums[i-2] + 1) % 10;
    }
    // partial sum is difference between sum of F(to) and sum of F(from -1)
    result = sums[indexTo] - sums[indexFrom];
    return (result > 0) ? result : (10 + result) % 10;
}

void test_algo() {
    assert(get_fibonacci_partial_sum_fast(3, 7) == 1);
    assert(get_fibonacci_partial_sum_fast(10, 10) == 5);
    //assert(get_fibonacci_partial_sum_fast(10, 200) == 2);
    for (int i = 0; i < 20; i++) {
        int from = rand() % 30 + 1;
        int to = rand() % 30 + 1;
        int tempSum = from + to;
        from = (from > to) ? to : from;
        to = tempSum - from;
        assert(get_fibonacci_partial_sum_naive(from, to) == get_fibonacci_partial_sum_fast(from, to));
    }
}
int main() {
    long long from, to;
    //test_algo();
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
