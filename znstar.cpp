#include <iostream>

unsigned long mod_exp(unsigned long base, unsigned long exp, unsigned long modulus)
{
    if (exp == 0) {
        return 1;
    }

    if (exp == 1) {
      return base;
    }

    unsigned long result = base;
    for (unsigned long i = 2; i <= exp; i++) {
      result = (result * base) % modulus;
    }

    return result;
}

int main()
{
    std::cout << "(2 ** 16) % 10 = " << mod_exp(2, 16, 10) << "\n";
    return 0;
}
