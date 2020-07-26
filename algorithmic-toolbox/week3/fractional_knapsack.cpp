#include <iostream>
#include <vector>

using std::vector;

int find_max_index(vector<int> weights, vector<int> values) {
  int max_index = 0;
  double max_ratio = (double)values[0] / weights[0];

  for (int i = 1; i < weights.size(); ++i) {
    if ((values[i] / (double)weights[i]) > max_ratio) {
      max_ratio = values[i] / (double)weights[i];
      max_index = i;
    };
  };

  return max_index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  while (capacity > 0 && (weights.size() > 0)) {
    int max_index = find_max_index(weights, values);
    if (weights[max_index] > capacity) {
      value += (double)values[max_index] / ((double)weights[max_index] / capacity);
      capacity = 0;
    } else {
      value += (double)values[max_index];
      capacity -= weights[max_index];
      weights.erase(weights.begin() + max_index);
      values.erase(values.begin() + max_index);
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
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
