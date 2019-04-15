#include "dislog.h"

#include <ctime>
#include <iostream>
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

long double time_naive_dislog_znstar(unsigned long n, unsigned long g)
{
    std::vector<long double> dislog_times;
    unsigned long result;
    std::clock_t start_time, end_time;

    for (unsigned long h = 2; h < n; h++) {
        if (h == g) {
            continue;
        }

        start_time = std::clock();

        // Naively compute discrete log of h with respect to g
        for (unsigned long x = 2; x < n-1; x++) {
            result = mod_exp(g, x, n);
            if (result == h) {
                end_time = std::clock();
                dislog_times.push_back(1000.0 * (end_time - start_time) / CLOCKS_PER_SEC);
                break;
            }
        }
    }

    // Average times
    long double average_time = 0.0;

    for (size_t i = 0; i < dislog_times.size(); i++) {
        average_time += dislog_times[i];
    }

    average_time = average_time / (long double) dislog_times.size();

    return average_time;
}

long double time_bstep_gstep_dislog_znstar(unsigned long n, unsigned long g)
{
    return 0.0;
}