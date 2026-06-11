/*
 * Atividade 4: Aritmética de Ponteiros em Arrays
 *
 * Objetivo: Gerenciar um array estático de 3 Produtos.
 * Criar função imprimir_produtos que percorre o array
 * OBRIGATORIAMENTE usando aritmética de ponteiros: (ptr + i)->campo
 * SEM usar sintaxe de colchetes ptr[i].
 */

#include <stdio.h>

typedef struct {
    int id;
    float preco;
    char nome[50];
} Produto;

void aplicar_desconto(Produto *ptr_produto, float percentual) {
    float fator = 1.0 - (percentual / 100.0);
    ptr_produto->preco = ptr_produto->preco * fator;
}

/*
 * Função imprimir_produtos
 * Recebe:
 *   - ptr: ponteiro para o primeiro elemento do array de Produto
 *   - quantidade: número de produtos no array
 *
 * IMPORTANTE: percorre com aritmética de ponteiros (ptr + i)
 * NÃO usa colchetes ptr[i] — proibido pelo enunciado!
 *
 * Como funciona a aritmética de ponteiros:
 *   - ptr aponta para o 1º elemento
 *   - ptr + 1 aponta para o 2º elemento (avança sizeof(Produto) bytes)
 *   - ptr + 2 aponta para o 3º elemento, e assim por diante
 */
void imprimir_produtos(Produto *ptr, int quantidade) {
    printf("\n--- Lista de Produtos ---\n");

    for (int i = 0; i < quantidade; i++) {
        // (ptr + i) calcula o endereço do i-ésimo elemento
        // -> acessa o campo desse elemento
        printf("ID: %d | Nome: %s | Preco: R$ %.2f\n",
               (ptr + i)->id,
               (ptr + i)->nome,
               (ptr + i)->preco);
    }

    printf("-------------------------\n");
}

int main() {
    // Array estático de 3 Produtos
    Produto estoque[3] = {
        {1, 49.90,  "Caneta Azul"},
        {2, 129.90, "Caderno 200 folhas"},
        {3, 35.50,  "Borracha Branca"}
    };

    printf("=== Atividade 4: Aritmetica de Ponteiros em Arrays ===\n");

    // O nome do array já é um ponteiro para o primeiro elemento!
    // estoque == &estoque[0]
    imprimir_produtos(estoque, 3);

    // Aplica desconto de 10% no segundo produto (índice 1)
    printf("\nAplicando 10%% de desconto em \"%s\"...\n", estoque[1].nome);
    aplicar_desconto(&estoque[1], 10.0);

    imprimir_produtos(estoque, 3);

    return 0;
}
