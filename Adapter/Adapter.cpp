#include <stdio.h>
#include <iostream>
using namespace std;

// Classe existente com uma interface incompatível
class OldCalculator
{
public:
    double calculateSum(double a, double b)
    {
        return a + b;
    }

    double calculateDifference(double a, double b)
    {
        return a - b;
    }

    double calculateProduct(double a, double b)
    {
        return a * b;
    }

    double calculateQuotient(double a, double b)
    {
        if (b != 0)
        {
            return a / b;
        }
        else
        {
            cout << "Erro: Divisão por zero não é permitida.\n";
            return 0;
        }
    }
};

// Interface alvo que a NewCalculator quer usar
class CalculatorInterface
{
public:
    virtual double add(double a, double b) = 0;
    virtual double subtract(double a, double b) = 0;
    virtual double multiply(double a, double b) = 0;
    virtual double divide(double a, double b) = 0;
};

// Adaptador que faz a interface entre OldCalculator e CalculatorInterface
class CalculatorAdapter : public CalculatorInterface
{
private:
    OldCalculator oldCalculator;

public:
    double add(double a, double b) override
    {
        return oldCalculator.calculateSum(a, b);
    }

    double subtract(double a, double b) override
    {
        return oldCalculator.calculateDifference(a, b);
    }

    double multiply(double a, double b) override
    {
        return oldCalculator.calculateProduct(a, b);
    }

    double divide(double a, double b) override
    {
        return oldCalculator.calculateQuotient(a, b);
    }
};

// Nova calculadora que usa a interface alvo
class NewCalculator
{
private:
    CalculatorInterface *calculator;

public:
    NewCalculator(CalculatorInterface *calculator) : calculator(calculator) {}

    void calculate()
    {
        double sum = calculator->add(5.5, 3.3);
        double difference = calculator->subtract(5.5, 3.3);
        double product = calculator->multiply(5.5, 3.3);
        double quotient = calculator->divide(5.5, 3.3);

        cout << "Soma: " << sum << endl;
        cout << "Diferença: " << difference << endl;
        cout << "Produto: " << product << endl;
        cout << "Quociente: " << quotient << endl;
    }
};

int main()
{
    CalculatorAdapter adapter;
    NewCalculator newCalculator(&adapter);
    newCalculator.calculate();

    return 0;
}