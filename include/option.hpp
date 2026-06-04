#pragma once

#include <cmath>


namespace options_pricing_engine {

// Option represents a standard European option contract and its market parameters.
    class Option {
        public:
            double S;      // Current stock price
            double K;      // Strike price
            double T;      // Time to expiry in years
            double r;      // Risk-free interest rate
            double sigma;  // Volatility of the underlying asset

            // Initialize the option parameters.
            Option(double stockPrice, double strikePrice, double timeToExpiry,
                double riskFreeRate, double volatility)
                : S(stockPrice), K(strikePrice), T(timeToExpiry), r(riskFreeRate), sigma(volatility) {}
    };

}
