#ifndef MAIN_H
#define MAIN_H

typedef struct Lista
{
	int info;
	struct Lista* prox;

}TLista;

typedef struct TViz
{
	int id_viz;
	struct TViz *prox_viz;

} TViz;

typedef struct TNo
{
	int id_no;
	TViz *prim_viz;
	struct TNo *prox_no;

} TNo;

typedef struct grafo
{
	TNo *prim_no;
	int V; /* Qtd de vertices */

} TG;

typedef struct pilha
{
	int id;
	struct pilha *prox;
} TP;

#define TRUE 1
#define FALSE 0

TLista* criarLista();
void liberarLista(TLista* l);
TLista* insere_inicio(TLista* l, int info);
TLista *insere_fim(TLista* l, int info);
int busca_no(TLista* l, int info);
TLista* copia_lista(TLista* l);
void print_lista(TLista* l);
void swap(TLista* a, TLista* b);
void bubbleSort(TLista* list);
int findLastId(TViz *v);
void achaPontes(TG *g);
TG* create(int V);
TG *CloneGraph(TG* g);
void release(TG *g);
TNo *findVertex(TG *g, int id);
int insertVertex(TG *g, int id);
int removeVertex(TG *g, int id);
int insertEdge(TG *g, int id1, int id2, int orientado);
TViz *findEdge(TG *g, int id1, int id2);
TViz *_remove(TViz *vertex, int id, int *flag);
int removeEdge(TG *G, int id1, int id2, int isDirected);
void print(TG *g);
int directed(TG *G);
int no_em_comum(TLista *primeiro, TLista *segundo);
TLista *junta_resultado(TLista *primeiro, TLista *segundo);
TLista* sair_chegar(TG *g, int id1, int id2, TLista* caminho);
int fortemente_conexos(TG *g);
void mostra_conexos(TLista **resp, int tam);
TLista** conexo(TG *g);
void achaArticulacao(TG *g);
void information(TG* G);
int menu(TG *G);

#endif // MAIN_H