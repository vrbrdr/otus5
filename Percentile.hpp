#pragma once

#include "IStatistics.hpp"
#include <string>
#include <vector>

namespace statistic {

    class Percentile : public IStatistics {
      public:
        Percentile(unsigned char percent);

        void update(double next) override;

        virtual double eval() const override;

        virtual const char* name() const override;

      private:
        const unsigned char m_percent;
        const std::string m_name;
        mutable std::vector<double> m_values;
    };
} // namespace statistic