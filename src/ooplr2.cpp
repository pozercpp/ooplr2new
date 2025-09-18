#include "decimal.h"
#include <iostream>

int main() {
  unsigned long long aa;
  std::cin >> aa;
  Decimal a(aa);
  Decimal b({1, 2, 3});
  Decimal res1 = a + b;
  res1.print();
  std::cout << std::endl;
  Decimal res2 = a - b;
  res2.print();
  std::cout << std::endl;
  return 0;
}