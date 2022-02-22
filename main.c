#include <gtk/gtk.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include "bibp2.h"

#define MAX1 100000

GtkWidget *frase;
GtkWidget *window;
GtkWidget *vbox;
GtkWidget *grid;
//gint handler_id;
List dicionario[MAX1];
int sinal=0;
char v[90];
char f[50];
char m[10];
char p[90];
int i=3,count=0,var=0;
int posicao=0,flag=0;
int j=0,b=0,g=0,c=0;
char* array[9] = { ".!?", "abc", "def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};
GDateTime* LastPressed = NULL;
GTimeSpan dif;
GDateTime *now;

char* next(List lista){
  List ant;
  List atual;
  ant = lista;
  atual = lista->next;
  strcat(v,atual->info.string);
  gtk_label_set_text((GtkLabel *)frase,v);
  return atual->info.string;
}

char* next1(List lista,char* chave){
  List ant;
  List atual;
  ant = lista;
  atual = lista->next;
  //char ch = '*';
  while(strcmp(atual->info.string,chave)!=0){
    //ant = lista;
    //atual = lista->next;
    ant = atual;
    atual = atual->next;
  }
  ant = atual;
  atual = atual->next;
  if(atual==NULL){
    ant = lista;
    atual = lista->next;
  }
  //g_print("%s", atual->info.string);
  strcat(v,atual->info.string);
  gtk_label_set_text((GtkLabel *)frase,v);
  return atual->info.string;
}

void tempo(int n){
  now = g_date_time_new_now_local();
  if(n < 10){
    char a[20];
    strcpy(a, array[n-1]);
    g_print("%s %d\n", array[n], n);
  if(LastPressed != NULL){
    dif = g_date_time_difference(now,LastPressed);
    if(dif < 500000){
        if (b<strlen(a)-1 && a[b]<128) b++;
        else if (b<strlen(a)-2 && a[b]>127) b++;
        else b=0;
    }
    else{
      b=0; // letra da palavra
      g++; //posicao da palavra (carregador tambem)
      var++;
    }
  }
  if(g > 0 && v[g-1]>192){
    f[var--] = '\0';
    f[var] = '\0';
    v[g--] = 0;
    v[g] = 0;
  }
  if(a[b]>127){
    c=b;
    f[var++] = a[c++];
    f[var] = a[c];
      v[g++] = a[b++];
      v[g] = a[b];
    }
  else {
    f[var]=a[b];
    v[g] = a[b];
  }
  LastPressed = g_date_time_new_now_local();
  gtk_label_set_text((GtkLabel *) frase, v);
  }
}

void button1_clicked(GtkWidget *widget, gpointer data) {
  g_print("1 .!?\n");
  tempo(1);
}

void button2_clicked(GtkWidget *widget, gpointer data) {
  g_print("2 abc\n");
    if(flag==1){
    strcat(v,"2");
    if(j<5){
      m[j]='2';
      posicao = posicao*10 + 2;
    }
    j++;
    count=0;
    i=3;
      gtk_label_set_text((GtkLabel *)frase,v);
    }else{
      tempo(2);

    }
}
void button3_clicked(GtkWidget *widget, gpointer data) {
  g_print("3 def\n");
  if(flag==1){
  strcat(v,"3");
  if(j<5){
    m[j]='3';
    posicao = posicao*10 + 3;
  }
  j++;
  count=0;
  i=3;
    gtk_label_set_text((GtkLabel *)frase,v);
  }else{
    tempo(3);
  }
}
void button4_clicked(GtkWidget *widget, gpointer data) {
  g_print("4 ghi\n");
  if(flag==1){
  strcat(v,"4");
  if(j<5){
    m[j]='4';
    posicao = posicao*10 + 4;
  }
  j++;
  count=0;
  i=3;
  gtk_label_set_text((GtkLabel *)frase,v);
}else{
  tempo(4);
}
}
void button5_clicked(GtkWidget *widget, gpointer data) {
  g_print("5 jkl\n");
    if(flag==1){
    strcat(v,"5");
    if(j<5){
      m[j]='5';
      posicao = posicao*10 + 5;
    }
    j++;
    count=0;
    i=3;
      gtk_label_set_text((GtkLabel *)frase,v);
    }else{
      tempo(5);
    }
}
void button6_clicked(GtkWidget *widget, gpointer data) {
  g_print("6 mno\n");
    if(flag==1){
    strcat(v,"6");
    if(j<5){
      m[j]='6';
      posicao = posicao*10 + 6;
    }
    j++;
    count=0;
    i=3;
      gtk_label_set_text((GtkLabel *)frase,v);
    }else{
      tempo(6);
    }
}
void button7_clicked(GtkWidget *widget, gpointer data) {
  g_print("7 pqrs\n");
    if(flag==1){
    strcat(v,"7");
    if(j<5){
      m[j]='7';
      posicao = posicao*10 + 7;
    }
    j++;
    count=0;
    i=3;
      gtk_label_set_text((GtkLabel *)frase,v);
    }else{
      tempo(7);
    }
}
void button9_clicked(GtkWidget *widget, gpointer data) {
  g_print("9 wxyz\n");
    if(flag==1){
    strcat(v,"9");
    if(j<5){
      m[j]='9';
      posicao = posicao*10 + 9;
    }
    j++;
    count=0;
    i=3;
      gtk_label_set_text((GtkLabel *)frase,v);
    }else{
      tempo(9);
    }
}
void button0_clicked(GtkWidget *widget, gpointer data) {
    g_print("0 Space\n");
    strcat(v," ");
    for(int p = 0; p < 5 ;p++){
      m[p]='\0';
    }
    //pesquisa(dicionario[posicao], p);
    j=0;
    posicao=0;
    count=0;
    i=3;
    gtk_label_set_text((GtkLabel *)frase,v);


}
void buttonast_clicked(GtkWidget *widget, gpointer data) {
    g_print("* Cicle\n");
    if(flag==1){
      if(isdigit(v[strlen(v)-1])){
      if(!lista_vazia(dicionario[posicao])){
      while(j>0){
        v[strlen(v)-1]='\0';
        j--;
      }
      strcpy(p,next(dicionario[posicao]));
      j = strlen(p);
      }
    } else if(isalpha(v[strlen(v)-1])){
        while(j>0){
          v[strlen(v)-1]='\0';
          j--;
        }
        strcpy(p,next1(dicionario[posicao],p));
        j = strlen(p);
    }
    count=0;
    i=3;
      gtk_label_set_text((GtkLabel *)frase,v);
    }else{
      g_print("* Cicle\n");
      var++;
      f[var]='\0';
      posicao = num(f);
      pesquisa(dicionario[posicao],f);
      var=0;
      posicao=0;
      //f[0]='\0';
      /*
      word[j] = '\0';
      posicao = num(word);
      pesquisa(dicionario[posicao], word);
      posicao = 0;
      j = 0;
      word[0]='\0';
      */

    }
}
void buttonash_clicked(GtkWidget *widget, gpointer data) {
    g_print("# Delete\n"); //printa no terminal
    if(flag==1){
    if(!isalpha(v[strlen(v)-1]) && !isdigit(v[strlen(v)-1])){
      //g_print("Entra1");
      v[strlen(v)-1]='\0';    //apaga o ultimo caracter
    } else if(isalpha(v[strlen(v)-1])){ // v[5,8,7,4,2] = v[l,u,s,i,a, ,m,a,r,c,o]
        while(isalpha(v[strlen(v)-1])){
          //g_print("Entra2");
          v[strlen(v)-1]='\0';
        }
        for(int p=0;m[p]!='\0' && p<5 ;p++){
          v[strlen(v)]=m[p];
        }

      // 23456 -> marco marcos      pala[]
    } else if(isdigit(v[strlen(v)-1])){
      //printf("j==%d",j);
      if(j<=5 && j>-1){
        //g_print("Entra3");
        v[strlen(v)-1]='\0';
        posicao=posicao/10;
        //g_print("%d",posicao);
        j--;
      }else{
        //g_print("Entra4");
        v[strlen(v)-1]='\0';
        j--;
      }
    }
    count=0;
    i=3;
      gtk_label_set_text((GtkLabel *)frase,v);
    } else {
      v[strlen(v)-1] = '\0'; //apaga o ultimo caracter
      gtk_label_set_text((GtkLabel*)frase, v);
    }
}
void button8_clicked(GtkWidget *widget, gpointer data) {
    if(flag==1){
    g_print("8 tuv\n");
    strcat(v,"8");
    if(j<5){
      m[j]='8';
      posicao = posicao*10 + 8;
    }
    j++;
    count=0;
    i=3;
      gtk_label_set_text((GtkLabel *)frase,v);
    }else{
      tempo(8);
    }
}

void toogle_signal(GtkWidget *widget, gpointer data){
  g_print("Mudou\n");
  sinal++;
  if(sinal%2 == 0){
    flag = 0;
    g_print("flag1=%d",flag);
  }
  else {
    flag = 1;
    g_print("flag2=%d",flag);
  }

}

int main(int argc, char *argv[]) {

  GtkWidget *togglebt;
  GtkWidget *button0;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button5;
  GtkWidget *button6;
  GtkWidget *button7;
  GtkWidget *button8;
  GtkWidget *button9;
  GtkWidget *buttonast;
  GtkWidget *buttonash;


for(int j = 0; j < MAX1; j++){
  dicionario[j] = cria_lista();
}

//int posicao = 0;
char word[50];
word[0] = '\0';

setlocale(LC_ALL, "en_US.UTF-8");
FILE* fin;
wint_t wc;
char ch;
fin=fopen ("in.txt","r");
//fin = fopen(argv[1], "r");
while((wc=fgetwc(fin))!=WEOF){
  ch = troca(wc);
  ch = tolower(ch);
  if(!isalpha(ch) && (word[0] != '\0')){
    word[j] = '\0';
    posicao = num(word);
    pesquisa(dicionario[posicao], word);
    posicao = 0;
    j = 0;
    word[0]='\0';
  }
  else if(isalpha(ch)){
      word[j++] = ch;
  }
}
fclose(fin);
/*
FILE * fos = fopen("out.txt","w");
for(int h=0; h<MAX1;h++){
  List lista = dicionario[h];
  List curr = lista;
  while(curr!=NULL){
    if(strlen(curr->info.string)==0){
      curr=curr->next;
      continue;
    }
    fprintf(fos,"%s\n",curr->info.string);
    curr= curr->next;
  }
}
fclose(fos);
*/

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 180);
  gtk_window_set_title(GTK_WINDOW(window), "T9");
  gtk_container_set_border_width(GTK_CONTAINER(window), 5);
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,1);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  grid = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(grid),2);
  gtk_grid_set_column_spacing(GTK_GRID(grid),140);

  button0 = gtk_button_new_with_label("     0\nSpace");
  gtk_grid_attach(GTK_GRID(grid), button0, 1, 3, 2, 1);
  button1 = gtk_button_new_with_label(" 1\n.!?");
  gtk_grid_attach(GTK_GRID(grid), button1, 0, 0, 2, 1);
  button2 = gtk_button_new_with_label("   2\nabc");
  gtk_grid_attach(GTK_GRID(grid), button2, 1, 0, 2, 1);
  button3 = gtk_button_new_with_label("   3\ndef");
  gtk_grid_attach(GTK_GRID(grid), button3, 2, 0, 2, 1);
  button4 = gtk_button_new_with_label("   4\nghi");
  gtk_grid_attach(GTK_GRID(grid), button4, 0, 1, 2, 1);
  button5 = gtk_button_new_with_label(" 5\njkl");
  gtk_grid_attach(GTK_GRID(grid), button5, 1, 1, 2, 1);
  button6 = gtk_button_new_with_label("    6\nmno");
  gtk_grid_attach(GTK_GRID(grid), button6, 2, 1, 2, 1);
  button7 = gtk_button_new_with_label("    7\npqrs");
  gtk_grid_attach(GTK_GRID(grid), button7, 0, 2, 2, 1);
  button8 = gtk_button_new_with_label("  8\ntuv");
  gtk_grid_attach(GTK_GRID(grid), button8, 1, 2, 2, 1);
  button9 = gtk_button_new_with_label("    9\nwxyz");
  gtk_grid_attach(GTK_GRID(grid), button9, 2, 2, 2, 1);
  buttonast = gtk_button_new_with_label("    *\nCicle");
  gtk_grid_attach(GTK_GRID(grid), buttonast, 0, 3, 2, 1);
  buttonash = gtk_button_new_with_label("     #\nDelete");
  gtk_grid_attach(GTK_GRID(grid), buttonash, 2, 3, 2, 1);
  //buttonbt = gtk_button_new_with_label("botaofds");
  //gtk_grid_attach(GTK_GRID(grid), buttonbt, 2, 4, 2, 3);
  togglebt = gtk_toggle_button_new_with_label("Modo Inteligente");
  gtk_box_pack_start(GTK_BOX(vbox),togglebt,FALSE,FALSE,0);
  g_signal_connect(G_OBJECT(togglebt), "clicked", G_CALLBACK(toogle_signal), NULL);

  frase = gtk_label_new(NULL);
  gtk_box_pack_start(GTK_BOX(vbox),frase,TRUE,TRUE,20);
  gtk_widget_modify_font(frase,pango_font_description_from_string("25.4"));

  gtk_container_add(GTK_CONTAINER(vbox), grid);

  j = 0;
  flag = 0;
  //char signal;



  g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(button1_clicked), NULL);
  g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(button2_clicked), NULL);
  g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(button3_clicked), NULL);
  g_signal_connect(G_OBJECT(button4), "clicked", G_CALLBACK(button4_clicked), NULL);
  g_signal_connect(G_OBJECT(button5), "clicked", G_CALLBACK(button5_clicked), NULL);
  g_signal_connect(G_OBJECT(button6), "clicked", G_CALLBACK(button6_clicked), NULL);
  g_signal_connect(G_OBJECT(button7), "clicked", G_CALLBACK(button7_clicked), NULL);
  g_signal_connect(G_OBJECT(button8), "clicked", G_CALLBACK(button8_clicked), NULL);
  g_signal_connect(G_OBJECT(button9), "clicked", G_CALLBACK(button9_clicked), NULL);
  g_signal_connect(G_OBJECT(button0), "clicked", G_CALLBACK(button0_clicked), NULL);
  g_signal_connect(G_OBJECT(buttonast), "clicked", G_CALLBACK(buttonast_clicked), NULL);
  g_signal_connect(G_OBJECT(buttonash), "clicked", G_CALLBACK(buttonash_clicked), NULL);
  //g_signal_connect(G_OBJECT(togglebt), "clicked", G_CALLBACK(toogle_signal),NULL);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), G_OBJECT(window));
  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}
