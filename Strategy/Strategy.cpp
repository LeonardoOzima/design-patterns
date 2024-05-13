#include <stdio.h>
#include <iostream>
using namespace std;

// Estratégia abstrata
class CalculationStrategy
{
public:
    virtual double calculate(double a, double b) const = 0;
};

// Estratégia concreta A (soma)
class SumStrategy : public CalculationStrategy
{
public:
    double calculate(double a, double b) const override
    {
        return a + b;
    }
};

// Estratégia concreta B (subtração)
class SubtractStrategy : public CalculationStrategy
{
public:
    double calculate(double a, double b) const override
    {
        return a - b;
    }
};

// Contexto
class Calculator
{
private:
    CalculationStrategy *strategy;

public:
    Calculator(CalculationStrategy *strategy) : strategy(strategy) {}

    void setStrategy(CalculationStrategy *strategy)
    {
        this->strategy = strategy;
    }

    double executeStrategy(double a, double b) const
    {
        return strategy->calculate(a, b);
    }
};

int main()
{
    SumStrategy sumStrategy;
    SubtractStrategy subtractStrategy;

    Calculator calculator(&sumStrategy);
    cout << "Resultado da soma: " << calculator.executeStrategy(5.5, 3.3) << endl;

    calculator.setStrategy(&subtractStrategy);
    cout << "Resultado da subtração: " << calculator.executeStrategy(5.5, 3.3) << endl;

    return 0;
}