/*
	Autores:    Felipe Luiz Soares 0030481511012
		    Jean Vitor         0030481511019
	Exercício 4 da lista 1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reglista{
  int valor;
  struct reglista *prox;
}Tlista;

typedef struct regDesc{
  Tlista *inicio;
  Tlista *fim;
  int qtd;
}Tdesc;

void additem(Tdesc *, int);
void imprimir(Tdesc *);
int pertinencia(Tdesc *, int);

void uniao(Tdesc *,Tdesc *);
void interseccao(Tdesc *,Tdesc *);
void diferenca(Tdesc *,Tdesc *);


int main(){
    int vValor, Num, EscolheDif;
    int i, Atamanho, Btamanho;
    char EscolheConj;
    Tdesc *ConjuntoA, *ConjuntoB;

    ConjuntoA = (Tdesc *) malloc(sizeof(Tdesc));
    ConjuntoB = (Tdesc *) malloc(sizeof(Tdesc));

    ConjuntoA->inicio = NULL;
    ConjuntoB->inicio = NULL;
    ConjuntoA->fim = NULL;
    ConjuntoB->fim = NULL;

    scanf("%d", &Atamanho);
    for (i = 0; i < Atamanho; i++) {
      scanf("%d", &Num);
      additem(ConjuntoA, Num);
    }
    scanf("%d", &Btamanho);
    for (i = 0; i < Btamanho; i++) {
      scanf("%d", &Num);
      additem(ConjuntoB, Num);
    }

  	printf("\nLista 1: ");
  	imprimir(ConjuntoA);
    printf("\nLista 2: ");
    imprimir(ConjuntoB);
    printf("\n\n");

    // while(1){
    //    printf("Digite um numero para verificar sua pertinencia ou -999 para sair\n");
    //    scanf("%d", &Num);
    //    if(Num == -999)
    //       break;
    //    printf("Digite o conjunto A ou B\n");
    //    scanf(" %c", &EscolheConj);
    //    if(EscolheConj == 'A')
    //      if(pertinencia(ConjuntoA, Num))
    //        printf("O numero %d pertence ao conjunto A\n", Num);
    //     else
    //       printf("Valor não pertinente aos conjuntos\n");
    //    if(EscolheConj == 'B')
    //      if(pertinencia(ConjuntoB, Num))
    //          printf("O numero %d pertence ao conjunto B\n", Num);
    //    else
    //       printf("Valor não pertinente aos conjuntos\n");
    //
    //
    // }

    printf("Digite 1 - Diferenca de A menos B ou Digite 2 - Diferenca de B menos A\n\n");
    while(1){
        scanf("%d", &EscolheDif);
        if(EscolheDif == -999)
          break;
        if(EscolheDif == 1)
        {  printf("\nA diferença 1-2 eh: ");
          diferenca(ConjuntoA, ConjuntoB);
        }
        if(EscolheDif == 2)
        { printf("A diferença 2-1 eh: ");
          diferenca(ConjuntoB, ConjuntoA);
        }
    }
    printf("\n\n");
    printf("A uniao eh: ");
    uniao(ConjuntoA, ConjuntoB);
    printf("\n");
    printf("A interseccao eh: ");
    interseccao(ConjuntoA, ConjuntoB);
    printf("\n");
    return 0;
}

void additem(Tdesc *desc, int valor){
  Tlista *aux;
  aux = (Tlista *)malloc(sizeof(Tlista));
  aux->valor = valor;
  aux->prox = NULL;
  if(desc->inicio == NULL)
    desc->inicio = aux;
  else
    desc->fim->prox = aux;

  desc->fim = aux;
  desc->qtd++;
}

void imprimir(Tdesc *desc){
  Tlista *aux;
  aux = desc->inicio;
	while(aux != NULL){
    printf("%d ", aux->valor);
		aux = aux->prox;
	}
}

int pertinencia(Tdesc *desc, int valor){
  Tlista *aux;
  aux = (Tlista *)malloc(sizeof(Tlista));
  aux = desc->inicio;
  while(aux != NULL){
    if(aux->valor == valor)
      return 1;
    aux = aux->prox;
  }
  return 0;
}


void uniao(Tdesc *descA,Tdesc *descB)
{
  Tlista *aux, *aux2;
  int cont;
  imprimir(descA);
  aux2 = descB->inicio;
  while(1)
  { aux = descA->inicio;
    cont=0;
    while(aux != NULL)
    {
      if(aux->valor == aux2->valor)
        cont++;
      aux = aux->prox;
    }
    if(cont == 0)
      printf("%d ",aux2->valor );
    if(aux2->prox != NULL)
      aux2 = aux2->prox;
    else
    {
      break;
    }
  }
}

void interseccao(Tdesc *descA, Tdesc *descB){
  Tlista *aux, *aux2;
  aux = descA->inicio;
  aux2 = descB->inicio;
  while(aux != NULL){
    while(aux2 != NULL){
        if(aux->valor == aux2->valor){
          printf("%d ", aux->valor);
          if(aux->prox == NULL)
            break;
          aux=aux->prox;
          aux2=descB->inicio;
        }
        else
          aux2=aux2->prox;
    }
    aux=aux->prox;
    aux2=descB->inicio;
  }
}

void diferenca(Tdesc *descA,Tdesc *descB)
{
  Tlista *aux, *aux2;
  int cont;
  aux = descA->inicio;
  while(1)
  { aux2 = descB->inicio;
    cont=0;
    while(aux2 != NULL)
    {
      if(aux->valor == aux2->valor)
        cont++;
      aux2 = aux2->prox;
    }
    if(cont == 0)
      printf("%d ",aux->valor);
    if(aux->prox != NULL)
      aux = aux->prox;
    else
    {
      break;
    }
  }
}
