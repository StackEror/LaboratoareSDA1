#include <stdio.h>
#include <stdlib.h>
#define MAX_NODURI 10

int num_noduri = 0;
int num_muchii = 0;
int de_la_nod, la_nod;
int matrice_incidenta[MAX_NODURI][MAX_NODURI];
int matrice_adiacenta[MAX_NODURI][MAX_NODURI];
int stack[100];
int count1 = 0;
int queue[100];
int count2 = 0;
int visited[100];

void Citire_graf();
void Afisarea_matriciei_incidenta();
void Afisarea_matriciei_adiacenta();
void Afisarea_optiunilor();
void Lista_de_adiacenta();
void Parcurgere_adancime(int nod_initial);
void Parcurgere_largime(int nod_initial);
void push(int x);
int  pop();
void add(int x);
int delete();

int main() {
    int nod;
    int optiune;
    while(1) {
        Afisarea_optiunilor();
        scanf("%d", &optiune);
        count1 == 0;
        for(int i = 1;i <= num_noduri; i++)
		visited[i]= 0;
        switch (optiune) {
            case 1:
                Citire_graf();
                break;
            case 2:
                Afisarea_matriciei_incidenta();
                break;
            case 3:
                Afisarea_matriciei_adiacenta();
                break;
            case 4:
                Lista_de_adiacenta();
                break;
            case 5:
                printf("Introdu n nodul de la care va incepe parcurgerea\n");
                scanf("%d",&nod);
                getchar();
                Parcurgere_adancime(nod);
                break;
            case 6:
                printf("Introdu n nodul de la care va incepe parcurgerea\n");
                scanf("%d",&nod);
                getchar();
                Parcurgere_largime(nod);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Optiune invalida! Introduceti din nou.\n");
        }
    }
    return 0;
}
void Citire_graf() {
    printf("Introduceti numarul de noduri: ");
    scanf("%d", &num_noduri);
    printf("Introduceti numarul de muchii: ");
    scanf("%d", &num_muchii);
    int max_edges = num_noduri * (num_noduri - 1);
    for (int i = 1; i <= max_edges; i++) {
        printf("Introduceti muchia %d , pentru a iesi tastati(0 0): ", i);
        scanf("%d %d", &de_la_nod, &la_nod);
        if ((de_la_nod == 0) && (la_nod == 0)) 
            break;
        if (de_la_nod > num_noduri || la_nod > num_noduri || de_la_nod <= 0 || la_nod <= 0) { 
            printf("Muchie invalida!\n"); 
            i--; 
        } 
        else{
            matrice_adiacenta[de_la_nod][la_nod] = 1;
            matrice_incidenta[i][de_la_nod] = -1;
            matrice_incidenta[i][la_nod] = 1;
            if (de_la_nod == la_nod) {
                matrice_incidenta[i][la_nod] = 2; 
            }
        }
    }
}

void Afisarea_matriciei_incidenta() {
    printf("Matricea de incidenta:\n");
    for (int i = 1; i <= num_muchii; i++) {
        for (int j = 1; j <= num_noduri; j++) {
            printf("%4d", matrice_incidenta[i][j]);
        }
        printf("\n");
    }
}

void Afisarea_matriciei_adiacenta() {
    printf("Matricea de adiacenta:\n");
    for (int i = 1; i <= num_noduri; i++) {
        for (int j = 1; j <= num_noduri; j++) {
            printf("%4d", matrice_adiacenta[i][j]);
        }
        printf("\n");
    }
}

void Lista_de_adiacenta(){
     printf("Lista de adiacenta:\n");
    for (int i = 1; i <= num_noduri; i++) {
        printf("\n");
        printf("%d| ",i);
        for (int j = 1; j <= num_noduri; j++) {
            if(matrice_adiacenta[i][j] ==  1){
                printf("%d - ",j);
            }
        }
        printf("0");
    }
}

void Parcurgere_adancime(int nod_initial)  // DFS
{
    int popped_node,i;
    push(nod_initial);         
    visited[nod_initial] = 1;   
    popped_node = pop();          
    if(popped_node != 0){
        printf(" %d ",popped_node);
    }
    while(popped_node != 0)
    {
        for(i = 1; i <= num_noduri; i++)
        {
            if((matrice_adiacenta[popped_node][i] != 0) && (visited[i] == 0))
            {
                push(i);
                visited[i] = 1;
            }
        }
        popped_node = pop();
            if(popped_node != 0){
                printf(" %d ",popped_node);
            }
    }
    for(i = 1; i <=num_noduri; i++)
    {
        if(visited[i] == 0) Parcurgere_adancime(i);
    }
}

void push(int x)
{
    if(count1 == 100){
        printf("No more space in the stack\n");
        return;
    }
    stack[count1] = x;
    count1++;
}

int pop()
{
    if(count1 == 0){
        return 0;
    }
    int res = stack[count1 - 1];
    count1--;
    return res;
}

void Parcurgere_largime(int nod_initial)    //  BFS
{
    int current_node,i;
    add(nod_initial);
    visited[nod_initial] = 1;
    current_node = delete();
    if(current_node != 0){
        printf(" %d ",current_node);
    }
    while(current_node != 0)
    {
        for(int i = 1; i <= num_noduri; i++)
        {
            if((matrice_adiacenta[current_node][i] != 0) && visited[i] == 0)
            {
                add(i);
                visited[i] = 1;
            }
        }
        current_node = delete();
        if(current_node != 0) printf(" %d ",current_node);
    }
    for(int i = 1; i <=num_noduri; i++)
    {
        if(visited[i] == 0) Parcurgere_largime(i);
    }
    
}

void add(int x)
{
    if(count2 == 100){
        fprintf(stderr,"No more space in queue\n");
        exit(0);
    }
    queue[count2] = x;
    count2++;
}

int delete()
{
    if(count2 == 0){
        return 0;
    }
    int res = queue[0];
    for(int i = 0; i < count2 - 1; i++){
    queue[i] = queue[i + 1];
    }
    count2--;
    return res;
}
void Afisarea_optiunilor() {
    
    printf("\nAlegeti o optiune:\n");
    printf("1. Citire graf de la tastatura\n");
    printf("2. Afisare matrice de incidenta\n");
    printf("3. Afisare matrice de adiacenta\n");
    printf("4. Afisare lista de adiacenta\n");
    printf("5. Parcurgere in adancime\n");
    printf("6. Parcurgere in largime\n");
    printf("0. Iesire\n");
}