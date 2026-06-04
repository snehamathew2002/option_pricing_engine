#include "include/option.hpp"
#include "models/black_scholes.cpp"
#include "models/binomial.cpp"
#include <iostream> 

using namespace std;

namespace options_pricing_engine {

    class Main {
    public:
        static void run() {
            cout << "Welcome to the Options Pricing Engine!" << endl;
            // In a full implementation, we would create Option instances and call pricing functions here.
            cout << "Running Black-Scholes models..." << endl;
            Option opt(150.0, 100.0, 1.0, 0.05, 0.2);
            double callPrice = call(opt);
            cout << "Call Price: " << callPrice << endl;

            cout << "-----------------------------------" << endl;

            double putPrice = put(opt);
            cout << "Put Price: " << putPrice << endl;

            cout << "-----------------------------------" << endl;

            cout << "Running Binomial models..." << endl;
            cout << "Binomial Call Price(10 steps): " << call(opt, 10) << endl;
            cout << "Binomial Call Price(50 steps): " << call(opt, 50) << endl;
            cout << "Binomial Call Price(100 steps): " << call(opt, 100) << endl;
            cout << "Binomial Call Price(500 steps): " << call(opt, 500) << endl;

            cout << "-----------------------------------" << endl;

            cout << "Binomial Put Price(10 steps): " << put(opt, 10) << endl;
            cout << "Binomial Put Price(50 steps): " << put(opt, 50) << endl;
            cout << "Binomial Put Price(100 steps): " << put(opt, 100) << endl;
            cout << "Binomial Put Price(500 steps): " << put(opt, 500) << endl;
        }
    };
}

int main() {
    options_pricing_engine::Main::run();
    return 0;
}
