#include "../include/option.hpp"
#include <cmath>
#include <iostream>
#include <vector>
    
using namespace std;

namespace options_pricing_engine {

    double call(const Option& option, int steps) {
        cout << "[Binomial-Tree] Calculating call price..." << endl;
        
        double dt = option.T / steps; // Time per step
        double u = exp(option.sigma * sqrt(dt)); // Up factor - how much the stock price goes up in one step
        double d = 1.0 / u; // Down factor - how much the stock price goes down in one step
        double p = (exp(option.r * dt) - d) / (u - d); // Risk-neutral probability of an up move

        vector<double> stockPrices(steps + 1);

        for (int i = 0; i <= steps; i++) {
            stockPrices[i] = option.S * pow(u, i) * pow(d, steps -i);
        }
        
        vector<double> optionValues(steps + 1);

        for (int i = 0; i <= steps; i++) {
            optionValues[i] = max(0.0, stockPrices[i] - option.K); // Payoff at maturity
        }

        for (int j = steps - 1; j >= 0; j--) {
            for (int i = 0; i <= j; i++) {
                optionValues[i] = exp(-option.r * dt) * (p * optionValues[i + 1] + (1 - p) * optionValues[i]);
            }
        }

        return optionValues[0];
    }

    double put(const Option& option, int steps) {
        cout << "[Binomial-Tree] Calculating put price..." << endl;
        
        double dt = option.T / steps; // Time per step
        double u = exp(option.sigma * sqrt(dt)); // Up factor - how much the stock price goes up in one step
        double d = 1.0 / u; // Down factor - how much the stock price goes down in one step
        double p = (exp(option.r * dt) - d) / (u - d); // Risk-neutral probability of an up move

        vector<double> stockPrices(steps + 1);

        for (int i = 0; i <= steps; i++) {
            stockPrices[i] = option.S * pow(u, i) * pow(d, steps -i);
        }
        
        vector<double> optionValues(steps + 1);

        for (int i = 0; i <= steps; i++) {
            optionValues[i] = max(0.0, option.K - stockPrices[i]); // Payoff at maturity
        }

        for (int j = steps - 1; j >= 0; j--) {
            for (int i = 0; i <= j; i++) {
                optionValues[i] = exp(-option.r * dt) * (p * optionValues[i + 1] + (1 - p) * optionValues[i]);
            }
        }

        return optionValues[0];
    }
}