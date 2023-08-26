#include "Percentile.hpp"
#include <algorithm>
#include <cstring>
#include <stdexcept>

statistic::Percentile::Percentile(unsigned char percent)
    : m_percent{percent},
      m_name{"pct" + std::string(std::to_string((int)percent))} {

    if (percent < 0 || percent > 100) {
        throw new std::invalid_argument(
            "percent should be in the range from 0 to 100");
    }

    // + std::to_string((int)percent);
}

void statistic::Percentile::update(double next) {
    m_values.push_back(next);
}

double statistic::Percentile::eval() const {
    if (m_values.size() == 0) {
        return 0;
    }

    std::sort(m_values.begin(), m_values.end());
    int n = m_percent / 100. * m_values.size();

    return m_values[n];
}

const char* statistic::Percentile::name() const {
    return m_name.c_str();
};