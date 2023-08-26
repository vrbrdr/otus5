#include "StandardDeviation.hpp"

void statistic::StandardDeviation::update(double next) {
    m_values.push_back(next);
}

double statistic::StandardDeviation::eval() const {
    if (m_values.size() == 0) {
        return 0;
    }

    double avg{0};
    for (auto v : m_values) {
        avg += v;
    }

    avg = avg / m_values.size();

    double std{0};
    for (auto v : m_values) {
        std += (v - avg) * (v - avg);
    }

    std = sqrt(std / (m_values.size()));

    return std;
}

const char* statistic::StandardDeviation::name() const {
    return "std";
};