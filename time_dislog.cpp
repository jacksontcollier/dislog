#include "dislog.h"

#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage ./time_dislog znstar_and_generator_infile\n";
		return 0;
	}

	std::ifstream fin(argv[1], std::ifstream::in);

	if (!fin) {
		std::cout << "Unable to open " << argv[1] << "for reading\n";
		return 0;
	}

	std::string line;
	std::stringstream ss;
	unsigned long n, g;
	std::vector<std::pair<unsigned long, unsigned long>> n_and_g;

	while (std::getline(fin, line)) {
		line.replace(line.find(","), 1, " ");
		ss.clear();
		ss.str(line);
		ss >> n >> g;
		n_and_g.push_back(std::make_pair(n, g));
		line.clear();
	}

	std::vector<long double> naive_dislog_times;

	for (size_t i = 0; i < n_and_g.size(); i++) {
		n = n_and_g[i].first;
		g = n_and_g[i].second;
		naive_dislog_times.push_back(time_naive_dislog_znstar(n, g));
	}

	// Write results to stdout
	for (size_t i = 0; i < n_and_g.size(); i++) {
		n = n_and_g[i].first;
		g = n_and_g[i].second;
		std::cout << n << " " << g << " " << naive_dislog_times[i] << "\n";
	}

	return 0;
}