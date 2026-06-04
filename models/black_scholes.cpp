#include "../include/option.hpp"
#include <cmath>
#include <iostream>

using namespace std;

namespace options_pricing_engine {

    // Black-Scholes pricing uses the log-normal distribution of stock prices
    // and closed-form formulas for European call and put options.

    double normalCDF(double value) {
        return 0.5 * (1.0 + erf(value / sqrt(2.0)));
    }

    double getD1(const Option& option) {
        return (log(option.S / option.K) + (option.r + 0.5 * option.sigma * option.sigma) * option.T) / (option.sigma * sqrt(option.T));
    }

    double getD2(double sigma, double time, double d1) {
        return d1 - sigma * sqrt(time);
    }

    double call(const Option& option) {
        // In a full implementation, compute d1 and d2, then use the normal CDF.
        // callPrice = S * N(d1) - K * exp(-r * T) * N(d2)
        cout << "[Black-Scholes] Calculating call price..." << endl;
        
        double d1 = getD1(option);
        double d2 = getD2(option.sigma, option.T, d1);
        double callPrice = option.S * normalCDF(d1) - option.K * exp(-option.r * option.T) * normalCDF(d2);
        return callPrice;
    }

    double put(const Option& option) {
        // In a full implementation, compute d1 and d2, then use the put formula:
        // putPrice = K * exp(-r * T) * N(-d2) - S * N(-d1)
        cout << "[Black-Scholes] Calculating put price..." << endl;

        double d1 = getD1(option);
        double d2 = getD2(option.sigma, option.T, d1);
        double putPrice = option.K * exp(-option.r * option.T) * normalCDF(-d2) - option.S * normalCDF(-d1);
        return putPrice;
    }
}