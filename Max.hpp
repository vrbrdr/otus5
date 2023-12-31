#pragma once

#include "IStatistics.hpp"

namespace statistic {
    class Max : public IStatistics {
      public:
        Max() : m_max{-std::numeric_limits<double>::max()} {
        }

        void update(double next) override {
            if (next > m_max) {
                m_max = next;
            }
        }

        virtual double eval() const override {
            return m_max;
        };

        virtual const char* name() const override {
            return "max";
        };

      private:
        double m_max;
    };
} // namespace statistic