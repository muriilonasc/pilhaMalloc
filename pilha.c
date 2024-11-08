#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **dados;      // Ponteiro genérico para os elementos da fila
    int inicio;        // Índice do primeiro elemento
    int fim;           // Índice do último elemento
    int tamanho;       // Capacidade atual da fila
    int capacidade;    // Capacidade total da fila
    int ultimoIndice;
} Pilha;

// Função para criar a pilha
Pilha* criarPilha(int capacidadeInicial) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if (pilha == NULL) return NULL;  // Verifica se a alocação foi bem-sucedida

    pilha->dados = (void **) malloc(sizeof(void*) * capacidadeInicial);
    pilha->capacidade = capacidadeInicial;
    pilha->topo = -1;

    return pilha;
}

// função dobrarCapacidade
void dobrarCapacidade(Pilha *pilha) {
    int novaCapacidade = pilha->capacidade * 2;
    void **novosDados = (void **) malloc(sizeof(void*) * novaCapacidade);

    for (int i = 0; i < pilha->tamanho; i++) {
        novosDados[i] = pilha->dados[i];
    }

    free(pilha->dados);
    pilha->dados = novosDados;
    pilha->capacidade = novaCapacidade;
}

// Função inserirNaPilha
void inserirNaPilha(Pilha *pilha, void *item) {
    if (pilha->ultimoIndice + 1 == pilha->capacidade) {
        dobrarCapacidade(pilha);
    }

    pilha->dados[pilha->fim] = item;
    pilha->ultimoIndice++;
}

// Função removerDaPilha
void* removerDaPilha(Pilha *pilha) {
    if (fila->ultimoIndice == -1) {
        return NULL;  
    }

    void *item = pilha->dados[pilha->ultimoIndice];
    pilha->ultimoIndice--;
    return item;
}

// Função para limpar e liberar a pilha
void limparPilha(Pilha *pilha) {
    if (pilha != NULL) {
        free(pilha->dados);  // Libera a memória alocada para os dados
        free(pilha);         // Libera a memória da estrutura da fila
    }
}
