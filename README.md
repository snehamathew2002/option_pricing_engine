# Options Pricing Engine

A C++ implementation of two widely used option pricing models in quantitative finance:

* **Black-Scholes Model** (closed-form analytical solution)
* **Binomial Tree Model** (numerical pricing approach)

The project prices European call and put options, compares analytical and numerical methods, and demonstrates convergence of the Binomial Tree model toward the Black-Scholes solution as the number of time steps increases.

---

## Project Structure

```text
options_pricing_engine/
│
├── models/
│   ├── black_scholes.cpp
│   ├── binomial.cpp
│
├── include/
│   ├── option.hpp
│
├── main.cpp
├── README.md
```

---

## Features

### Black-Scholes Model

* European Call Option Pricing
* European Put Option Pricing
* Standard Normal CDF implementation
* Closed-form analytical pricing

### Binomial Tree Model

* European Call Option Pricing
* European Put Option Pricing
* Risk-neutral valuation
* Backward induction algorithm
* Configurable number of tree steps
* Convergence analysis against Black-Scholes

---

## Financial Concepts Covered

### Call Option

A call option gives the holder the right, but not the obligation, to purchase an asset at a predetermined strike price before expiry.

Call payoff at expiry:

```text
max(S - K, 0)
```

where:

* S = Stock price at expiry
* K = Strike price

---

### Put Option

A put option gives the holder the right, but not the obligation, to sell an asset at a predetermined strike price before expiry.

Put payoff at expiry:

```text
max(K - S, 0)
```

---

### Black-Scholes Pricing

The Black-Scholes model assumes:

* Log-normal stock price distribution
* Constant volatility
* Constant risk-free interest rate
* No arbitrage opportunities
* European-style exercise

The model provides a closed-form theoretical option price.

---

### Binomial Tree Pricing

The Binomial Tree model simulates possible future stock price movements through a sequence of up and down steps.

At each step:

* The stock can move upward by factor u
* The stock can move downward by factor d

The option is valued by:

1. Generating stock prices at expiry
2. Calculating option payoffs at expiry
3. Working backward through the tree using risk-neutral probabilities
4. Discounting future values back to the present

---

## Example Output

```text
Welcome to the Options Pricing Engine!

Running Black-Scholes models...

Call Price: 54.9701
Put Price: 0.0930826

Running Binomial models...

Binomial Call Price(10 steps): 54.9486
Binomial Call Price(50 steps): 54.9661
Binomial Call Price(100 steps): 54.9679
Binomial Call Price(500 steps): 54.9700

Binomial Put Price(10 steps): 0.0715795
Binomial Put Price(50 steps): 0.0890214
Binomial Put Price(100 steps): 0.0908499
Binomial Put Price(500 steps): 0.0929831
```

---

## Convergence Analysis

### Call Option

| Model                |   Price |
| -------------------- | ------: |
| Black-Scholes        | 54.9701 |
| Binomial (10 Steps)  | 54.9486 |
| Binomial (50 Steps)  | 54.9661 |
| Binomial (100 Steps) | 54.9679 |
| Binomial (500 Steps) | 54.9700 |

### Put Option

| Model                |  Price |
| -------------------- | -----: |
| Black-Scholes        | 0.0931 |
| Binomial (10 Steps)  | 0.0716 |
| Binomial (50 Steps)  | 0.0890 |
| Binomial (100 Steps) | 0.0908 |
| Binomial (500 Steps) | 0.0930 |

### Observation

As the number of binomial tree steps increases, the numerical solution converges toward the analytical Black-Scholes solution.

This validates the implementation and demonstrates the relationship between discrete-time and continuous-time option pricing models.

---

## Key Learnings

### Option Pricing is Risk-Based

Option value depends on:

* Time to expiry
* Volatility
* Interest rates
* Future uncertainty

not simply on current stock price.

### Future Payoffs Must Be Discounted

An option's value today is determined by the expected value of future payoffs discounted back to the present.

### Numerical Models Approximate Analytical Models

The Binomial Tree model approximates stock price evolution through discrete steps and converges to Black-Scholes as the number of steps increases.

### Risk-Neutral Valuation

The project applies risk-neutral probabilities to price derivatives without requiring forecasts of actual market direction.

---

## Building the Project

Compile using g++:

```bash
g++ main.cpp -o main
```

If compiling separate source files:

```bash
g++ main.cpp models/black_scholes.cpp models/binomial.cpp -o main
```

---

## Running the Project

Windows:

```bash
main.exe
```

Linux/macOS:

```bash
./main
```

---