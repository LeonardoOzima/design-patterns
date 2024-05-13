#include <stdio.h>
#include <iostream>
using namespace std;

class Singleton
{
private:
    // Construtor privado para que nenhum objeto possa ser criado.
    Singleton() {}

    // Instância estática do singleton
    static Singleton *instance;

public:
    // Método estático para controle de acesso à instância singleton.
    static Singleton *getInstance()
    {
        if (!instance)
            instance = new Singleton;
        return instance;
    }

    // Método para somar dois números
    int soma(int a, int b)
    {
        return a + b;
    }

    // Método para subtrair dois números
    int subtracao(int a, int b)
    {
        return a - b;
    }

    // Método para multiplicar dois números
    int multiplicacao(int a, int b)
    {
        return a * b;
    }

    // Método para dividir dois números
    double divisao(int a, int b)
    {
        if (b == 0)
        {
            cout << "Erro: Divisão por zero não é permitida.\n";
            return 0;
        }
        return static_cast<double>(a) / static_cast<double>(b);
    }
};

// Inicializando ponteiro como NULL.
Singleton *Singleton::instance = 0;

int main()
{
    Singleton *s = Singleton::getInstance();
    int resultadoSoma = s->soma(5, 3);
    int resultadoSubtracao = s->subtracao(5, 3);
    int resultadoMultiplicacao = s->multiplicacao(5, 3);
    double resultadoDivisao = s->divisao(5, 3);

    cout << "O resultado da soma é: " << resultadoSoma << endl;
    cout << "O resultado da subtração é: " << resultadoSubtracao << endl;
    cout << "O resultado da multiplicação é: " << resultadoMultiplicacao << endl;
    cout << "O resultado da divisão é: " << resultadoDivisao << endl;

    return 0;
}