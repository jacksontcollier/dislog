#include "dislog.h"

#include <set>
#include <utility>
#include <vector>

// Perform modular exponentiation: (base ^ exp) % modulus
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

// Determine if p is prime
bool is_prime(unsigned long p)
{
    if (p <= 3) {
        return p > 1;
    } else if (((p % 2) == 0) || ((p % 3) == 0)) {
        return false;
    }

    unsigned long i = 5;

    while ((i * i) <= p) {
        if (((p % i) == 0) || ((p % (i + 2)) == 0)) {
            return false;
        }
        i++;
    }

    return true;
}

// Generate all primes in range [start, end] (inclusive)
std::vector<unsigned long> gen_primes(unsigned long start, unsigned long end)
{
    std::vector<unsigned long> primes;
    unsigned long p = start;
    
    if (p == 1) {
        p++;
    } 
    
    if (p == 2) {
        primes.push_back(p);
        p++;
    } else if ((p % 2) == 0) {
        p++;
    } 
    
    for (; p <= end; p += 2) {
        if (is_prime(p)) {
            primes.push_back(p);
        }
    }

    return primes; 
}

// Find a generator for znstar with n a prime p. Return the modulus p and generator g
// as a pair
std::pair<unsigned long, unsigned long> get_zpstar_generator(unsigned long p)
{
    unsigned long g = 2;
    
    for (; g < p; g++) {
        bool is_generator = true;
        std::set<unsigned long> generated_elements;
        generated_elements.clear();
        generated_elements.insert(1);
        for (unsigned long x = 1; x < p-1; x++) {
            unsigned long result = mod_exp(g, x, p);
            if (generated_elements.find(result) != generated_elements.end()) {
                is_generator = false;
                break;
            } else {
                generated_elements.insert(result);
            }
        }
        if (is_generator) {
            return std::make_pair(p, g);
        }
    }

    return std::make_pair(p, 0);
}

