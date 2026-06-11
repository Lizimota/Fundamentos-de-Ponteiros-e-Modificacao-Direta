/*
 * Atividade 5: Alocação Dinâmica de Memória (malloc e free)
 *
 * Objetivo: Remover o limite estático de tamanho.
 * O usuário escolhe quantos produtos cadastrar.
 * Usar malloc para alocar memória dinamicamente e free para liberar.
 */

#include <stdio.h>
#include <stdlib.h>  // Necessário para malloc() e free()

typedef struct {
    int id;
    float preco;
    char nome[50];
} Produto;

void aplicar_desconto(Produto *ptr_produto, float percentual) {
    float fator = 1.0 - (percentual / 100.0);
    ptr_produto->preco = ptr_produto->preco * fator;
}

// Reutilizada da Atividade 4 — aritmética de ponteiros obrigatória
void imprimir_produtos(Produto *ptr, int quantidade) {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("ID: %d | Nome: %s | Preco: R$ %.2f\n",
               (ptr + i)->id,
               (ptr + i)->nome,
               (ptr + i)->preco);
    }
    printf("-------------------------\n");
}

int main() {
    int quantidade;

    printf("=== Atividade 5: Alocacao Dinamica de Memoria ===\n\n");

    // Pergunta ao usuário quantos produtos deseja cadastrar
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Numero invalido de produtos.\n");
        return 1;
    }

    /*
     * malloc(n * sizeof(Produto)) aloca na heap:
     *   - n = quantidade de produtos
     *   - sizeof(Produto) = tamanho em bytes de uma struct Produto
     *   - Retorna um ponteiro void* que fazemos cast para Produto*
     *
     * Diferença de array estático (stack):
     *   Produto estoque[3];  <- tamanho fixo, definido em tempo de compilação
     *   Produto *estoque = malloc(n * sizeof(Produto));  <- tamanho em tempo de execução
     */
    Produto *estoque = (Produto *) malloc(quantidade * sizeof(Produto));

    // Sempre verificar se malloc retornou NULL (falha na alocação)
    if (estoque == NULL) {
        printf("Erro: nao foi possivel alocar memoria!\n");
        return 1;
    }

    printf("\nMemoria alocada com sucesso para %d produto(s)!\n\n", quantidade);

    // Preenche o array iterando com ponteiros (aritmética de ponteiros)
    for (int i = 0; i < quantidade; i++) {
        printf("--- Produto %d ---\n", i + 1);

        // (estoque + i) aponta para o i-ésimo elemento alocado
        (estoque + i)->id = i + 1;

        printf("Nome: ");
        scanf(" %[^\n]", (estoque + i)->nome);  // Lê string com espaços

        printf("Preco: R$ ");
        scanf("%f", &(estoque + i)->preco);
    }

    // Exibe todos os produtos cadastrados
    printf("\nProdutos cadastrados:");
    imprimir_produtos(estoque, quantidade);

    // Aplica desconto de 5% em todos os produtos
    printf("\nAplicando 5%% de desconto em todos os produtos...\n");
    for (int i = 0; i < quantidade; i++) {
        aplicar_desconto(estoque + i, 5.0);
    }

    imprimir_produtos(estoque, quantidade);

    /*
     * IMPORTANTÍSSIMO: liberar a memória alocada com malloc!
     * free() devolve a memória para o sistema operacional.
     * Não chamar free() causa MEMORY LEAK (vazamento de memória).
     */
    free(estoque);
    estoque = NULL;  // Boa prática: evita ponteiro dangling (apontando para memória liberada)

    printf("\nMemoria liberada com sucesso!\n");

    return 0;
}
