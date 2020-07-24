#include <iostream>
#include <vector>

using std::vector;

int get_fibonacci_last_digit(int n)
{
  if (n <= 1)
  {
    return n;
  }
  else
  {
    vector<int> nums(n);
    nums[0] = 0;
    nums[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
      nums[i] = (nums[i - 1] + nums[i - 2]) % 10;
    }
    return nums[n];
  }
}

int main()
{
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
