#ifndef __DISLOG_H__
#define __DISLOG_H__

#include <utility>
#include <vector>

unsigned long mod_exp(unsigned long base, unsigned long exp, unsigned long modulus);

bool is_prime(unsigned long p);

std::vector<unsigned long> gen_primes(unsigned long start, unsigned long end);

std::pair<unsigned long, unsigned long> get_zpstar_generator(unsigned long p);

long double time_naive_dislog_znstar(unsigned long n, unsigned long g);

long double time_bstep_gstep_dislog_znstar(unsigned long n, unsigned long g);

#endif
