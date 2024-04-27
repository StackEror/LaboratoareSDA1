#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#define INF 1000000
#define MAX_NODURI 20
#define min(a,b) a > b ? b : a
enum crossing_graph {not_visited = 0, finished = 1};

int from_node, to_node,capacity;
int matrice_adiacenta[MAX_NODURI][MAX_NODURI];
int matrice_capacitate[MAX_NODURI][MAX_NODURI];
int flux[MAX_NODURI][MAX_NODURI];
int vertex_color[MAX_NODURI];
int queue[100];
int visited[100];

int num_of_nodes = 0;
int num_of_edges = 0;
void Citire_graf();
void Afisarea_matriciei_adiacenta();
void Ford_fulkerson();
bool BFS(int source,int  destination,int ancestors[],int num_of_nodes);
void read_input_file();
int main()
{
    Ford_fulkerson();

    return 0;
}

void read_input_file()
{
    int i,j;
    FILE *graf = fopen("C:\\Users\\chicu\\OneDrive\\Desktop\\MDFulkerson\\maxflow2.txt", "r");
    /*
        "data2.txt"
        "C:\\Users\\chicu\\OneDrive\\Desktop\\MDFulkerson\\maxflow1.txt"
        "C:\\Users\\chicu\\OneDrive\\Desktop\\MDFulkerson\\maxflow2.txt"
        "C:\\Users\\chicu\\OneDrive\\Desktop\\MDFulkerson\\maxflow3.txt"
    */

    fscanf(graf, "%d %d", &num_of_nodes, &num_of_edges);
    printf("\nNumarul de noduri : %d   Muchii : %d\n",num_of_nodes, num_of_edges);

    for (i = 1; i <= num_of_nodes; i++)
    {
        for (j = 1; j <= num_of_nodes; j++)
        {
                flux[i][j] = 0;
                //matrice_capacitate[i][j] = 0;
        }
    }

    for (i = 1; i <= num_of_edges; i++)
    {
        fscanf(graf, "%d %d %d", &from_node, &to_node, &capacity);
        matrice_capacitate[from_node][to_node] = capacity;
        printf("Muchia(%d,%d)  Capacitatea : %d\n", from_node, to_node, capacity);
    }
    fclose(graf);
}

void Ford_fulkerson()
{
    int source, destination, num_of_nodes;
    
    read_input_file();
    printf("Introduceti numarul de noduri: ");
    scanf("%d", &num_of_nodes);

    printf("Introduceti nodul sursa: ");
    scanf("%d", &source);

    printf("Introduceti nodul destinatie: ");
    scanf("%d", &destination);
    

    int flux_maxim = 0;
    int ancestors[num_of_nodes + 1];

    while (BFS(source, destination, ancestors, num_of_nodes))
    {
        int flux_curent = INF;
        int nod;
        int pre_nod;

        for (nod = destination; nod != source; nod = ancestors[nod])
        {
            pre_nod = ancestors[nod];
            flux_curent = min(flux_curent,matrice_capacitate[pre_nod][nod] - flux[pre_nod][nod]);
        }

        for (nod = destination; nod != source; nod = ancestors[nod])
        {
            pre_nod = ancestors[nod];
            flux[pre_nod][nod] += flux_curent;
            flux[nod][pre_nod] -= flux_curent;
        }
        flux_maxim += flux_curent;
    }

    printf("Fluxul fiecarei muchii:\n");

    for(int i = 1; i <= destination; i++)
    {
        for(int j = 1; j <= num_of_nodes; j++){
            if(matrice_capacitate[i][j])
            {
                printf("flux[%d][%d] = %d\n",i,j,flux[i][j]);
            }
        }
    }

    printf("Fluxul maxim: %d",flux_maxim);
}


bool BFS(int source, int destination, int ancestors[], int num_of_nodes)
{
    int vizitat[num_of_nodes + 1];
    int queue[num_of_nodes], front = -1, rear = -1, i, pre_nod, nod;
    
    for (i = 1; i <= num_of_nodes; i++)
    {
        vizitat[i] = not_visited;
    }

    queue[++rear] = source;
    vizitat[source] = finished;
    ancestors[source] = -1;
    
    while (front < rear)
    {
        pre_nod = queue[++front];
        
        for (nod = 1; nod <= num_of_nodes; nod++)
        {
            if (!vizitat[nod] && matrice_capacitate[pre_nod][nod] - flux[pre_nod][nod] > 0)
            { 
                queue[++rear] = nod;
                ancestors[nod] = pre_nod;
                vizitat[nod] = finished;
            }
        }
    }
    
    return vizitat[destination];
}




// if(source == destination)
    // {
    //     printf("Fluxul maxim din '%d' in '%d' este: 0\n",source,destination);
    //     exit(0);
    // }