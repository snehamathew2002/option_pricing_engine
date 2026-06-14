#include "../include/option.hpp"
#include <iostream>
#include <random>

using namespace std;

namespace options_pricing_engine {

// Monte Carlo simulation estimates option prices by generating many random
// stock price paths and averaging discounted payoffs.
// The stochastic path follows geometric Brownian motion.

    double random_normal(double mean, double stddev) {
        static random_device rd;
        static mt19937 gen(rd());
        normal_distribution<> d(mean, stddev);
        return d(gen);
    }

    double call(Option& option, int simulations) {
        cout << "[Monte Carlo] Calculating call price..." << endl;
        
        double dt = option.T; // Time to maturity
        double discount_factor = exp(-option.r * dt);
        double payoff_sum = 0.0;

        for (int i = 0; i < simulations; i++) {
            double Z = random_normal(0.0, 1.0); // Standard normal random variable
            double ST = option.S * exp((option.r - 0.5 * option.sigma * option.sigma) * dt + option.sigma * sqrt(dt) * Z); // Simulated stock price at maturity
            payoff_sum += max(0.0, ST - option.K); // Payoff for call option
        }

        return discount_factor * (payoff_sum / simulations); // Average discounted payoff
    }

    double put(Option& option, int simulations) {
        cout << "[Monte Carlo] Calculating put price..." << endl;
        
        double dt = option.T; // Time to maturity
        double discount_factor = exp(-option.r * dt);
        double payoff_sum = 0.0;

        for (int i = 0; i < simulations; i++) {
            double Z = random_normal(0.0, 1.0); // Standard normal random variable
            double ST = option.S * exp((option.r - 0.5 * option.sigma * option.sigma) * dt + option.sigma * sqrt(dt) * Z); // Simulated stock price at maturity
            payoff_sum += max(0.0, option.K - ST); // Payoff for put option
        }

        return discount_factor * (payoff_sum / simulations); // Average discounted payoff
    }
} 
