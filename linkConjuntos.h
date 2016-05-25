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

void criacao( Tdesc *,Tdesc *);

void destroi(Tdesc *);

void additem(Tdesc *, int);

int excluir(Tdesc *, char);

void imprimir(Tdesc *);

void uniao(Tdesc *,Tdesc *);

void interseccao(Tdesc *,Tdesc *);

void diferenca(Tdesc *,Tdesc *);

void produto(Tdesc *,Tdesc *);

int pertinencia(Tdesc *, int);

void equivalencia(Tdesc *, Tdesc *);

int cardinalidade(Tdesc *);
