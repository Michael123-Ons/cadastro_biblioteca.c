//definição da struct do livro

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIVROS 100

typedef struct {
    int id;
    char titulo[50];
    char autor[50];
    int ano;
    int disponivel; //1 = disponivel // 0 = emprestado
} Livro;

//variáveis globais e menu principal

Livro livros[MAX_LIVROS]; //vetor da struct
int totalLivros = 0; //contador

//protótipo das funções

void cadastrarLivro();
void buscarLivro();
void listarLivros();
void exibirLivro(Livro *livro);
void emprestarLivro();

int main() {
    int opcao;
    do {
        printf("\n--- Biblioteca ---\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Buscar Livro\n");
        printf("3. Listar Livros\n");
        printf("4. Emprestar Livro\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();


        switch (opcao) {
            case 1: cadastrarLivro(); break;
            case 2: buscarLivro(); break;
            case 3: listarLivros(); break;
            case 4: emprestarLivro(); break;
            case 5: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        } 
    } while (opcao != 5);
    return 0;
}

//função do cadastro

void cadastrarLivro() {
    if (totalLivros >= MAX_LIVROS) {
        printf("Biblioteca cheia!\n");
        return;
    }

    Livro *livro = &livros[totalLivros]; //ponteiro para novo livro

    printf("ID: ");
    scanf("%d", &livro->id);
    getchar;

    printf("Título: ");
    fgets(livro->titulo, 50, stdin);
    livro->titulo[strcspn(livro->titulo, "\n")] = '\0';

    printf("Autor: ");
    fgets(livro->autor, 50, stdin);
    livro->autor[strcspn(livro->autor, "\n")] = '\0';

    printf("Ano: ");
    scanf("%d", &livro->ano);
    getchar();

    livro->disponivel = 1;
    totalLivros++;
    printf("Livro cadastrado com sucesso!\n");

}

//função para buscar um livro

void buscarLivro() {
    int opcao; 
    printf("Buscar por:\n1. ID\n2. Título\nOpção: ");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1) {
        int id;
        printf("ID: ");
        scanf("%d", &id);
        getchar();
        for (int i = 0; i < totalLivros; i++) {
            if (livros[i].id == id) {
                exibirLivro(&livros[i]);
                return;
            }
        }
    }
    printf("Livro não encontrado!\n");
}

//função de exibição dos detalhes do livro

void exibirLivro(Livro *livro) {      //recebendo o ponteiro
    printf("\n--- Livro ---\n");
    printf("ID: %d\n", livro->id);
    printf("Título: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano: %d\n", livro->ano);
    printf("Status: %s\n", livro->disponivel ? "Disponível" : "Emprestado");
}

//função para listar todos livros

void listarLivros() {
    printf("\n--- Todos os Livros ---\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("%d. %s (%s)\n", livros[i].id, livros[i].titulo, livros[i].autor);
    }
}


//função para emprestar livro

void emprestarLivro() {
    int id;
    printf("ID do livro: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].id == id) {
            if (livros[i].disponivel) {
                livros[i].disponivel = 0;
                printf("Livro emprestado!\n");
            } else {
                printf("Livro já emprestado!\n");
            }
            return;  
        }
    }
    printf("Livro não encontrado!\n");
}