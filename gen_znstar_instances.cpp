#include "dislog.h"

#include <iostream>
#include <sstream>

// Given a start range and end range as command line arguments, this program will find all instances
// of znstar with modulus n in this range such that n is prime. It will also find a generator for each
// znstar instance, and print the modulus n, followed by a comma, followed by the generator, each
// pair newline separated

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cout << "Usage: ./gen_znstar_instances prime_range_start prime_range_end\n";
        return 0;
    }
    
    std::stringstream input_parser;
    unsigned long prime_range_start;
    unsigned long prime_range_end;
    
    // Parse and convert command line arguments
    input_parser.str(std::string(argv[1]));
    input_parser >> prime_range_start;
    input_parser.clear();
    input_parser.str(std::string(argv[2]));
    input_parser >> prime_range_end;
    input_parser.clear();
    
    // Get primes in this range
    std::vector<unsigned long> primes = gen_primes(prime_range_start, prime_range_end);
    std::vector<std::pair<unsigned long, unsigned long>> znstar_and_generator_pairs;
    
    // Compute generator for each znstar with n prime. Form a vector of pairs,
    // (prime n for znstar, generator for znstar) 
    for (size_t i = 0; i < primes.size(); i++) {
        znstar_and_generator_pairs.push_back(get_zpstar_generator(primes[i]));
    }
    
    // Write znstar and generator pairs to stdout, comma separated
    for (size_t i = 0; i <znstar_and_generator_pairs.size(); i++) {
        std::cout << znstar_and_generator_pairs[i].first << ",";
        std::cout << znstar_and_generator_pairs[i].second << "\n";
    }

    return 0; 
}
