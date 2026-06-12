#include <stdio.h>    // Biblioteca padrão para entrada e saída (printf, scanf)
#include <time.h>     // Biblioteca para medir tempo (função clock())

// Função que calcula o n-ésimo número de Fibonacci em tempo O(log n)

unsigned long long Fib3(unsigned long long n) {
	// Inicializa variáveis auxiliares para o cálculo
	unsigned long long i = 1;  // representa F(1)
	unsigned long long j = 0;  // representa F(0)
	unsigned long long k = 0;
	unsigned long long h = 1;
	unsigned long long t;      // variável temporária para armazenar resultados intermediários

	// Enquanto n for maior que zero, realiza operações de duplicação rápida
	while (n > 0) {
		if (n % 2 != 0) {     // Se n é ímpar
			t = j * h;
			j = i * h + j * k + t;  // Atualiza j para o próximo Fibonacci
			i = i * k + t;           // Atualiza i para o próximo Fibonacci
		}
		t = h * h;
		h = 2 * k * h + t;           // Atualiza h para a próxima iteração
		k = k * k + t;               // Atualiza k para a próxima iteração

		n = n / 2;                   // Divide n por 2 para avançar na duplicação rápida
	}

	return j;   // Retorna o n-ésimo número de Fibonacci
}

int main() {
	unsigned long long n;  // Variável para armazenar o valor digitado pelo usuário
	unsigned long long resultado;// Variável para  chamada interativa
	printf("Digite o valor de n: ");
	scanf("%llu", &n);     // Lê o valor digitado e armazena em n

	clock_t inicio, fim;   // Variáveis para armazenar o tempo inicial e final
	double tempo;          // Variável para armazenar o tempo decorrido em segundos


	inicio = clock();      // Marca o tempo inicial
	for (int i=0; i<1000000; i++)// quantidade de chamadas interativas pra aumentar o tempo
		resultado = Fib3(n);  // Calcula o Fibonacci de n com a função rápida

	fim = clock();         // Marca o tempo final

	// Calcula o tempo decorrido em segundos
	tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

	// Exibe o resultado do cálculo de Fibonacci
	printf("Fibonacci de %llu = %llu\n", n, resultado);

	// Exibe o tempo gasto para o cálculo, com precisão de 10 casas decimais
	printf("Tempo: %.10f segundos\n", tempo);

	return 0;  // Finaliza o programa com sucesso
}


