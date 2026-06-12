#include <stdio.h>   // Biblioteca padrão para entrada e saída (printf, scanf)
#include <time.h>    // Biblioteca padrão para medir tempo (função clock())

// Função iterativa para calcular o n-ésimo número de Fibonacci com complexidade O(n)
unsigned long long Fib2(int n) {
    unsigned long long i, j, k;  // Variáveis auxiliares para cálculo

    i = 1;   // i começa com F(1) = 1
    j = 0;   // j começa com F(0) = 0

    // Loop de 1 até n para calcular Fibonacci iterativamente
    for (k = 1; k <= n; k++) {
        j = i + j;     // Novo valor de j é soma dos dois últimos termos
        i = j - i;     // Atualiza i para o valor anterior de j
    }

    return j;  // Retorna o n-ésimo número de Fibonacci
}

int main() {
    int n;  // Variável para armazenar o valor digitado pelo usuário
    unsigned long long resultado;// variavel da chamada interativa 
    printf("Digite o valor de n: ");  // Solicita ao usuário o valor de n
    scanf("%d", &n);                  // Lê o valor digitado e armazena na variável n

    clock_t inicio = clock();         // Marca o tempo inicial antes de calcular Fibonacci
    for (int i=0;i<1000000;i++) // quantidade de chamadas interativas pra aumentar o tempo do codigo 
	 
    resultado = Fib2(n);  // Chama a função iterativa para calcular Fibonacci

    clock_t fim = clock();            // Marca o tempo após o cálculo

    // Calcula o tempo gasto na execução, em segundos
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Exibe o resultado do cálculo de Fibonacci
    printf("Fibonacci de %d = %llu\n", n, resultado);

    // Exibe o tempo de execução com 10 casas decimais
    printf("Tempo: %.10f segundos\n", tempo);

    return 0;  // Finaliza o programa com código de sucesso
}

