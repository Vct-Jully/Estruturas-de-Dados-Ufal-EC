#ESTUDO DA ESTRUTURA DE MONTAGEM DA ÁRVORE:

Vamos analisar detalhadamente o comportamento da sua função de construção de árvore (`montando_arvore`) em conjunto com a função de inserção na fila, usando a entrada fictícia AAAAAABBBBBCCCCDDDEEF(frequências: A=6, B=5, C=4, D=3, E=2, F=1).

### Estrutura da fila de prioridade
A função `inserir_fila` mantém a fila de nós ordenada por frequência crescente. Cada nó contém:
- `dado`: o símbolo (caractere),
- `frequencia`: a frequência do símbolo,
- `proximo`: ponteiro para o próximo nó da fila,
- `esquerda` e `direita`: ponteiros para os filhos da árvore (que serão usados durante a construção da árvore de Huffman).

### Função `montando_arvore`

A função `montando_arvore` constrói a árvore de Huffman a partir dessa fila de prioridade. Vamos emular como ela funciona com os dados fornecidos:

**Fila inicial (frequências crescentes):**
- F (1), E (2), D (3), C (4), B (5), A (6)

### Passo a passo da execução de `montando_arvore`

1. **Primeiro loop**:
    - **Pegamos F (1) e E (2)** da fila (os dois menores):
    - Criamos um novo nó `novoNode` com o valor `'*'` (marcador de nó interno) e frequência `1 + 2 = 3`.
    - Esse novo nó `'*'` terá:
      - `esquerda` apontando para F,
      - `direita` apontando para E.
    - A fila agora contém:
      - [D (3), C (4), B (5), A (6)] e o novo nó `'*'` (com frequência 3).
    - Inserimos esse nó `'*'` na fila, que agora fica ordenada:
      - [D (3), '*' (3), C (4), B (5), A (6)]

2. **Segundo loop**:
    - **Pegamos D (3) e '*' (3)** da fila:
    - Criamos outro nó `novoNode` com `'*'` e frequência `3 + 3 = 6`.
    - Esse nó terá:
      - `esquerda` apontando para D,
      - `direita` apontando para o primeiro nó `'*'` (que contém F e E).
    - A fila agora contém:
      - [C (4), B (5), A (6)] e o novo nó `'*'` (com frequência 6).
    - Inserimos esse novo nó `'*'`, a fila ordenada:
      - [C (4), B (5), A (6), '*' (6)]

3. **Terceiro loop**:
    - **Pegamos C (4) e B (5)** da fila:
    - Criamos um novo nó `novoNode` com `'*'` e frequência `4 + 5 = 9`.
    - Esse nó terá:
      - `esquerda` apontando para C,
      - `direita` apontando para B.
    - A fila agora contém:
      - [A (6), '*' (6)] e o novo nó `'*'` (com frequência 9).
    - Inserimos o novo nó `'*'`, a fila fica:
      - [A (6), '*' (6), '*' (9)]

4. **Quarto loop**:
    - **Pegamos A (6) e '*' (6)** da fila:
    - Criamos um novo nó `novoNode` com `'*'` e frequência `6 + 6 = 12`.
    - Esse nó terá:
      - `esquerda` apontando para A,
      - `direita` apontando para o nó `'*'` (que contém D, F, e E).
    - A fila agora contém:
      - ['*' (9)] e o novo nó `'*'` (com frequência 12).
    - Inserimos o nó `'*'`, a fila fica:
      - ['*' (9), '*' (12)]

5. **Quinto loop (último)**:
    - **Pegamos '*' (9) e '*' (12)** da fila:
    - Criamos o nó final `novoNode` com `'*'` e frequência `9 + 12 = 21`.
    - Esse nó terá:
      - `esquerda` apontando para o nó `'*'` (que contém C e B),
      - `direita` apontando para o nó `'*'` (que contém A, D, F, e E).
    - Não sobram mais nós na fila, a árvore foi construída!

### Árvore final de Huffman:

A árvore de Huffman terá a seguinte estrutura em pré-ordem (usando '*' para nós internos):

```
          *
         / \
        *   *
       / \   / \
      C   B A   *
               / \
              D   *
                 / \
                F   E
```

### Explicação das linhas de `montando_arvore`:

1. **`if (fila == NULL || fila->proximo == NULL)`**: Caso a fila tenha apenas um nó, ele já é a árvore. Retornamos a fila como a árvore nesse caso.

2. **`*tamArvore = 0;`**: Inicializamos o contador do tamanho da árvore (usado para controle externo, como na escrita do cabeçalho).

3. **Loop `while (fila != NULL && fila->proximo != NULL)`**: Pegamos sempre os dois nós com as menores frequências da fila, criamos um novo nó pai `'*'` com a soma das frequências, e reinserimos esse novo nó na fila.

4. **`novoNode->esquerda = fila;` e **`novoNode->direita = fila->proximo;`**: O novo nó pai aponta para os dois nós removidos da fila.

5. **`fila = fila->proximo->proximo;`**: Removemos os dois nós da fila (os dois menores que acabamos de combinar).

6. **`fila = inserir_fila(fila, novoNode);`**: O novo nó pai é inserido de volta na fila, mantendo a ordem crescente por frequência.

7. **`if (fila != NULL)`**: Atualiza o tamanho da árvore quando sobrar apenas um nó na fila (a raiz final).

8. **Retorno**: A árvore completa é retornada no final.
