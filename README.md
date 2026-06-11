# 📦 Ponteiros em C — Gerenciamento de Estoque

Projeto desenvolvido como atividade prática da disciplina de **Programação em C**, com foco em **ponteiros**, **structs**, **passagem por referência** e **alocação dinâmica de memória**.

---

## 📁 Estrutura do Projeto

```
ponteiros-c/
├── atividade1/
│   └── atividade1.c   — Ponteiros básicos e modificação direta
├── atividade2/
│   └── atividade2.c   — Passagem por referência (função com ponteiro)
├── atividade3/
│   └── atividade3.c   — Ponteiros para structs e operador ->
├── atividade4/
│   └── atividade4.c   — Aritmética de ponteiros em arrays estáticos
├── atividade5/
│   └── atividade5.c   — Alocação dinâmica com malloc e free
└── README.md
```

---

## 🧠 Conceitos Abordados

### Atividade 1 — Ponteiros e Modificação Direta

Declare uma variável `float preco = 100.0`, crie um ponteiro `float *ptr = &preco` e aplique aumento de 10% **exclusivamente pelo ponteiro** (`*ptr = *ptr * 1.10`).

**Conceito-chave:** `*ptr` é o operador de **desreferenciamento** — acessa o valor que está no endereço de memória guardado pelo ponteiro.

```c
float preco = 100.0;
float *ptr = &preco;
*ptr = *ptr * 1.10;  // altera preco via ponteiro
```

---

### Atividade 2 — Passagem por Referência

Encapsula a lógica em `void aplicar_desconto(float *ptr_preco, float percentual)`. A função recebe o **endereço** da variável e a modifica diretamente na memória, sem precisar retornar nenhum valor.

**Conceito-chave:** Passagem por referência em C é feita passando o endereço (`&variavel`) para uma função que espera um ponteiro.

```c
void aplicar_desconto(float *ptr_preco, float percentual) {
    *ptr_preco = *ptr_preco * (1.0 - percentual / 100.0);
}

// Na main:
aplicar_desconto(&preco, 15.0);
```

---

### Atividade 3 — Ponteiros para Structs e Operador `->`

Agrupa os dados do produto em uma `struct Produto { int id; float preco; }`. A função `aplicar_desconto` passa a receber um ponteiro para a struct e usa o **operador seta** `->` para acessar os campos.

**Conceito-chave:** `ptr->campo` é equivalente a `(*ptr).campo`. É a forma mais limpa de acessar membros de uma struct via ponteiro.

```c
void aplicar_desconto(Produto *ptr_produto, float percentual) {
    ptr_produto->preco *= (1.0 - percentual / 100.0);
}
```

---

### Atividade 4 — Aritmética de Ponteiros em Arrays

Gerencia um array estático de 3 `Produto`. A função `imprimir_produtos` percorre o array **obrigatoriamente** com aritmética de ponteiros, sem usar colchetes `[]`.

**Conceito-chave:** Em C, `ptr + i` avança `i * sizeof(TipoDoPonteiro)` bytes na memória. Para structs, isso significa apontar diretamente para o i-ésimo elemento do array.

```c
void imprimir_produtos(Produto *ptr, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("%s: R$ %.2f\n", (ptr + i)->nome, (ptr + i)->preco);
        // Equivalente proibido: ptr[i].nome, ptr[i].preco
    }
}
```

---

### Atividade 5 — Alocação Dinâmica (`malloc` e `free`) ⭐ Pesquisa Extra

Remove o limite estático. O usuário define quantos produtos quer cadastrar em tempo de execução. A memória é alocada na **heap** com `malloc` e deve ser liberada com `free` ao final.

**Conceito-chave:**

| | Array Estático | Array Dinâmico |
|---|---|---|
| Tamanho | Definido em compilação | Definido em execução |
| Memória | Stack | Heap |
| Liberação | Automática | Manual (`free`) |

```c
// Aloca espaço para N produtos na heap
Produto *estoque = (Produto *) malloc(quantidade * sizeof(Produto));

if (estoque == NULL) {
    // Sempre verificar se a alocação falhou!
    printf("Erro de alocacao!\n");
    return 1;
}

// ... usa o array ...

// Libera a memória ao final — OBRIGATÓRIO!
free(estoque);
estoque = NULL;  // Boa prática: evita ponteiro dangling
```

---

## ▶️ Como Compilar e Executar

Você precisa de um compilador C instalado (como o `gcc`).

```bash
# Compilar individualmente
gcc atividade1/atividade1.c -o atividade1/atividade1
gcc atividade2/atividade2.c -o atividade2/atividade2
gcc atividade3/atividade3.c -o atividade3/atividade3
gcc atividade4/atividade4.c -o atividade4/atividade4
gcc atividade5/atividade5.c -o atividade5/atividade5

# Executar
./atividade1/atividade1
./atividade5/atividade5   # Esta pede input do usuário
```

---

## 💡 Principais Aprendizados

- Um **ponteiro** armazena um **endereço de memória**, não um valor diretamente
- `&variavel` retorna o endereço | `*ponteiro` acessa o valor no endereço
- Passar `&variavel` para uma função permite que ela modifique o valor original (passagem por referência)
- O operador `->` é o jeito correto de acessar campos de struct via ponteiro
- Aritmética de ponteiros (`ptr + i`) navega por arrays sem usar `[]`
- `malloc` aloca memória dinâmica na heap; `free` é **obrigatório** para evitar memory leak

---

*Desenvolvido para fins acadêmicos — Disciplina de Programação em C*
