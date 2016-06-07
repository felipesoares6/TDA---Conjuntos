#include "linkConjuntos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flag=0;
void criacao( Tdesc *Conjunto)
{
  Conjunto->inicio = NULL;
  Conjunto->fim = NULL;
  Conjunto->qtd = 0;
}


void destroi(Tdesc *desc){
  if(desc != NULL){
    Tlista *aux;
    while(desc->inicio != NULL){
        aux = desc->inicio;
        desc->inicio = desc->inicio->prox;
        free(aux);
    }
  }
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

int excluir(Tdesc *desc, int valor){
	//excluir
  //printf("%d\n",valor );
	Tlista *aux=desc->inicio;
	int flag2=0;
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
	if(flag2 == 0)
		return 1;
	else
	   return 0;
}

void imprimir(Tdesc *desc){
  Tlista *aux;
  aux = desc->inicio;
	while(aux != NULL)
  {
    if(flag==0){
      printf("%d ", aux->valor);
    }
    else
    { printf("(%d, ", aux->valor);
      aux = aux->prox;
      printf("%d)",aux->valor );
      aux = aux->ant->prox;
    }
    aux = aux->prox;
	}
  flag=0;
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
      additem(descA,aux2->valor);
    if(aux2->prox != NULL)
      aux2 = aux2->prox;
    else
    {
      break;
    }
  }
}

void interseccao(Tdesc *descA, Tdesc *descB,Tdesc *descC){
  Tlista *aux, *aux2;
  aux = descA->inicio;
  aux2 = descB->inicio;
  while(aux != NULL){
    while(aux2 != NULL){
        if(aux->valor == aux2->valor){
          additem(descC,aux->valor);
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

void equivalencia(Tdesc *descA, Tdesc *descB)
{
	Tlista *aux, *aux2;
	int cont;
	aux = descA->inicio;
	aux2 = descB->inicio;
	cont = descA->qtd;
	int qtde = 0;
	while(aux != NULL){
		while(aux2 != NULL){
			if(aux->valor == aux2->valor){
				qtde++;
			if(aux->prox == NULL)
				break;
			aux = aux->prox;
			aux2 = descB->inicio;
			}
			else
				aux2 = aux2->prox;
		}
		aux = aux->prox;
		aux2 = descB->inicio;
	}
	if(qtde == cont)
		printf("Os conjuntos são equivalentes.");//////////////////////////////////
	else
		printf("Os conjuntos não são equivalentes.");/////////////////////////////////
}


void diferenca(Tdesc *descA,Tdesc *descB,Tdesc *descC)
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
      additem(descC,aux->valor);
    if(aux->prox != NULL)
      aux = aux->prox;
    else
    {
      break;
    }
  }
}
void produto(Tdesc *descA,Tdesc *descB,Tdesc *descC)
{
  Tlista *aux, *aux2;
  aux = descA->inicio;
  char valor[7];
  int i,j;
  while(aux!=NULL)
  { aux2 = descB->inicio;
    while(aux2 != NULL)
    {
      additem(descC,aux->valor);
      additem(descC,aux2->valor);
      flag=1;
      aux2 = aux2->prox;
    }
    aux = aux->prox;
  }
  imprimir(descC);
  destroi(descC);
}
