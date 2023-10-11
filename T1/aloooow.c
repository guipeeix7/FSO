#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

float euclidiana (int x2, int x1, int y2, int y1){
   float x = x2 - x1;
   float y = y2 - y1;

   return (sqrt(pow(x,2))+(pow(y, 2)));
}

struct graph 
{
   int V; 
   int A; 
   int **adj; 
};
typedef struct graph *Graph;

static int **MATRIXint( int r, int c, int val) { 
   int **m = malloc( r * sizeof (int *));
   for (int i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

Graph GRAPHinit( int V) 
{ 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}

void GRAPHinsertArc( Graph G, int v, int w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->adj[w][v] = 1;//GRAFO não direcionado
      G->A++;
   }
}

void GRAPHremoveArc( Graph G, int v, int w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->adj[w][v] = 0;
      G->A--;
   }
}

void GRAPHdestroy(Graph G)
{
    free(G->adj);
}

void GraphShow(Graph G)
{
    for(int i=0; i<G->V; i++)
   {
      printf("%d:", i);
      for (int j=0; j<G->V; j++)
      {
        if(G->adj[i][j] != 0) printf(" %d", j);
      }
      printf("\n");
   }
   printf("\n");
}

void GRAPHcpt (Graph G, int origem, int destino, int n){
   int i, vert, novaDist, min;
   int *M, *L, *caminho;
   M =(int *)malloc(n*(sizeof(int)));
   L =(int *)malloc(n*(sizeof(int)));
  
   //iniciando variáveis
   for(i=0; i<n; i++){
      M[i] = 0; //determina se o vertece já foi visitado
      L[i] =INT_MAX; // determina o Comprimento mais curto
   }
   vert = origem;
   L[vert] = 0;
   while(vert != destino && vert != -1){ //ainda não terminou ou o caminho não existe

      for(i=0; i < n; i++){ //pecorre vertices adjacentes de vert
         if(G->adj[vert][i] != 0 && M[i]==0){ // se aresta existe e não foi visitada
            novaDist = L[vert] + G->adj[vert][i];
            if(novaDist < L[i]){
               L[i] =novaDist; //atualiza menor distância
            }
         }
      }
      M[vert] = 1; // toda a lista de adj do vert já foi analisada
      min = INT_MAX;
      vert = -1;
      for(i=0; i<n; i++){//encontra próximo vertice do caminho
         if(M[i]==0 && L[i]<min){ //escolhe o verice com menor peso 
            min = L[i]; //atualiza min
            vert = i; //atualiza vert
         }
      }   
   }
   // listar caminho mais curto entre origem e destino
   if(vert == -1)//encontrou caminho
   {
      printf("-1\n");
   }
   else{
      printf("%d\n", L[destino]);
   }
   free(M);
   free(L);
}
int main(){
   float d;
    int n;
    int ox, oy;
    int sx, sy;
    int *ix, *iy;
    float dist;

    Graph almofadas;

    scanf("%f", &d); //tamanho do passo
    scanf("%d", &n); //almofadas
    almofadas = GRAPHinit(n);

   ix =  malloc(sizeof(int)*n);
   iy =  malloc(sizeof(int)*n);

    scanf("%d %d", &ox, &oy); //coordenadas origem
    ix[0] = ox;
    iy[0] = oy;

    scanf("%d %d", &sx, &sy); //coordenadas sofá
    ix[n-1]=sx;
    iy[n-1]=sy;
    
    for(int i=1; i<n; i++){
       if(i<n-1){
         scanf("%d %d", &ix[i], &iy[i]);
       }
        for (int a = 0 ; a<=i; a++){ //Calcular distância euclidiana para cada ponto, se esse valor for menor que d pode criar a aresta, esse valor será o peso de cada aresta
           if(almofadas->adj[i][a] == 0 && a!=i){ 
               dist= euclidiana(ix[i], iy[i], ix[a], iy[a]);
               //printf("%f ", dist);
               if(dist 
               <= d){
                  GRAPHinsertArc(almofadas, i, a); //origem, destino 
               }
           }
        }
    }
   GRAPHcpt(almofadas, 0, n-1, n);
    //printf("\n");
    //GraphShow(almofadas);
    
    free(ix);
    free(iy);
    GRAPHdestroy(almofadas);
    return 0;
}