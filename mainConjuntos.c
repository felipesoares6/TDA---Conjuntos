#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkConjuntos.h"

int main(){
   int vValor, Num, Escolhe;
   int i, Atamanho, Btamanho;
   char EscolheConj;
   Tdesc *ConjuntoA, *ConjuntoB;
   ConjuntoA = (Tdesc *) malloc(sizeof(Tdesc));
   ConjuntoB = (Tdesc *) malloc(sizeof(Tdesc));

   criacao(ConjuntoA,ConjuntoB);

	 printf("Digite o tamanho do Conjunto A: ");
     scanf("%d", &Atamanho);
	 printf("\nDigite os valores do Conjunto A:\n");
   for (i = 0; i < Atamanho; i++) {
      scanf("%d", &Num);
      additem(ConjuntoA, Num);
    }
	 printf("\nDigite o tamanho do Conjunto B: ");
    scanf("%d", &Btamanho);
	 printf("\nDigite os valores do Conjunto B:\n");
   for (i = 0; i < Btamanho; i++) {
      scanf("%d", &Num);
      additem(ConjuntoB, Num);
    }

  	printf("\nConjunto A: ");
  	imprimir(ConjuntoA);
    printf("\nConjunto B: ");
    imprimir(ConjuntoB);
    printf("\n\n");
    printf("Digite um numero para verificar sua pertinencia ou -999 para sair\n");
    while(1)
    {  scanf("%d", &Num);
       if(Num == -999)
          break;
       printf("Digite o conjunto A ou B\n");
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
		  printf("\n");
        }
        if(Escolhe == 2)
        { printf("--->A diferença B-A eh: ");
          diferenca(ConjuntoB, ConjuntoA);
		  printf("\n");
        }
    }
    printf("\n\nDigite 1 - Produto de A menos B ou Digite 2 - Produto de B menos A -"
                                                      "Digite -999 para sair\n\n");
    while(1){
        scanf("%d", &Escolhe);
        if(Escolhe == -999)
          break;
        if(Escolhe == 1)
        { printf("--->O produto A-B eh: ");
          produto(ConjuntoA, ConjuntoB);
		      printf("\n");
        }
        if(Escolhe == 2)
        { printf("--->O produto B-A eh: ");
          produto(ConjuntoB, ConjuntoA);
		      printf("\n");
        }
    }
    printf("\n\n");
    printf("A uniao eh: ");
    uniao(ConjuntoA, ConjuntoB);
    printf("\n");
    printf("A interseccao eh: ");
    interseccao(ConjuntoA, ConjuntoB);
	  printf("\n");
	  equivalencia(ConjuntoA, ConjuntoB);
    printf("\n\n");

    printf("Cardinalidade do Conjunto A = %d\n", cardinalidade(ConjuntoA));
    printf("Cardinalidade do Conjunto B = %d\n\n", cardinalidade(ConjuntoB));

    while(1)
    { printf("De qual Conjunto deseja excluir (1-Conjunto A ou 2-Conjunto B) ?\n");
	  scanf("%d",&Escolhe);
      printf("Digite o valor que deseja excluir do conjunto\n");
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

    while(1){
      printf("Digite o conjunto a ser destruido(1- Conjunto A; 2- Conjunto B ou -999 Para Nenhum)\n");
      scanf("%d",&Escolhe);
      if(Escolhe == -999)
        break;
      else if(Escolhe == 1){
        destroi(ConjuntoA);
        printf("Conjunto A destruido com sucesso!\n");
      }else{
        destroi(ConjuntoB);
        printf("Conjunto B destruido com sucesso!\n");
      }

    }
    imprimir(ConjuntoA);
    printf("\n");
    imprimir(ConjuntoB);
    printf("\n");

    return 0;
}
