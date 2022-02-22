typedef struct nodes* List;
typedef struct lwords{
    char string[40];
    int num;
}List_words;

typedef struct nodes {
    List_words info;
    List next;
} nodes;

int num(char* word);//

char troca(wint_t wc);//

List cria_lista (void);//

int change(int flag);//

void pesquisa (List lista, char* it);//

void procura_lista (List lista, char* chave, List *ant, List *atual);//

void insere_lista (List lista, int num, char* chave);//

void opcao(List lista);

int lista_vazia(List lista);
