# Design Patterns

# Adapter

> [Adapter/Adapter.cpp](https://github.com/LeonardoOzima/design-patterns/blob/main/Adapter/Adapter.cpp)

> Este repositório contém uma implementação simples de uma calculadora que usa o padrão de design Adapter em C++. A calculadora pode realizar operações básicas como soma, subtração, multiplicação e divisão.

## Propósito

O propósito deste código é demonstrar o uso do padrão de design Adapter. O Adapter é um padrão de design estrutural que permite que objetos com interfaces incompatíveis trabalhem juntos. Ele envolve um único objeto, o adaptador, que faz a interface entre dois outros objetos.

Neste código, a classe `OldCalculator` é a calculadora existente com uma interface incompatível. A `NewCalculator` é a nova calculadora que precisa usar a `OldCalculator`, mas com uma interface diferente. A `CalculatorAdapter` é usada para adaptar a interface da `OldCalculator` para a interface que a `NewCalculator` espera.

## Implementação

Neste código, o Padrão de Projeto Adapter é implementado por meio de uma classe `CalculatorAdapter`, uma interface `CalculatorInterface` e duas classes concretas `OldCalculator` e `NewCalculator`.

#### Classe OldCalculator

A classe `OldCalculator` é a calculadora existente com uma interface incompatível. Ela tem métodos para calcular a soma, a diferença, o produto e o quociente de dois números.

```cpp
class OldCalculator {
public:
    double calculateSum(double a, double b);
    double calculateDifference(double a, double b);
    double calculateProduct(double a, double b);
    double calculateQuotient(double a, double b);
};
```

#### Interface CalculatorInterface

A interface `CalculatorInterface` declara os métodos que a `NewCalculator` espera que a calculadora tenha.

```cpp
class CalculatorAdapter : public CalculatorInterface {
private:
    OldCalculator oldCalculator;

public:
    double add(double a, double b) override;
    double subtract(double a, double b) override;
    double multiply(double a, double b) override;
    double divide(double a, double b) override;
};
```

#### Classe NewCalculator

A classe `NewCalculator` usa a `CalculatorInterface` para realizar cálculos. Ela tem um método `calculate()` que realiza várias operações matemáticas e imprime os resultados.

```cpp
class NewCalculator {
private:
    CalculatorInterface* calculator;

public:
    NewCalculator(CalculatorInterface* calculator);
    void calculate();
};
```

## Uso

Para usar a nova calculadora:

- Crie um objeto CalculatorAdapter.
- Crie um objeto NewCalculator e inicialize-o com o adaptador.
- Chame o método calculate() para realizar cálculos e imprimir os resultados.

Exemplo:

```cpp
CalculatorAdapter adapter;
NewCalculator newCalculator(&adapter);
newCalculator.calculate();
```

## Diagrama UML

![Estrutura do padrão de projeto Singleton](https://refactoring.guru/images/patterns/diagrams/adapter/structure-object-adapter-indexed.png)

> **Referência:** https://refactoring.guru/pt-br/design-patterns/adapter

# Singleton

> [Singleton/Singleton.cpp](https://github.com/LeonardoOzima/design-patterns/blob/main/Singleton/Singleton.cpp)

Este repositório contém uma implementação simples de uma calculadora que usa o padrão de design Singleton em C++. A calculadora pode realizar operações básicas como soma, subtração, multiplicação e divisão.

## Propósito

O propósito deste código é demonstrar o uso do padrão de design Singleton. O Singleton é um padrão de design criacional que garante que uma classe tenha apenas uma instância e fornece um ponto de acesso global a essa instância.

Neste código, a classe `Singleton` é a calculadora. Ela é implementada como um Singleton para garantir que apenas uma instância da calculadora exista em todo o programa. Isso é útil porque permite que o estado e os comportamentos da calculadora sejam acessados de qualquer lugar do código sem a necessidade de passar referências para a calculadora.

## Implementação

Neste código, o Padrão de Projeto Singleton é implementado por meio de uma classe `Singleton`.

#### Classe Singleton

A classe `Singleton` é a calculadora que é implementada como um Singleton. Ela tem métodos para calcular a soma, a diferença, o produto e o quociente de dois números.

```cpp
class Singleton {
private:
    // Construtor privado para que nenhum objeto possa ser criado.
    Singleton() {}

    // Instância estática do singleton
    static Singleton *instance;

public:
    // Método estático para controle de acesso à instância singleton.
    static Singleton *getInstance();

    // Método para somar dois números
    int soma(int a, int b);

    // Método para subtrair dois números
    int subtracao(int a, int b);

    // Método para multiplicar dois números
    int multiplicacao(int a, int b);

    // Método para dividir dois números
    double divisao(int a, int b);
};
```

## Uso

Para usar a calculadora:

- Obtenha a instância do Singleton usando o método getInstance().
- Use os métodos da calculadora para realizar cálculos.
  Exemplo:

```cpp
Singleton *s = Singleton::getInstance();
int resultadoSoma = s->soma(5, 3);
int resultadoSubtracao = s->subtracao(5, 3);
int resultadoMultiplicacao = s->multiplicacao(5, 3);
double resultadoDivisao = s->divisao(5, 3);
```

## Diagrama UML

![Estrutura do padrão de projeto Singleton](https://refactoring.guru/images/patterns/diagrams/singleton/structure-pt-br-indexed.png)

> **Referência:** https://refactoring.guru/pt-br/design-patterns/singleton

# Strategy

> [Strategy/Strategy.cpp](https://github.com/LeonardoOzima/design-patterns/blob/main/Strategy/Strategy.cpp)

Este repositório contém uma implementação simples de uma calculadora que usa o padrão de design Strategy em C++. A calculadora pode realizar operações básicas como soma e subtração.

## Propósito

O propósito deste código é demonstrar o uso do padrão de design Strategy. O Strategy é um padrão de design comportamental que permite que você defina uma família de algoritmos, coloque cada um deles em uma classe separada e torne seus objetos intercambiáveis.

Neste código, a classe `Calculator` é o contexto que usa uma `CalculationStrategy` para realizar uma operação. As classes `SumStrategy` e `SubtractStrategy` são estratégias concretas que implementam a interface `CalculationStrategy`.

## Implementação

Neste código, o Padrão de Projeto Strategy é implementado por meio de uma classe `Calculator`, uma interface `CalculationStrategy` e duas classes concretas `SumStrategy` e `SubtractStrategy`.

#### Interface CalculationStrategy

A interface `CalculationStrategy` declara um método que todas as estratégias concretas devem implementar.

```cpp
class CalculationStrategy {
public:
    virtual double calculate(double a, double b) const = 0;
};
```

#### Estratégias Concretas

As classes de estratégia concreta (`SumStrategy` e `SubtractStrategy`) implementam o algoritmo definido na interface `CalculationStrategy`.

```cpp
class SumStrategy : public CalculationStrategy {
public:
    double calculate(double a, double b) const override;
};

class SubtractStrategy : public CalculationStrategy {
public:
    double calculate(double a, double b) const override;
};
```

#### Classe Calculator

A classe `Calculator` é o contexto que usa uma `CalculationStrategy` para realizar uma operação. Ela tem um método `executeStrategy()` que realiza a operação e retorna o resultado.

```cpp
class Calculator {
private:
    CalculationStrategy* strategy;

public:
    Calculator(CalculationStrategy* strategy);
    void setStrategy(CalculationStrategy* strategy);
    double executeStrategy(double a, double b) const;
};
```

## Uso

Para usar a calculadora:

1. Crie um objeto de estratégia concreta (`SumStrategy` ou `SubtractStrategy`).
2. Crie um objeto `Calculator` e inicialize-o com a estratégia.
3. Chame o método `executeStrategy()` para realizar a operação e obter o resultado.

Exemplo:

```cpp
SumStrategy sumStrategy;
SubtractStrategy subtractStrategy;

Calculator calculator(&sumStrategy);
cout << "Resultado da soma: " << calculator.executeStrategy(5.5, 3.3) << endl;

calculator.setStrategy(&subtractStrategy);
cout << "Resultado da subtração: " << calculator.executeStrategy(5.5, 3.3) << endl;
```

## Benefícios

- Permite que você defina uma família de algoritmos e escolha o algoritmo a ser usado em tempo de execução.
- Promove a separação de preocupações ao encapsular cada algoritmo em uma classe separada.
- Facilita a adição de novos algoritmos sem modificar o código existente.

## Quando Usar

Use o Padrão de Projeto Strategy quando:

- Você tem vários algoritmos para realizar uma tarefa e deseja alternar entre eles dinamicamente.
- Você precisa isolar os detalhes de implementação de um algoritmo do código do cliente.
- Você tem uma classe com um comportamento que pode ser estendido ou alterado por várias subclasses.

## Diagrama UML

![Estrutura do padrão de projeto Strategy](https://refactoring.guru/images/patterns/diagrams/strategy/solution.png)

> **Referência:** https://refactoring.guru/pt-br/design-patterns/strategy
