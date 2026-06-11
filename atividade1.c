/*
 * Atividade 1: Fundamentos de Ponteiros e Modificação Direta
 *
 * Objetivo: Declarar uma variável float, apontar um ponteiro para ela
 * e aplicar um aumento de 10% EXCLUSIVAMENTE pelo ponteiro.
 */

#include <stdio.h>

int main() {
    // Declara a variável de preço e inicializa com 100.0
    float preco = 100.0;

    // Declara o ponteiro para float e aponta para o endereço de preco
    float *ptr = &preco;

    printf("=== Atividade 1: Ponteiros e Modificacao Direta ===\n\n");
    printf("Endereco de preco: %p\n", (void *)ptr);
    printf("Preco original: R$ %.2f\n", preco);

    // Aplica aumento de 10% EXCLUSIVAMENTE pelo ponteiro
    // *ptr acessa o valor que está no endereço armazenado pelo ponteiro
    *ptr = *ptr * 1.10;

    // Imprime o valor da variavel original (que foi alterada pelo ponteiro)
    printf("Preco apos aumento de 10%% (via ponteiro): R$ %.2f\n", preco);

    return 0;
}
