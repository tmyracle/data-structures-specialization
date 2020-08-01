#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <map>

using std::vector;
using std::map;
using std::iterator;

int get_majority_element(vector<int> &a, int left, int right) {
  //write your code here
  int answer = -1;
  map<int, int> valueCounts;
  for (int i = left; i < right; ++i) {
    valueCounts[a[i]]++;
  }

  map<int, int>::iterator it = valueCounts.begin();

  for (std::pair<int, int> element: valueCounts) {
    if (element.second > (a.size()/2)) {
      answer = 1;
      break;
    }
  }

  return answer;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
