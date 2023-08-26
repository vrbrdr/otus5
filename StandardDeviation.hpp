#pragma once

#include "IStatistics.hpp"
#include <cmath>
#include <vector>

namespace statistic {
    class StandardDeviation : public IStatistics {
      public:
        StandardDeviation() = default;

        void update(double next) override;

        virtual double eval() const override;

        virtual const char* name() const override;

      private:
        std::vector<double> m_values;
    };
} // namespace statistic