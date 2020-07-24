#include <iostream>

long long lcm_fast(int a, int b) {
  for (long l = 1; l <= (long long)a * b; ++l)
    if ((l * a) % b == 0)
      return (l * a);

  return (long long)a * b;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
