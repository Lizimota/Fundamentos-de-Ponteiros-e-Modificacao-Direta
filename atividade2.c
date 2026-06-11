/*
 * Atividade 2: Passagem por Referência
 *
 * Objetivo: Encapsular a lógica em uma função aplicar_desconto
 * que recebe um PONTEIRO para o preço e altera o valor original na memória.
 */

#include <stdio.h>

/*
 * Função aplicar_desconto
 * Recebe:
 *   - ptr_preco: ponteiro para float (endereço da variável de preço)
 *   - percentual: o percentual de desconto a aplicar (ex: 15.0 para 15%)
 * Retorna: void (não retorna nada, modifica diretamente na memória)
 */
void aplicar_desconto(float *ptr_preco, float percentual) {
    // Calcula o fator de desconto (ex: 15% -> multiplica por 0.85)
    float fator = 1.0 - (percentual / 100.0);

    // Modifica o valor ORIGINAL na memória usando o ponteiro
    *ptr_preco = *ptr_preco * fator;
}

int main() {
    float preco = 100.0;

    printf("=== Atividade 2: Passagem por Referencia ===\n\n");
    printf("Preco original: R$ %.2f\n", preco);

    // Passa o ENDEREÇO da variavel para a função
    // A função vai modificar o valor diretamente na memória
    aplicar_desconto(&preco, 15.0);

    printf("Preco apos desconto de 15%%: R$ %.2f\n", preco);

    // Aplicando outro desconto para demonstrar
    aplicar_desconto(&preco, 10.0);
    printf("Preco apos mais 10%% de desconto: R$ %.2f\n", preco);

    return 0;
}
