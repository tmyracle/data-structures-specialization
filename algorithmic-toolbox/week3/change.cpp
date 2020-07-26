#include <iostream>
#include <vector>

using std::vector;

int get_change(int m) {
  //write your code here
  int n = 0;
  int remainder = m;
  vector<int> coins{ 10, 5, 1};

  if (m < 1) {
    return 0;
  };

  for (int i = 0; i < coins.size(); ++i) {
    if (remainder == 0) {
      break;
    } else if (coins[i] > remainder) {
      continue;
    } else {
      n += remainder / coins[i];
      remainder = remainder % coins[i];
    }
  }

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
