#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "bibp2.h"

///done
List cria_lista (void){
    List aux;
    aux = (List) malloc(sizeof (List));
    if (aux != NULL) {
        aux->info.num = 0;
        aux->next = NULL;
    }
    return aux;
}

//done
void procura_lista (List lista, char* chave, List *ant, List *atual){
  //fprintf(stderr,"%s\n",chave);
    *ant = lista;
    *atual = lista->next;
    while ((*atual) != NULL ){
        if(strcmp((*atual)->info.string, chave) == 0){
            int num = (*atual)->info.num;
            (*ant)->next = (*atual)->next;
            //free(atual);
            num++;
            insere_lista(lista, num, chave);
            return;
        }
        *ant = *atual;
        *atual = (*atual)->next;
    }

    //if (atual != NULL && (strcmp((*atual)->info.string, chave) != 0))
        insere_lista(lista, 1, chave);
}

//done
void pesquisa (List lista, char* it){
    List ant;
    List atual;
    procura_lista (lista, it, &ant, &atual);
}

//done
void insere_lista (List lista, int num, char* chave){ //ordenado
    //fprintf(stderr,"%s\n",chave);
    List ant;
    List atual;
    ant = lista;
    atual = lista->next;
    List aux = cria_lista();
    aux->info.num = num;
    strcpy(aux->info.string, chave);
    //memcpy(no, it, sizeof(*it));
    while (atual != NULL && atual->info.num >= num){
        ant = atual;
        atual = atual->next;
    }
    ant->next = aux;
    aux->next = atual;
    //free(aux);
}



///done
int num(char* word){
    int i = 0;
    int num = 0;
    char ch;
    char word1[20];
    strcpy(word1,word);
    word1[5]= '\0';
    while(word1[i] != '\0'){
        ch = word1[i];
        switch (ch){
            case 'a': case 'b': case 'c':
                num = num*10 + 2;
                break;
            case 'd': case 'e': case 'f':
                num = num*10 + 3;
                break;
            case 'g': case 'h': case 'i':
                num = num*10 + 4;
                break;
            case 'j': case 'k': case 'l':
                num = num*10 + 5;
                break;
            case 'm': case 'n': case 'o':
                num = num*10 + 6;
                break;
            case 'p': case 'q': case 'r': case 's':
                num = num*10 + 7;
                break;
            case 't': case 'u': case 'v':
                num = num*10 + 8;
                break;
            case 'w': case 'x': case 'y': case 'z':
                num = num*10 + 9;
                break;
        }
        i++;
    }
    return num;
}

//done
char troca(wint_t wc){
    char ch;
    switch (wc){
      case 225: case 224: case 227 : case 226 :
          ch = 'a';
          return ch;
        case 232 : case 233 : case 234 :
          ch = 'e';
          return ch;
        case 236 : case 237 : case 238 :
          ch = 'i';
          return ch;
        case 243: case 242 : case 244 : case 245 :
          ch = 'o';
          return ch;
        case 249 : case 250 : case 251 :
          ch = 'u';
          return ch;
        case 231:
          ch = 'c';
          return ch;
        default:
          ch = wc;
          return ch;
      }
}

////done
    int change(int flag){
          if(flag == 1) flag = 0;
          else if(flag == 0) flag = 1;
          return flag;
    }
//////////////////////////////////
    void opcao(List lista){
      List ant;
      List atual;
      ant = lista;
      atual = lista->next;
      while (atual != NULL ){
        printf("%s", atual->info.string);
        ant = atual;
        atual = atual->next;
      }
    }

    int lista_vazia(List lista){
    return (lista->next == NULL ? 1 : 0);
}
