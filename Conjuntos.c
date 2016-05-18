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
/*
void uniao(Tlista *inicio,Tlista *inicio2);
void interseccao(Tlista *inicio,Tlista *inicio2,int qtd);
void diferenca12(Tlista *inicio,Tlista *inicio2);
void diferenca21(Tlista *inicio,Tlista *inicio2);

*/

int main(){
    int vValor, Num;
    int i, Atamanho, Btamanho, qtdmenor;
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

    if(Atamanho > Btamanho)
       qtdmenor = Atamanho;
    else
     qtdmenor = Btamanho;

    while(1){
       printf("Digite um numero para verificar sua pertinencia ou -999 para sair\n");
       scanf("%d", &Num);
       if(Num == -999)
          break;
       printf("Digite o conjunto A ou B\n");
       scanf(" %c", &EscolheConj);
       if(EscolheConj == 'A')
         if(pertinencia(ConjuntoA, Num))
           printf("O numero %d pertence ao conjunto A\n", Num);
        else
          printf("Valor não pertinente aos conjuntos\n");
       if(EscolheConj == 'B')
         if(pertinencia(ConjuntoB, Num))
             printf("O numero %d pertence ao conjunto B\n", Num);
       else
          printf("Valor não pertinente aos conjuntos\n");
    }
    /*
    uniao(inicio, inicio2);
    interseccao(inicio, inicio2, qtdmenor);
    diferenca12(inicio, inicio2);
    diferenca21(inicio, inicio2);
    */
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

/*
void uniao(Tlista *inicio, Tlista *inicio2)
{x
  Tlista *aux, *aux2;
  int cont;
  printf("A uniao eh: ");
  imprimir(inicio);
  aux2 = inicio2;
  while(1)
  { aux = inicio;
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
    { printf("\n\n");
      break;
    }
  }
}

void interseccao(Tlista *inicio, Tlista *inicio2,int qtd)
{
  int cont=0, i;
  Tlista *aux, *aux2;
  int vetor[qtd];

  aux = inicio;
  aux2 = inicio2;
  i = 0;
  while(aux != NULL){
    while(aux2 != NULL){
        if(aux->valor == aux2->valor)
        {
          vetor[cont] = aux->valor;
          cont++;
          if(aux->prox == NULL)
            break;
          aux=aux->prox;
          aux2=inicio2;
        }
        else
          aux2=aux2->prox;
    }
    aux=aux->prox;
    aux2=inicio2;
  }
  printf("A interseccao eh: ");
  for(i=0;i<cont;i++)
    printf("%d ", vetor[i]);
  printf("\n\n");
}

void diferenca12(Tlista *inicio,Tlista *inicio2)
{
  Tlista *aux, *aux2;
  int cont;
  printf("A diferença 1-2 eh: ");
  aux = inicio;
  while(1)
  { aux2 = inicio2;
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
    { printf("\n\n");
      break;
    }
  }
}

void diferenca21(Tlista *inicio,Tlista *inicio2)
{
  Tlista *aux, *aux2;
  int cont;
  printf("A diferença 2-1 eh: ");
  aux2 = inicio2;
  while(1)
  { aux = inicio;
    cont=0;
    while(aux != NULL)
    {
      if(aux->valor == aux2->valor)
        cont++;
      aux = aux->prox;
    }
    if(cont == 0)
      printf("%d ",aux2->valor);
    if(aux2->prox != NULL)
      aux2 = aux2->prox;
    else
    { printf("\n\n");
      break;
    }
  }
}
*/
