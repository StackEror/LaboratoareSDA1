#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define N 100
#define min(a, b) ((a) < (b) ? (a) : (b))

int retea[N][N], flux[N][N];

// Funcția pentru a verifica dacă există un drum de la nodul sursă la nodul destinație
bool BFS(int sursa, int destinatie, int parinte[], int nr_noduri)
{
    bool vizitat[nr_noduri + 1];
    int coada[nr_noduri], front = -1, rear = -1, i, u, v;
    
    // Inițializăm toate nodurile ca nevizitate
    for (i = 1; i <= nr_noduri; i++)
    {
        vizitat[i] = false;
    }
    
    coada[++rear] = sursa;
    vizitat[sursa] = true;
    parinte[sursa] = -1;
    
    while (front < rear)
    {
        u = coada[++front];
        
        // Verificăm toate vecinii nodului u
        for (v = 1; v <= nr_noduri; v++)
        {
            if (!vizitat[v] && retea[u][v] - flux[u][v] > 0)
            { // se verifica daca muchia e disponibila
                coada[++rear] = v;
                parinte[v] = u;
                vizitat[v] = true;
            }
        }
    }
    
    // Dacă nodul destinație a fost vizitat, există un drum de la sursă la destinație 
    return vizitat[destinatie];
}

// Funcția pentru a introduce capacitățile arcelor în rețea


void read_input_file(int sursa,int destinatie,int nr_noduri)
{
    int a, b, c, i, j,n,e;
    FILE *input = fopen(/*"C:\\Users\\chicu\\OneDrive\\Desktop\\maxflow.txt"*/"data2.txt", "r");
    fscanf(input, "%d %d", &n, &e);
    printf("\nNumber of Vertices : %d   Edges : %d", n, e);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            flux[i][j] = 0;
        }
    }

    for (i = 1; i <= e; i++)
    {
        fscanf(input, "%d %d %d", &a, &b, &c);
        retea[a][b] = c;
        printf("\nA : %d  B : %d  Capacity : %d", a, b, c);
    }
    fclose(input);
}


int main()
{
    int sursa, destinatie, nr_noduri;
    
    printf("Introduceti numarul de noduri: ");
    scanf("%d", &nr_noduri);
    
    printf("Introduceti nodul sursa: ");
    scanf("%d", &sursa);
    
    printf("Introduceti nodul destinatie: ");
    scanf("%d", &destinatie);
    
    //introducere_retea(sursa, destinatie, nr_noduri);
    read_input_file(sursa, destinatie, nr_noduri);
    int flux_maxim = 0;
    int parinte[nr_noduri + 1];
    
    while (BFS(sursa, destinatie, parinte, nr_noduri))
    {
        int flux_curent = INT_MAX;
        int v;
        
        // Găsim fluxul minim pe drumul de la sursă la destinație 
        for (v = destinatie; v != sursa; v = parinte[v])
        {
            int u = parinte[v];
            flux_curent = min(flux_curent, retea[u][v] - flux[u][v]);
        }
        
        // Actualizăm fluxul și fluxul invers
        for (v = destinatie; v != sursa; v = parinte[v])
        {
            int u = parinte[v];
            flux[u][v] += flux_curent;
            flux[v][u] -= flux_curent;
        }
        
        // Adăugăm fluxul curent la fluxul maxim
        flux_maxim += flux_curent;
    }
    int total = 0;
    printf("\n");
    for(int d = 1; d <= nr_noduri; d++)
        for(int f = 1; f <= nr_noduri; f++){
            if(retea[d][f] && retea[d][f] != flux[d][f]){
                total+=flux[d][f];
            }
            if(retea[d][f])
            {
                printf("flux[%d][%d] = %d\n",d,f,flux[d][f]);
            }
        }
        //printf("Total = %d\n",total);
    printf("\nFluxul maxim este: %d\n", flux_maxim);
    
    return 0;
}


/*
void Citire_graf() 
{
    printf("Introduceti numarul de noduri: ");
    scanf("%d", &num_of_nodes);
    printf("Introduceti numarul de muchii: ");
    scanf("%d", &num_of_edges);
    
    for (int i = 1; i <= num_of_edges; i++)
    {
        printf("Introduceti muchia %d:  ", i);
        scanf("%d %d", &from_node, &to_node);
        if (from_node == to_node)
            { 
                printf("Nu exista bucle!\n"); 
                i--; 
                continue;
            } 

                printf("Introduceti capacitatea muchiei: ");
                scanf("%d",&capacity);
                
        if (from_node > num_of_nodes || to_node > num_of_nodes || from_node <= 0 || to_node <= 0)
        { 
            printf("Muchie invalida!\n"); 
            i--; 
        } 
        else
        {
            matrice_adiacenta[from_node][to_node] = 1;
            matrice_capacitate[from_node][to_node] = capacity;
        }
    }
}
*/



/*
void introducere_retea(int sursa, int destinatie, int nr_noduri)
{
    int i, j, capacitate;
    
    // Inițializăm rețeaua și fluxul cu zero
    for (i = 1; i <= nr_noduri; i++)
    {
        for (j = 1; j <= nr_noduri; j++)
        {
            retea[i][j] = 0;
            flux[i][j] = 0;
        }
    }
    
    printf("Introduceti capacitatile arcelor din retea (0 pentru a opri introducerea):\n");
    
    while (true)
    {
        printf("Arcul (0 0) opreste introducerea.\n");
        printf("Nodul sursa: ");
        scanf("%d", &i);
        printf("Nodul destinatie: ");
        scanf("%d", &j);
        
        // Dacă s-au introdus 0 0, încheiem introducerea
        if (i == 0 && j == 0)
        {
            break;
        }
        
        printf("Capacitatea arcului: ");
        scanf("%d", &capacitate);
        
        // Adăugăm capacitatea în rețea
        retea[i][j] += capacitate;
    }
}*/
//oranj
/*#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 1000
#define oo 1000000000
int n;                              // number of nodes
int e;                              // number of edges
int capacity[MAX_NODES][MAX_NODES]; // capacity matrix
int flow[MAX_NODES][MAX_NODES];     // flow matrix
int color[MAX_NODES];               // needed for breadth-first search
int pred[MAX_NODES];                // array to store augmenting path

int min(int x, int y)
{
    return x < y ? x : y; // returns minimum of x and y
}
int head, tail;
int q[MAX_NODES + 2];

void enqueue(int x)
{
    q[tail] = x;
    tail++;
    color[x] = GRAY;
}

int dequeue()
{
    int x = q[head];
    head++;
    color[x] = BLACK;
    return x;
}
int bfs(int start, int target)
{
    int u, v;
    for (u = 0; u < n; u++)
    {
        color[u] = WHITE;
    }
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;   
    while (head != tail)
    {
        u = dequeue();
        // Search all adjacent white nodes v. If the capacity
        // from u to v in the residual network is positive,
        // enqueue v.
        for (v = 0; v < n; v++)
        {
            if (color[v] == WHITE && capacity[u][v] - flow[u][v] > 0)
            {
                enqueue(v);
                pred[v] = u;
            }
        }
    }
    // If the color of the target node is black now,
    // it means that we reached it.
    return color[target] == BLACK;
}

int max_flow(int source, int sink)
{
    int i, j, u;
    // Initialize empty flow.
    int max_flow = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            flow[i][j] = 0;
        }
    }
    // While there exists an augmenting path,
    // increment the flow along this path.
    while (bfs(source, sink))
    {
        // Determine the amount by which we can increment the flow.
        int increment = oo;
        for (u = n - 1; pred[u] >= 0; u = pred[u])
        {
            increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]);
        }
        // Now increment the flow.
        printf("\n");
        for (u = n - 1; pred[u] >= 0; u = pred[u])
        {
            flow[pred[u]][u] += increment;
            flow[u][pred[u]] -= increment;
                printf("pred [%d] = %d\n",u,pred[u]);
            
        }
        max_flow += increment;
    }
    // No augmenting path anymore. We are done.
    return max_flow;
}

void read_input_file()
{
    int a, b, c, i, j;
    FILE *input = fopen("data.txt", "r");
    // FILE* output = fopen("data.txt", "w");
    //   fprintf(output,"%d %d", n,e);
    // read number of nodes and edges
    fscanf(input, "%d %d", &n, &e);
    printf("\nNumber of Vertices : %d   Edges : %d", n, e);
    // initialize empty capacity matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            capacity[i][j] = 0;
        }
    }
    // read edge capacities
    for (i = 0; i < e; i++)
    {
        fscanf(input, "%d %d %d", &a, &b, &c);
        capacity[a][b] = c;
        printf("\nA : %d  B : %d  Capacity : %d", a, b, c);
    }
    fclose(input);
}

int main()
{
    read_input_file();
    printf("\nPlease enter Source(s) and Sink(t) :\n");
    int s = 0, t = n - 1;
    scanf("%d %d", &s, &t);
    printf("\nMax Flow : %d\n", max_flow(s, t));

    printf("\n");
    for(int d = 0; d <  n; d++)
        for(int f = 0; f <  n; f++){
            if(capacity[d][f])
            {
                printf("flux[%d][%d] = %d\n",d,f,flow[d][f]);
            }
        }
    return 0;
}

*/
