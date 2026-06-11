/*
 * Atividade 3: Ponteiros para Structs
 *
 * Objetivo: Criar uma struct Produto com id e preco.
 * Atualizar aplicar_desconto para receber um ponteiro para Produto
 * e usar o operador seta (->) para acessar os campos.
 */

#include <stdio.h>

/*
 * Struct Produto
 * Agrupa dados relacionados de um produto:
 *   - id: identificador inteiro
 *   - preco: preço em float
 */
typedef struct {
    int id;
    float preco;
} Produto;

/*
 * Função aplicar_desconto
 * Recebe:
 *   - ptr_produto: ponteiro para struct Produto
 *   - percentual: percentual de desconto a aplicar
 *
 * O operador seta (->) é equivalente a (*ptr).campo
 * Ou seja: ptr_produto->preco == (*ptr_produto).preco
 */
void aplicar_desconto(Produto *ptr_produto, float percentual) {
    float fator = 1.0 - (percentual / 100.0);

    // Usa o operador seta (->) para acessar o campo preco pelo ponteiro
    ptr_produto->preco = ptr_produto->preco * fator;
}

int main() {
    // Inicializa uma struct Produto
    Produto produto1;
    produto1.id = 1;
    produto1.preco = 250.0;

    printf("=== Atividade 3: Ponteiros para Structs ===\n\n");
    printf("Produto ID: %d\n", produto1.id);
    printf("Preco original: R$ %.2f\n", produto1.preco);

    // Passa o endereço da struct para a função
    aplicar_desconto(&produto1, 20.0);

    printf("Preco apos desconto de 20%%: R$ %.2f\n", produto1.preco);

    return 0;
}
