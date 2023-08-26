#include <iostream>
#include <limits>

#include "Average.hpp"
#include "IStatistics.hpp"
#include "Max.hpp"
#include "Min.hpp"
#include "Percentile.hpp"
#include "StandardDeviation.hpp"

using namespace statistic;

int main() {
    IStatistics* statistics[] = {new Min(),          new Max(),
                                 new Average(),      new StandardDeviation(),
                                 new Percentile(90), new Percentile(95)};

    bool init = false;
    double val = 0;
    while (std::cin >> val) {
        for (auto s : statistics) {
            s->update(val);
            init = true;
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    if (!init) {
        std::cerr << "No input data\n";
        return 1;
    }

    // Print results if any
    for (auto s : statistics) {
        std::cout << s->name() << " = " << s->eval() << std::endl;
    }

    for (auto s : statistics) {
        delete s;
    }

    return 0;
}