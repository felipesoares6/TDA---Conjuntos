/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reglista{
  int valor;
  struct reglista *prox;
  struct reglista *ant;
}Tlista;

typedef struct regDesc{
  Tlista *inicio;
  Tlista *fim;
  int qtd;
}Tdesc;

//void criacao( Tdesc *,int);
//void destruicao
void additem(Tdesc *, int);
int excluir(Tdesc *, char);
void imprimir(Tdesc *);
void uniao(Tdesc *,Tdesc *);
void interseccao(Tdesc *,Tdesc *);
void diferenca(Tdesc *,Tdesc *);
void produto(Tdesc *,Tdesc *);
int pertinencia(Tdesc *, int);
//
int cardinalidade(Tdesc *);

int main(){
    int vValor, Num, Escolhe;
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
    //criacao(ConjuntoA,Atamanho);
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
    printf("Digite um numero para verificar sua pertinencia ou -999 para sair");
    while(1)
    { scanf("%c", &EscolheConj);
       scanf("%d", &Num);
       if(Num == -999)
          break;
       printf("Digite o conjunto A ou B");
       scanf(" %c", &EscolheConj);
       if(EscolheConj == 'A')
         if(pertinencia(ConjuntoA, Num))
           printf("\n\n--->O numero %d pertence ao conjunto A\n\n", Num);
        else
          printf("\n\n--->Valor não pertinente aos conjuntos\n\n");
       if(EscolheConj == 'B')
         if(pertinencia(ConjuntoB, Num))
             printf("\n\n--->O numero %d pertence ao conjunto B\n\n", Num);
       else
          printf("\n\n--->Valor não pertinente aos conjuntos\n\n");
    }

    printf("Digite 1 - Diferenca de A menos B ou Digite 2 - Diferenca de B menos A -"
                                                      "Digite -999 para sair\n\n");
    while(1){
        scanf("%d", &Escolhe);
        if(Escolhe == -999)
          break;
        if(Escolhe == 1)
        {  printf("--->A diferença A-B eh: ");
          diferenca(ConjuntoA, ConjuntoB);
        }
        if(Escolhe == 2)
        { printf("--->A diferença B-A eh: ");
          diferenca(ConjuntoB, ConjuntoA);
        }
    }
    printf("\n\nDigite 1 - Produto de A menos B ou Digite 2 - Produto de B menos A -"
                                                      "Digite -999 para sair\n\n");
    while(1){
        scanf("%d", &Escolhe);
        if(Escolhe == -999)
          break;
        if(Escolhe == 1)
        {  printf("--->O produto A-B eh: ");
          produto(ConjuntoA, ConjuntoB);
        }
        if(Escolhe == 2)
        { printf("--->O produto B-A eh: ");
          produto(ConjuntoB, ConjuntoA);
        }
    }
    printf("\n\n");
    printf("A uniao eh: ");
    uniao(ConjuntoA, ConjuntoB);
    printf("\n");
    printf("A interseccao eh: ");
    interseccao(ConjuntoA, ConjuntoB);
    printf("\n\n");

    printf("Cardinalidade do Conjunto A = %d\n", cardinalidade(ConjuntoA));
    printf("Cardinalidade do Conjunto B = %d\n\n", cardinalidade(ConjuntoB));

    while(1)
    { printf("De qual Conjunto deseja excluir ?\n");
      printf("Digite o valor que deseja excluir do conjunto\n");
      scanf("%d",&Escolhe);
      scanf("%d",&Num);
      if(Num == -999)
          break;
      if(Escolhe == 1)
        if(excluir(ConjuntoA,Num)== 0)
          imprimir(ConjuntoA);
      if(Escolhe == 2)
        if(excluir(ConjuntoB,Num)== 0)
          imprimir(ConjuntoB);
      printf("\n");
    }
    return 0;
}

void additem(Tdesc *desc,int valor){
	Tlista *aux;
	aux = (Tlista *) malloc(sizeof(Tlista));
	aux->valor = valor;
	aux->prox = NULL;

	if (desc->inicio == NULL)
	{
		desc->inicio = aux;
		aux->ant  = NULL;
	}
	else
	{
		desc->fim->prox = aux;
		aux->ant = desc->fim;
	}
	desc->fim = aux;
  desc->qtd++;
}

int excluir(Tdesc *desc, char valor){
	//excluir
  printf("%d\n",valor );
	Tlista *aux=desc->inicio;
	int flag=0;
	while (aux != NULL)
	{
		if(valor == aux->valor)
		{		if(aux->ant == NULL && aux->prox == NULL)
				{		desc->inicio = NULL;
						desc->fim = NULL;
				}
				else if (aux->ant == NULL)
				{	desc->inicio = aux->prox;
					aux->prox->ant = NULL;
				}
				else if(aux->prox == NULL)
				{
					desc->fim = aux->ant;
					aux->ant->prox = NULL;
				}
				else
				{
					aux->ant->prox = aux->prox;
					aux->prox->ant = aux->ant;
				}
				free(aux);
				flag++;
		}
		aux = aux->prox;
	}
	if(flag == 0)
		return 1;
	else
	   return 0;
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

int cardinalidade(Tdesc *desc){
  Tlista *aux;
  int cont=0;
  aux = desc->inicio;
  while(aux!= NULL){
    cont++;
    aux=aux->prox;
  }
  return cont;
}

void diferenca(Tdesc *descA,Tdesc *descB)
{
  Tlista *aux, *aux2;
  aux = descA->inicio;
  int cont;
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
void produto(Tdesc *descA,Tdesc *descB)
{
  Tlista *aux, *aux2;
  aux = descA->inicio;

  int i,j;
  while(aux!=NULL)
  { aux2 = descB->inicio;
    while(aux2 != NULL)
    {
      printf("(%d,%d)",aux->valor,aux2->valor );
      aux2 = aux2->prox;
    }
    aux = aux->prox;
  }
}
