/*  TDA - Conjuntos
        Felipe Luiz Soares 0030481511012
        Debora Hirai 0030481511010
        Jean Vitor 003048151019
*/

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

void criacao( Tdesc *);
void destroi(Tdesc *);
void additem(Tdesc *, int);
int excluir(Tdesc *, int);
void imprimir(Tdesc *);
void uniao(Tdesc *,Tdesc *);
void interseccao(Tdesc *,Tdesc *,Tdesc *);
void diferenca(Tdesc *,Tdesc *,Tdesc *);
void produto(Tdesc *,Tdesc *,Tdesc *);
int pertinencia(Tdesc *, int);
void equivalencia(Tdesc *, Tdesc *);
int cardinalidade(Tdesc *);
