#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {

    vector<long long>period(2);
    int i = 2;
    
    period[0] = 0;
    period[1] = 1;
    while(true) {
        period.push_back((period[i-1] + period[i-2]) % m);
        if (i != 2 && period[i] == 1 && period[i-1] == 0) {
            period.pop_back();
            period.pop_back();
            return (period[n % period.size()]);
        }
        i++;
    }
    return 0;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
