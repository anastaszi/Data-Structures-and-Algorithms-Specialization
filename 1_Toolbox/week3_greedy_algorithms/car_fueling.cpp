#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int result = 0;
    int current = 0;
    int lastStop = 0;
    int maxStops = stops.size() - 1;

    while(current < maxStops) {
        lastStop = current;
        while (current < maxStops && stops[current + 1] - stops[lastStop] <= tank)
            current++;
        
        if (lastStop == current)
            return -1;
        if (current < maxStops)
            result++;
    }
    
    return result;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 1);
    stops.at(0) = 0;
    for (size_t i = 1; i < n + 1; i++)
        cin >> stops.at(i);
    stops.push_back(d);
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
