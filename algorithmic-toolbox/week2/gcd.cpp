#include <iostream>

int gcd(int a, int b)
{
  int first_val;
  int second_val;
  if (a > b)
  {
    first_val = a;
    second_val = b;
  }
  else
  {
    first_val = b;
    second_val = a;
  }

  if (second_val == 0)
  {
    return first_val;
  }
  else
  {
    return gcd(second_val, (first_val % second_val));
  }
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
