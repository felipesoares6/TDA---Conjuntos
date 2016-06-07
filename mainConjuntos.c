#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkConjuntos.h"

int main(){
    int vValor, Num, Escolhe, opcao;
    int i, j = 1, tamanho, EscolheConj;
	   Tdesc *Conjunto[5001];

	printf("\nEscolha a operacao a ser feita:\n");
	printf("1 - Criar Conjunto\n");
  printf("2 - Inserir elemento\n");
	printf("3 - Pertinencia de elemento a conjunto\n");
	printf("4 - Equivalencia de conjuntos\n");
	printf("5 - Cardinalidade do conjunto\n");
	printf("6 - União\n");
	printf("7 - Interseccao\n");
	printf("8 - Diferenca\n");
	printf("9 - Produto Cartesiano\n");
	printf("10 - Exclusao \n");
	printf("11 - Destruir\n");
  printf("12 - Imprimir\n");
	printf("13 - Sair\n");

	scanf("%d", &opcao);
	while (opcao != 13){
		switch(opcao)
		{
			case 1:
				Conjunto[j] = (Tdesc *) malloc(sizeof(Tdesc));
				criacao(Conjunto[j]);
        j++;
      break;

      case 2:
        printf("\nDigite o conjunto\n");
        scanf("%d", &EscolheConj);
        printf("Digite o tamanho do Conjunto: ");
				scanf("%d", &tamanho);
				printf("Digite os valores do Conjunto:\n");
				for (i = 0; i < tamanho; i++) {
					scanf("%d", &Num);
					additem(Conjunto[EscolheConj], Num);
				 }
      break;

			case 3:
				printf("Digite um numero para verificar sua pertinencia\n");
				scanf("%d", &Num);
  			printf("Digite o conjunto:\n");
  			scanf(" %d", &EscolheConj);
  			if(pertinencia(Conjunto[EscolheConj], Num))
  				printf("\n\n--->O numero %d pertence ao conjunto\n\n", Num);
  			else
  				printf("\n\n--->Valor não pertinente aos conjuntos\n\n");
			break;

			case 4:
        printf("Digite os dois conjuntos para verificar equivalencia\n");
        scanf("%d", &EscolheConj);
        vValor = EscolheConj;
        scanf("%d", &EscolheConj);
				equivalencia(Conjunto[vValor], Conjunto[EscolheConj]);
				printf("\n");
			break;

			case 5:
        printf("Digite os dois conjuntos para verificar a Cardinalidade\n");
        scanf("%d", &EscolheConj);
				printf("Cardinalidade do Conjunto %d = %d\n\n", EscolheConj,cardinalidade(Conjunto[EscolheConj]));
			break;

			case 6:
        printf("Digite os dois conjuntos para fazer a uniao entre eles!\n");
        scanf("%d", &EscolheConj);
        vValor = EscolheConj;
        scanf("%d", &EscolheConj);
				uniao(Conjunto[vValor], Conjunto[EscolheConj]);
        printf("Esta união foi armazenada no primeiro conjunto digitado\n");
				printf("\n");
			break;

			case 7:
        printf("Digite os dois conjuntos para fazer a interseccao entre eles!\n");
        scanf("%d", &EscolheConj);
        vValor = EscolheConj;
        scanf("%d", &EscolheConj);
        Conjunto[j] = (Tdesc *) malloc(sizeof(Tdesc));
				criacao(Conjunto[j]);
        interseccao(Conjunto[vValor], Conjunto[EscolheConj],Conjunto[j]);
        printf("Esta interseccao foi armazenada no conjunto %d\n",j);
				printf("\n");
        j++;
			break;

			case 8:
				printf("Digite os dois conjuntos para fazer a diferenca entre eles!\n");
        scanf("%d", &EscolheConj);
        vValor = EscolheConj;
        scanf("%d", &EscolheConj);
        Conjunto[j] = (Tdesc *) malloc(sizeof(Tdesc));
        criacao(Conjunto[j]);
        diferenca(Conjunto[vValor], Conjunto[EscolheConj],Conjunto[j]);
        printf("A diferença %d-%d foi armazenada no conjunto %d",vValor,EscolheConj,j);
        printf("\n");
        j++;
			break;

			case 9:
        printf("Digite os dois conjuntos para fazer o produto entre eles!\n");
        scanf("%d", &EscolheConj);
        vValor = EscolheConj;
        scanf("%d", &EscolheConj);
        Conjunto[j] = (Tdesc *) malloc(sizeof(Tdesc));
        criacao(Conjunto[j]);
        printf("\nO produto %d-%d :",vValor,EscolheConj);
        produto(Conjunto[vValor], Conjunto[EscolheConj],Conjunto[j]);
        printf("\n");
        j++;
			break;

			case 10:
        printf("De qual elemento do Conjunto deseja excluir\n");
          scanf("%d", &Num);
          printf("Digite o conjunto:\n");
          scanf("%d", &EscolheConj);
          if(excluir(Conjunto[EscolheConj],Num)== 0)
            printf("ELEMENTO EXCLUIDO\n");
      break;

			case 11:
					printf("Digite o conjunto a ser destruido\n");
					scanf("%d",&EscolheConj);
					destroi(Conjunto[EscolheConj]);
					printf("Conjunto destruido com sucesso!\n");
			break;

      case 12:
        printf("Digite o numero do conjunto a ser impresso: ");
        scanf("%d", &Escolhe);
        imprimir(Conjunto[Escolhe]);

      break;

		}
		printf("\n\nEscolha a operacao a ser feita:\n");
    printf("1 - Criar Conjunto\n");
    printf("2 - Inserir elemento\n");
  	printf("3 - Pertinencia de elemento a conjunto\n");
  	printf("4 - Equivalencia de conjuntos\n");
  	printf("5 - Cardinalidade do conjunto\n");
  	printf("6 - União\n");
  	printf("7 - Interseccao\n");
  	printf("8 - Diferenca\n");
  	printf("9 - Produto Cartesiano\n");
  	printf("10 - Exclusao \n");
  	printf("11 - Destruir\n");
    printf("12 - Imprimir\n");
  	printf("13 - Sair\n");
		scanf("%d", &opcao);
	}



    return 0;

}
