#include <stdio.h>   // Biblioteca padrão para entrada e saída (printf, scanf)
#include <time.h>    // Biblioteca padrão para medir tempo (função clock())

// Função recursiva para calcular o n-ésimo número de Fibonacci
// Complexidade exponencial O(2^n)
unsigned long long Fib1(unsigned int n) {
    if (n < 2) {               // Caso base: se n for 0 ou 1
        return n;              // Fibonacci(0) = 0, Fibonacci(1) = 1
    } else {
        // Chamada recursiva: soma dos dois números anteriores
        return Fib1(n - 1) + Fib1(n - 2);
    }
}

int main() {
    unsigned int n;            // Variável para armazenar o valor digitado pelo usuário

    printf("Digite o valor de n: ");  // Solicita o valor de n ao usuário
    scanf("%u", &n);                  // Lê o valor digitado e armazena na variável n

    clock_t inicio = clock();         // Marca o tempo inicial da execução da função Fib1

    unsigned long long resultado = Fib1(n);   // Chama a função Fib1 para calcular Fibonacci de n

    clock_t fim = clock();            // Marca o tempo final da execução da função Fib1

    // Calcula o tempo decorrido em segundos:
    // diferença entre fim e início dividido pelo número de clocks por segundo
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Exibe o resultado do cálculo de Fibonacci
    printf("Fibonacci de %u = %llu\n", n, resultado);

    // Exibe o tempo que levou para calcular, com 10 casas decimais de precisão
    printf("Tempo: %.10f segundos\n", tempo);

    return 0;   // Encerra o programa com sucesso
}
