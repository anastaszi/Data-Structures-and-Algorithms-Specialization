#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, vector<double>ratio) {
    
    int vectorSize = weights.size();
  double value = 0.0;
    while (capacity > 0) {
        int biggestRatio = 0;
        for (int i=0; i < vectorSize; i++) {
            if (ratio[i] > ratio[biggestRatio]) {
                biggestRatio = i;
            }
        }
        if (capacity > weights[biggestRatio]) {
            ratio[biggestRatio] = 0.0;
            value += (double)values[biggestRatio];
            capacity -= weights[biggestRatio];
            double sum = 0;
            for(int i = 0; i < vectorSize; i++)
            {
                sum += ratio[i];
            }
            if (sum == 0.0)
                break;
        } else {
            value += ratio[biggestRatio] * capacity;
            break;
        }
    }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
    vector<double> ratio(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
      ratio[i] = (double)values[i] / weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, ratio);

  std::cout.precision(4);
    std::cout << std::fixed << optimal_value << std::endl;
  return 0;
}
