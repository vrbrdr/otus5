#pragma once

#include "IStatistics.hpp"

namespace statistic {
    class Average : public IStatistics {
      public:
        Average() {}

        void update(double next) override {
            // avg = avg * (n / (n + 1)) + a / (n + 1)
            m_avg = m_avg * (m_count / (m_count + 1.)) + next / (m_count + 1.);
            ++m_count;
        }

        virtual double eval() const {
            return m_avg;
        };

        virtual const char* name() const {
            return "mean";
        };

      private:
        double m_avg{0};
        int m_count{0};
    };
} // namespace statistic