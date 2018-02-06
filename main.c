#include <stdio.h> /* I/O */
#include <stdlib.h> /* malloc */
#include <string.h> /* memset */
#include "main.h" /* structs */

/* Linked List */
TLista* criarLista()
{
	return NULL;
}
void liberarLista(TLista* l)
{
	if(l)
	{
		liberarLista(l->prox);

		free(l);
	}
}
TLista* insere_inicio(TLista* l, int info)
{
	TLista *novo = (TLista*)malloc(sizeof(TLista));
	novo->info = info;

	if(l)
		novo->prox = l;
	else
		novo->prox = NULL;

	return novo;
}
TLista *insere_fim(TLista* l, int info)
{
	if(!l)
	{
		return insere_inicio(l, info);
	}

	l->prox = insere_fim(l->prox, info);

	return l;
}
int busca_no(TLista* l, int info)
{
	if(!l)
		return 0;
	if(l->info == info)
		return 1;
	return busca_no(l->prox, info);
}
TLista* copia_lista(TLista* l)
{
	TLista *nova = criarLista();
	TLista* p = l;

	while(l)
	{
		nova = insere_fim(nova, l->info);
		l = l->prox;
	}

	return nova;
}
void print_lista(TLista* l)
{
	if(l)
	{
		printf("%d ", l->info);
		print_lista(l->prox);
	}
}
void swap(TLista* a, TLista* b)
{
	if(a && b)
	{
		int temp = a->info;
		a->info = b->info;
		b->info = temp;
	}
}
void bubbleSort(TLista* list)
{
	if(list && list->prox)
	{
		TLista* p = list;

		while(p)
		{
			TLista* q = list;
			TLista* r = list->prox;

			while(r)
			{
				if(q->info > r->info)
				{
					swap(q, r);
				}

				q = q->prox;
				r = r->prox;
			}

			p = p->prox;
		}
	}
}

/* Stack */
//void pilhaIni(TP* pilha)
//{
//	if(pilha)
//		pilha->prox = NULL;
//
//}
//void push(TP *pilha, int val)
//{
//	if(pilha)
//	{
//		TP *novaPilha = (TP*)malloc(sizeof(TP));
//
//		novaPilha->id = val;
//
//		novaPilha->prox = NULL;
//
//		if(pilha->prox == NULL)pilha->prox = novaPilha;
//
//		else{
//
//			TP *p = pilha->prox;
//
//			while(p->prox){
//
//				p = p->prox;
//
//			}
//
//			p->prox = novaPilha;
//
//		}
//	}
//}
//void insertStack(TP * pilha, int val)
//{
//	if(pilha)
//	{
//
//		TP *p = pilha->prox;
//
//		while(p){
//
//			if(p->id == val)return;
//
//			p = p->prox;
//
//		}
//
//		push(pilha, val);
//	}
//}
//void showStack(TP *pilha)
//{
//	if(pilha)
//	{
//		TP *p = pilha->prox;
//
//		printf("\nArticulacoes: (");
//
//		while(p){
//
//			printf("%d", p->id);
//
//			if(p->prox)printf(" ,");
//
//			p = p->prox;
//
//		}
//
//		printf(")");
//	}
//}
//void libera(TP* pilha)
//{
//	if(pilha)
//	{
//		TP *p = pilha->prox, *temp;
//
//		if(p)
//		{
//			while(p)
//			{
//				temp = p;
//				p = p->prox;
//				free(temp);
//			}
//
//			free(pilha);
//		}
//	}
//}
//int buscaVisitado(TP *pilha, int val)
//{
//	if(pilha)
//	{
//		TP *p = pilha;
//
//		for(int i = 1; i <= val; ++i)
//		{
//			p = p->prox;
//		}
//
//		if(p)
//			return p->id;
//	}
//
//	return -1;
//}
//void insereVisitado(TP *pilha, int val)
//{
//	if(pilha)
//	{
//		TP *p = pilha;
//
//		for(int i = 0; i < val; ++i)
//		{
//			p = p->prox;
//		}
//
//		if(p)
//			p->id = 1;
//	}
//}
//void caminho(TG *g, int id1, TP *pilha)
//{
//	if(g)
//	{
//		insereVisitado(pilha, id1);
//
//		TNo *p = findVertex(g, id1);
//
//		if(p)
//		{
//
//			TViz *v = p->prim_viz;
//
//			while(v)
//			{
//
//				if(buscaVisitado(pilha, v->id_viz) == 0)
//
//					caminho(g, v->id_viz, pilha);
//
//				v = v->prox_viz;
//
//			}
//		}
//	}
//}
//int encontraCaminho(TG *g, int id1, int id2)
//{
//	if(g)
//	{
//		TNo *p = g->prim_no;
//
//		int result = 0;
//
//		TP *pilha = (TP*)malloc(sizeof(TP));
//
//		pilhaIni(pilha);
//
//		while(p)
//		{
//
//			push(pilha, 0);
//
//			p = p->prox_no;
//
//		}
//
//		caminho(g, id1, pilha);
//
//		result = buscaVisitado(pilha, id2);
//
//		libera(pilha);
//
//		return result;
//	}
//
//	return NULL;
//
//}
//int findLastId(TViz *v)
//{
//	while(v)
//	{
//		if(!v->prox_viz)
//			return v->id_viz;
//
//		v = v->prox_viz;
//	}
//
//	return 0;
//}
//void achaPontes(TG *g)
//{                     //METODO SIMPLES
//	if(g)
//	{
//		TNo *p = g->prim_no;
//
//		int id1 = 0;
//		int id2 = 0;
//		int ultimo = 0;
//
//		printf("- PONTES:\n");
//
//		while(p)
//		{
//
//			id1 = p->id_no;
//
//			TViz *v = p->prim_viz;
//
//			ultimo = findLastId(v);
//
//			while(v)
//			{
//
//				TViz *proximo = v->prox_viz;
//
//				id2 = v->id_viz;
//
//				removeEdge(g, id1, id2, 0);
//
//				if(!encontraCaminho(g, id1, id2))
//				{
//
//					if(id1 < id2)
//
//						printf("\t(%d, %d)\n", id1, id2);
//
//				}
//
//				insertEdge(g, id1, id2, 0);
//
//				v = proximo;
//
//				if(ultimo == id2)
//					break;
//
//			}
//
//			p = p->prox_no;
//		}
//	}
//
//}

int findLastId(TViz *v)
{
	while(v)
	{

		if(!v->prox_viz)return v->id_viz;

		v = v->prox_viz;

	}

	return 0;

}
void achaPontes(TG *g)
{
	if(g)
	{
		TLista *l = criarLista();
		printf("- PONTES:\n");
		TNo *p = g->prim_no;
		while(p){
			//printf("entrou no while de no %d\n",p->id_no);
			TViz *v = p->prim_viz;
			while((v) && busca_no(l, v->id_viz)){
				//printf("achou no %d na lista\n",v->id_viz);
				v = v->prox_viz;
			}
			while(v){
				//printf("entrou no while de do vizinho %d\n",v->id_viz );
				TG *teste = CloneGraph(g);
				removeEdge(teste, p->id_no, v->id_viz, 0);
				if(conexo(teste))
				{	//mostra_conexos(conexo(teste),teste->V+1);
					printf("\t(%d, %d)\n", p->id_no, v->id_viz);
				}
				release(teste);
				v = v->prox_viz;
			}
			l = insere_inicio(l, p->id_no);
			p = p->prox_no;
		}
		if(l) liberarLista(l);
	}

}
/* Graph */

/* Cria um grafo */
TG* create(int V)
{
	TG * g = (TG*)malloc(sizeof(TG));
	g->prim_no = NULL;
	g->V = V;

	return g;
}
TG *CloneGraph(TG* g)
{
	if(g)
	{
		TG *novo = create(0);
		TNo *p = g->prim_no;
		while(p){
			insertVertex(novo, p->id_no);
			TViz *v = p->prim_viz;
			while(v){
				insertEdge(novo, p->id_no, v->id_viz, 0);
				v = v->prox_viz;
			}
			p = p->prox_no;
		}
		return novo;
	}

	return NULL;
}
/* Libera um grafo */
void release(TG *g)
{
	if(g)
	{
		TNo *p = g->prim_no;

		/* Libera os vértices */
		while(p)
		{
			TViz *v = p->prim_viz;

			while(v)
			{
				TViz *t = v;
				v = v->prox_viz;
				free(t);
			}

			TNo *q = p;

			p = p->prox_no;

			free(q);
		}

		/* Libera o grafo */
		free(g);
	}
}
/* Encontra um vertice no grafo

Return:
Retorna um ponteiro válido para o vertice caso exista
Caso não exista, retorna NULL
*/
TNo *findVertex(TG *g, int id)
{
	if(g)
	{
		TNo *p = g->prim_no;

		while(p)
		{
			if(p->id_no == id)
				break;

			p = p->prox_no;
		}

		return p;
	}

	return NULL;
}
/* Insere um vertice no grafo

Return:
TRUE caso seja inserido com sucesso
FALSE caso já exista esse vertice no grafo
*/
int insertVertex(TG *g, int id)
{
	/* Verifica se o vértice já existe no grafo. Se existir, não inserir novamente */
	if(findVertex(g, id))
		return FALSE;

	TNo *vertice = (TNo*)malloc(sizeof(TNo));

	vertice->id_no = id;
	vertice->prim_viz = NULL;
	vertice->prox_no = NULL;

	TNo *p = g->prim_no;

	if(p)
	{
		while(p->prox_no)
			p = p->prox_no;

		p->prox_no = vertice;
	}
	else
		g->prim_no = vertice;

	g->V++;

	return TRUE;
}
/* Remove um vertice no grafo

Return:
TRUE caso tenha removido com sucesso
FALSE caso o vertice nao exista no grafo
*/
int removeVertex(TG *g, int id)
{
	if(g)
	{
		TNo *p = g->prim_no;

		TViz *anterior = NULL;

		TNo *anterior_no = NULL;

		while(p && p->id_no != id)
		{
			anterior_no = p;
			p = p->prox_no;
		}

		/* Se p é NULL, não existe o que ser retirado */
		if(p)
		{
			/* Vamos excluir os caminhos de p para outro nos */
			TViz *v = p->prim_viz;

			while(v)
			{
				TViz *aux = v;
				v = v->prox_viz;
				free(aux);
			}

			TNo *q = g->prim_no;

			while(q) // agora vamos excluir caminhos de outros nos ate p
			{
				if(p != q)
				{                 //se q nao for o proprio vertice a ser retirado
					TViz *v = q->prim_viz; //, buscamos se ele tem aresta para chegar em p

					while(v)
					{
						if(v->id_viz == id)
						{
							TViz *aux = v;
							v = v->prox_viz;

							if(anterior)
							{
								anterior->prox_viz = v;
							}
							else
							{
								q->prim_viz = v;
							}

							free(aux);     //so existe um caminho de q para p,

							break;		//logo podemos parar de procurar
						}
						else
						{
							anterior = v; v = v->prox_viz;
						}
					}
				}

				anterior = NULL;

				q = q->prox_no;			//e agora olhamos se outro nó tem aresta para p
			}

			//agora vamos enfim retirar o no
			if(!anterior_no)
			{		//se p é o primeiro no do grafo
				g->prim_no = p->prox_no;	//o primeiro no do grafo passa a ser o proximo de p

				free(p);
				g->V--;
				return TRUE;
			}

			anterior_no->prox_no = p->prox_no; //o no anterior a p aponta para o proximo no após p

			free(p);

			g->V--;

			return TRUE;
		}
	}

	return FALSE;
}
/* Insere um arco no grafo
Return:
TRUE caso insira com sucesso o arco no grafo
FALSE caso os vertices id1 ou id2 não existam no grafo
*/
int insertEdge(TG *g, int id1, int id2, int orientado)
{
	if(g)
	{
		TNo* origin = findVertex(g, id1);
		TNo* destiny = findVertex(g, id2);

		// Origem e/ou Destino não existe(m)
		if(!origin || !destiny)
			return FALSE;

		// Já existe aresta de id1 para id2
		if(findEdge(g, id1, id2))
			return FALSE;

		TViz *novo = (TViz*)malloc(sizeof(TViz));
		novo->id_viz = id2;
		novo->prox_viz = NULL;

		TViz *v = origin->prim_viz;

		// Se não tem primeiro vizinho, o novo é o primeiro agora 
		if(!v)
		{
			origin->prim_viz = novo;

			if(!orientado)
			{
				insertEdge(g, id2, id1, 1); //se o grafo for nao for orientado  acrescenta a volta
			}

			return TRUE;
		}

		while(v->prox_viz)
		{
			v = v->prox_viz;  //acha o ultimo vizinho
		}

		v->prox_viz = novo;   //acrescenta o novo caminho no final da lista de vizinhos

		if(!orientado)
			insertEdge(g, id2, id1, 1); //se não for orientado, faz o caminho id2->id1

		return TRUE;
	}
	return FALSE;
}
/* Busca um arco no grafo

Return:
Um ponteiro válido para o arco caso seja encontrado
NULL caso o arco não exista
*/
TViz *findEdge(TG *g, int id1, int id2)
{
	if(g)
	{
		TNo *p = findVertex(g, id1);

		TViz *v = p->prim_viz;

		while(v)
		{
			if(v->id_viz == id2)
				break;

			v = v->prox_viz;
		}

		return v;
	}

	return NULL;
}
/* Remover arco - Função auxiliar

variável 'flag' recebe o valor TRUE caso algum arco tenha sido removido

Return:
Nova lista de adjacencias sem o arco a ser removido

*/
TViz *_remove(TViz *vertex, int id, int *flag)
{
	if(!vertex)
		return vertex;

	if(vertex->id_viz == id)
	{
		TViz* next = vertex->prox_viz;
		free(vertex);

		*flag = TRUE;

		return next;
	}
	else
	{
		vertex->prox_viz = _remove(vertex->prox_viz, id, flag);

		return vertex;
	}
}
/* Remover arco

Return:
TRUE caso tenha removido o arco com sucesso
FALSE caso o arco a ser removido não exista

*/
int removeEdge(TG *G, int id1, int id2, int isDirected)
{
	if(G)
	{
		TNo *vertex = findVertex(G, id1);

		if(vertex)
		{
			int flag = FALSE;

			vertex->prim_viz = _remove(vertex->prim_viz, id2, &flag);

			if(flag)
			{
				/* Caso o grafo seja orientado, remover a volta também */
				if(!isDirected)
				{
					return removeEdge(G, id2, id1, 1);
				}

				return TRUE;
			}
		}
	}

	return FALSE;
}
/* Exibe o grafo na tela */
void print(TG *g)
{
	if(g)
	{
		TNo *p = g->prim_no;

		while(p)
		{
			printf("%d -> ", p->id_no);

			TViz *v = p->prim_viz;

			while(v)
			{
				printf("%d -> ", v->id_viz);
				v = v->prox_viz;
			}

			printf("NULL\n");
			p = p->prox_no;
		}
	}
}
/*  Verifica se o grafo é orientado ou não.

Return:
TRUE caso o grafo seja orientado
FALSE caso não seja
*/
int directed(TG *G)
{
	if(G)
	{
		TNo *p = G->prim_no;

		while(p)
		{
			TViz *v = p->prim_viz;

			while(v)
			{
				if(!findEdge(G, v->id_viz, p->id_no))
					return TRUE;

				v = v->prox_viz;
			}

			p = p->prox_no;
		}
	}

	return FALSE;
}
int no_em_comum(TLista *primeiro, TLista *segundo)
{
	int contador = 0;

	if(primeiro && segundo)
	{
		while(primeiro)
		{
			if(busca_no(segundo, primeiro->info))
				contador++;

			primeiro = primeiro->prox;
		}
	}

	return contador;
}
TLista *junta_resultado(TLista *primeiro, TLista *segundo)
{
	while(segundo)
	{
		if(!busca_no(primeiro, segundo->info))
		{
			primeiro = insere_fim(primeiro, segundo->info);
		}

		segundo = segundo->prox;
	}

	return primeiro;

}
TLista* sair_chegar(TG *g, int id1, int id2, TLista* caminho)
{
	if(g)
	{

		//printf("COMEÇO de %d para %d\n",id1,id2 );
		TNo *p = findVertex(g, id1);

		int edgeRemoved = 0;
		if(findEdge(g, id1, id1)){
			removeEdge(g, id1, id1, 0);
			edgeRemoved = 1;
		}
		TViz *v = p->prim_viz;
		while(v)
		{	//print_lista(caminho);
			//printf("do while\n");

			//printf("testando caminho de %d e indo para %d\n",id1,v->id_viz);
			if(v->id_viz == id2)
			{	//printf("Achou caminho:");
				if(!busca_no(caminho, id1)) caminho = insere_fim(caminho, id1); //a função evita repetições do mesmo nó 
				if(!busca_no(caminho, id2)) caminho = insere_fim(caminho, id2); //na explicitação do caminho
																				//print_lista(caminho);
																				//printf("\n");
			}
			else
			{
				//printf("Não é esse o caminho\n" );
				//print_lista(caminho);
				//printf("\n");
				//printf("bucando %d em caminho : %d\n",v->id_viz,busca_no(caminho,v->id_viz) );
				if(!busca_no(caminho, v->id_viz))
				{	  //se certificando de não entrar em um loop infinito
					int teste = busca_no(caminho, id1);  //se certificando do caminho não ter duas vezes o mesmo nó
														 //printf("id1=%d\n",id1 );
					TLista *novo_caminho = criarLista();
					//printf("teste é: %d\n",teste);


					novo_caminho = copia_lista(caminho);


					novo_caminho = insere_fim(novo_caminho, id1);

					TLista *temp = sair_chegar(g, v->id_viz, id2, novo_caminho); //pega o resultado, se for 0 não existe caminho ate id2 
																				 //printf("temp de %d:",id1);
																				 //print_lista(temp);
																				 //printf("\n");

					if(temp)
					{
						caminho = junta_resultado(caminho, temp);				//partindo deste v

					}
					liberarLista(novo_caminho);
				}
			}

			v = v->prox_viz;


			//printf("tenta outro no\n");
		}
		if(edgeRemoved) insertEdge(g, id1, id1, 0);
		if(!caminho && id1 == id2){
			//printf("(!caminho && id1 == id2)\n");
			return insere_inicio(NULL, id1);
		}

		if(!busca_no(caminho, id1))
		{
			return NULL; // se não possui vertice ou nenhum dos vertices o leva ao destino, retorna 0
		}
		return caminho;
	}

	return NULL;
}
int fortemente_conexos(TG *g)
{
	if(g)
	{
		TLista **resp = (TLista**)malloc(sizeof(TLista*)*(g->V + 1));
		//printf("foi\n");
		/* Função para incializar todo o vetor para zero */
		for(int x = 0; x <= g->V; x++){
			resp[x] = criarLista();
		}

		int i = 0;

		TNo *no = g->prim_no;
		while(no){
			//printf("entrou no no\n");
			TLista* no_chegou_em_si_mesmo = sair_chegar(g, no->id_no, no->id_no, NULL);  //se certifica que existe uma resposta
																						 //print_lista(no_chegou_em_si_mesmo);
																						 //printf("\n");
			if(no_chegou_em_si_mesmo && no_chegou_em_si_mesmo->prox && !findEdge(g, no->id_no, no->id_no)){
				int j = 0;
				while(j <= i){
					//print_lista(no_chegou_em_si_mesmo);
					//printf("contem\n");
					//print_lista(resp[j]);
					//printf("?\n");
					if(no_em_comum(no_chegou_em_si_mesmo, resp[j])){
						//printf("sim\n");
						break;
					}
					//printf("nao\n");
					j++;
				}

				resp[j] = junta_resultado(resp[j], no_chegou_em_si_mesmo);
				if(j > i){
					i++;
				}
			}
			no = no->prox_no;

		}

		for(int k = 0; k < g->V + 1; k++)
		{	//print_lista(resp[k]);
			//printf("\n");
			for(int j = k + 1; j < g->V + 1; j++)
			{
				if(no_em_comum(resp[k], resp[j]))
				{
					i--;

					//printf("no em comum no final com\n");
					//print_lista(resp[j]);
					//printf("\n");
					resp[k] = junta_resultado(resp[k], resp[j]);
					liberarLista(resp[j]);
					resp[j] = NULL;
				}
			}
		}

		printf("- Componentes fortemente conexos:\n");


		if(!i)
			printf("Nenhum\n");
		int j = 1;
		while(j <= i){
			printf("\t");
			print_lista(resp[j]);
			printf("\n");
			liberarLista(resp[j]);
			j++;
		}
		liberarLista(resp[0]);
		free(resp);
	}

	return 0; //restorna 0 pois nenhuma outra função precisa ser chamada
}
void mostra_conexos(TLista **resp, int tam)
{
	if(!resp)
		printf("\tNenhum\n");
	int i = 1;
	while(i<tam){
		printf("\t");
		print_lista(resp[i]);
		printf("\n");
		i++;
	}
	free(resp);
}
TLista** conexo(TG *g)
{
	if(g)
	{
		//printf("entrou no conexo\n");
		TLista **resp = (TLista**)malloc(sizeof(TLista*)*(g->V + 1));
		//printf("criou TLista de tamanho %d\n",g->V);

		/* Função para incializar todo o vetor para zero */
		for(int x = 0; x <= g->V; x++){
			resp[x] = criarLista();
		}
		//printf("inicializou\n");
		int i = 0;

		TNo *no = g->prim_no;
		while(no){
			//printf("entrou no loop que busca de no em no\n");
			TLista* no_chegou_em_si_mesmo = sair_chegar(g, no->id_no, no->id_no, NULL);  //se certifica que existe uma resposta
																						 //print_lista(no_chegou_em_si_mesmo);
																						 //printf("\n");
			if(no_chegou_em_si_mesmo){
				int j = 0;
				while(j <= i){
					if(no_em_comum(no_chegou_em_si_mesmo, resp[j])){
						//printf("no em comum\n");
						break;
					}
					j++;
				}
				//printf("j=%d\n",j );
				resp[j] = junta_resultado(resp[j], sair_chegar(g, no->id_no, no->id_no, NULL));
				if(j > i){
					i++;
				}
			}
			no = no->prox_no;

		}
		for(int k = 0; k < g->V + 1; k++)
		{	//print_lista(resp[k]);
			//printf("\n");
			for(int j = k + 1; j < g->V + 1; j++)
			{
				if(no_em_comum(resp[k], resp[j]))
				{
					i--;

					//printf("no em comum no final com\n");
					//print_lista(resp[j]);
					//printf("\n");
					resp[k] = junta_resultado(resp[k], resp[j]);
					liberarLista(resp[j]);
					resp[j] = NULL;
				}
			}
		}

		if(i == 1)
		{
			free(resp);
			return NULL;
		}
		return resp;
	}

	return NULL;
}
void achaArticulacao(TG *g)
{
	if(g)
	{
		printf("\n- PONTOS DE ARTICULACAO:\n");
		TNo *p = g->prim_no;

		while(p)
		{
			//printf("no while\n");
			TG *teste = CloneGraph(g);
			//printf("fez teste\n");
			removeVertex(teste, p->id_no);
			//printf("removeu vertice\n");

			if(conexo(teste))
			{
				printf("\t( %d )\n", p->id_no);
			}
			else
			{
			}

			release(teste);
			p = p->prox_no;
		}
	}

}
void information(TG* G)
{
	if(G)
	{
		printf("GRAFO:\n");

		/* Se esse grafo é orientado ou não.
		Se for orientado, informe sua(s) componente(s) fortemente conexa(s).
		Um grafo orientado é fortemente conexo se para qualquer par (v,w) de seus vértices existe um caminho de v a w e também um caminho de w para v.
		*/
		if(directed(G))
		{
			printf("- Orientado\n");
			fortemente_conexos(G);
		}
		/* Se esse grafo não for orientado, verifique se ele é conexo.*/
		else
		{
			printf("- Nao Orientado\n");

			/*	Se for conectado, indique as pontes (ponte ?uma aresta cuja a remo?o desconecta o grafo) e os pontos de articula?o
			(um ponto de articula?o ?um v?tice de um grafo tal que a remo?o desse v?tice provoca um aumento no n?mero de componentes conectados) existentes no grafo.
			*/
			TLista** resp = conexo(G);
			if(!resp)
			{
				printf("- Grafo Conexo\n");
				achaArticulacao(G);
				achaPontes(G);

			}
			else
			{
				/*
				Se não for conectado, informe os componentes conexos desse grafo.
				*/
				printf("- Grafo Nao Conexo\n");
				printf("- COMPONENTES CONECTADOS:\n");
				mostra_conexos(resp, G->V + 1);
			}
		}
	}
}

/* Interface */
int menu(TG *G)
{
	int running = TRUE;

	while(running)
	{
		system("clear");
		printf("OPERACOES COM GRAFO:\n");
		printf("1. Exibir Grafo\n");
		printf("2. Exibir Informacoes do Grafo\n");
		printf("3. Inserir Vertice\n");
		printf("4. Inserir Arco\n");
		printf("5. Retirar Vertice\n");
		printf("6. Retirar Arco\n");
		printf("7. Buscar Vertice\n");
		printf("8. Buscar Arco\n");
		printf("9. Sair\n");
		printf("> ");

		int option = 0;
		scanf("%d", &option);

		switch(option)
		{
		case 1: 		print(G); 						break;
		case 2:			information(G);					break;

		case 3:
		{
			printf("\nId do vertice: ");

			int id = 0;

			scanf("%d", &id);
			if(insertVertex(G, id))
				printf("Vertice inserido com sucesso.\n");
			else
				printf("Falha ao inserir vertice.\n");
		}
		break;

		case 4:
		{
			int isDirected = 0;

			printf("Tipo de arco: \n");
			printf("0. Nao Orientado\n");
			printf("1. Orientado\n");
			printf("> ");
			scanf("%d", &isDirected);

			int origin = 0;
			int destiny = 0;

			printf("Origem: ");
			scanf("%d", &origin);

			printf("Destino: ");
			scanf("%d", &destiny);

			if(insertEdge(G, origin, destiny, isDirected))
				printf("Arco inserido com sucesso.\n");
			else
				printf("Falha ao inserir arco.\n");
		}
		break;

		case 5:
		{
			printf("\nId do vertice: ");

			int id = 0;

			scanf("%d", &id);
			if(removeVertex(G, id))
				printf("Vertice removido com sucesso.\n");
			else
				printf("Falha ao remover vertice.\n");
		}
		break;

		case 6:
		{
			int isDirected = 0;

			printf("Tipo de arco: \n");
			printf("0. Nao Orientado\n");
			printf("1. Orientado\n");
			printf("> ");
			scanf("%d", &isDirected);

			int id1 = 0;
			int id2 = 0;
			printf("Origem: ");
			scanf("%d", &id1);
			printf("Destino: ");
			scanf("%d", &id2);

			if(removeEdge(G, id1, id2, isDirected))
				printf("Arco removido com sucesso.\n");
			else
				printf("Falha ao remover arco.\n");
		}
		break;

		case 7:
		{
			int id = 0;
			printf("Digite o id do vertice: ");
			scanf("%d", &id);
			TNo* vertex = findVertex(G, id);

			if(vertex)
			{
				printf("\nVertice: %d\nMemoria: %p\n", vertex->id_no, vertex);
			}
			else
			{
				printf("\nVertice nao encontrado!\n");
			}
		}

		break;

		case 8:
		{
			int origin = 0;
			int destiny = 0;

			printf("Origem: ");
			scanf("%d", &origin);

			printf("Destino: ");
			scanf("%d", &destiny);

			TViz *edge = findEdge(G, origin, destiny);

			if(edge)
			{
				printf("Arco existente para %d -> %d.\nMemoria: %p.\n", origin, destiny, edge);
			}
			else
			{
				printf("Nao existe arco do vertice %d ao vertice %d.\n", origin, destiny);
			}
		}
		break;

		case 9:
		{
			printf("BYE BYE!!!\n");
			return TRUE;
		}
		default:
			printf("Parametro invalido\n");
		}

		/* Esperar o usuario pressionar alguma tecla para prosseguir para a próxima operação */
		while(getchar() != '\n');
		getchar();
	}
}


/*
G = (V, E)
Graph = (Vertex, Edges)

*Um grafo pode ter zero arestas, mas nunca zero vertices

*/
int main(int argc, char* argv[])
{
	/* Verifica se a quantidade de parâmetros é diferente de 2
	Para funcionar precisa ser 2:
	argv[0] = Nome do programa
	argv[1] = Primeiro parâmetro passado ( Nome do arquivo a ser aberto )
	*/
	if(argc != 2)
	{
		printf("Entrada invalida\n");
		return 1;
	}

	/* Abre o arquivo no modo leitura (r = read) */
	FILE * fp = fopen(argv[1], "r");
	//FILE * fp = fopen("graph.txt", "r");

	/* Se fp for igual a zero, significa que não foi possível abrir o arquivo */
	if(!fp)
	{
		printf("Falha ao abrir o arquivo %s\n", argv[1]);
		return 1;
	}

	/* Lê quantos vértices há no grafo */
	int V = 0;
	fscanf(fp, "%d", &V);

	/* Caso não tenha vertices, terminar o programa */
	if(V <= 0)
	{
		printf("Um grafo precisa ter ao menos um vertice.\n");
		fclose(fp);
		return 1;
	}

	/* Cria um grafo vazio */
	TG *G = create(V);

	/* Insere os vertices no grafo */
	int i = 0;
	for(i = 0; i < V; i++)
		insertVertex(G, i + 1);

	/* Insere os arcos no grafo */
	int origin = 0;
	int destiny = 0;

	fscanf(fp, "%d %d", &origin, &destiny);

	while(!feof(fp))
	{
		insertEdge(G, origin, destiny, 1);
		fscanf(fp, "%d %d", &origin, &destiny);
	}

	/* Exibe o menu e só retorna quando for para encerrar o programa */
	menu(G);


	/* Libera os vertices e o grafo */
	release(G);

	/* Fecha o arquivo */
	fclose(fp);

	return 0;
}
