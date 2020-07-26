#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
  int number_of_refills = 0;
  int current_refill = 0;
  int last_refill;
  stops.insert(stops.begin(), 0);
  stops.push_back(dist);

  while (current_refill <= stops.size()) {
    last_refill = current_refill;

    while ((current_refill <= stops.size()) && (stops[current_refill + 1] - stops[last_refill] <= tank)) {
      current_refill += 1;
    }
    if (current_refill == last_refill) {
      return -1;
    }
    if (current_refill <= stops.size()) {
      number_of_refills += 1;
    }
  }
  return number_of_refills;
};


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
