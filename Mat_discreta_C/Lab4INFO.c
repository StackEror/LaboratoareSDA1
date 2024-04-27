#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODURI 20
#define MAXIM 999
#define MINIM -999
struct graf{
    int from;
    int to;
    
}arce[30];
int num_noduri = 0;
int num_muchii = 0;
int de_la_nod, la_nod,pondere,nod;
int matrice_ponderata_min[MAX_NODURI][MAX_NODURI];
int matrice_ponderata_max[MAX_NODURI][MAX_NODURI];
int cost_min_curr[MAX_NODURI];
int cost_max_curr[MAX_NODURI];
int bellman_matr_min[MAX_NODURI][MAX_NODURI];
int bellman_matr_max[MAX_NODURI][MAX_NODURI];
int stocare_min[MAX_NODURI];
int stocare_max[MAX_NODURI];
int afisare[MAX_NODURI];
int matrice_adiacenta[MAX_NODURI][MAX_NODURI];
void Eliberere();
int Gasire_element_min();
int Gasire_element_max();
void Citire_graf();
void Afisarea_matriciei_adiacenta();
void Afisarea_optiunilor();
void Afisare_matrice_ponderata();
void Gasire_drum_minim_cu_Ford(int nod);
void Afisare_drum_minim_Ford();
void Gasire_drum_maxim_cu_Ford(int nod);
void Afisare_drum_maxim_Ford();
void Corectare_pondere(int din, int in);
void Gasire_drum_minim_cu_Bellman_Kalaba(int momeala);
void Gasire_drum_maxim_cu_Bellman_Kalaba(int momeala);
int main() {
    int optiune;
    while(1) {
        Eliberere();
        Afisarea_optiunilor();
        scanf("%d", &optiune);
        switch (optiune) {
            case 1:
                Citire_graf();
                break;
            case 2:
                Afisare_matrice_ponderata();       
                break;
            case 3:
                printf("Introdu nodul final de gasire a drumului: \n");
                scanf("%d",&nod);
                Gasire_drum_minim_cu_Ford(nod);
                break;
            case 4:
                Afisare_drum_minim_Ford();
                break;
            case 5:
                printf("Introdu nodul final pentru drum maxim\n");
                scanf("%d",&nod);
                Gasire_drum_maxim_cu_Ford(nod);
                break;
            case 6:
                Afisare_drum_maxim_Ford();
                break;
            case 7:
                printf("Introdu nodul initial de gasire a drumului: \n");
                scanf("%d",&nod);
                Gasire_drum_minim_cu_Bellman_Kalaba(nod);
                break;
            case 8:
                printf("Introdu nodul initial de gasire a drumului: \n");
                scanf("%d",&nod);
                Gasire_drum_maxim_cu_Bellman_Kalaba(nod);
                break;
            case 9:
              printf("Introduceti muchia de schimbare a ponderii: ");
                scanf("%d %d", &de_la_nod, &la_nod);
                Corectare_pondere(de_la_nod,la_nod);
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
    
    for (int i = 1; i <= num_muchii; i++)
    {
        printf("Introduceti muchia %d:  ", i);
        scanf("%d %d", &de_la_nod, &la_nod);
        if (de_la_nod == la_nod)
            { 
                printf("Nu exista bucle!\n"); 
                i--; 
                continue;
            } 

                printf("Introduceti ponderea muchiei: ");
                scanf("%d",&pondere);
                
        if (de_la_nod > num_noduri || la_nod > num_noduri || de_la_nod <= 0 || la_nod <= 0)
        { 
            printf("Muchie invalida!\n"); 
            i--; 
        } 
        else
        {
            matrice_adiacenta[de_la_nod][la_nod] = 1;
            matrice_ponderata_min[de_la_nod][la_nod] = pondere;
            matrice_ponderata_max[de_la_nod][la_nod] = pondere;
        }
    }
    
    int t = 0;//pentru a tine urma numarului de muchii din vectorul b
   
    for (int i = 1; i <=num_noduri; i++)
    {
        for (int j = 1; j <=num_noduri; j++)
        {
            if(matrice_adiacenta[i][j] != 0)
            {
                arce[t].from = i;
                arce[t].to = j;
                t++;
            }
        }
    }

    for (int i = 1; i <= num_noduri; i++)
    {
        for (int j = 1; j <= num_noduri; j++)
        {
            if(matrice_ponderata_max[i][j] == 0)
            {
                matrice_ponderata_min[i][j] = MAXIM;
                matrice_ponderata_max[i][j] = MINIM;
            }
        }
        matrice_ponderata_min[i][i] = 0;
        matrice_ponderata_max[i][i] = 0;
    }

}

// void Afisarea_matriciei_adiacenta() {
//     printf("Matricea de adiacenta:\n");
//     for (int i = 1; i <= num_noduri; i++) {
//         for (int j = 1; j <= num_noduri; j++) {
//             printf("%4d", matrice_adiacenta[i][j]);
//         }
//         printf("\n");
//     }
// }
void Afisare_matrice_ponderata()
{
    printf("Matricea ponderata:\n");
    for (int i = 1; i <= num_noduri; i++) {
        for (int j = 1; j <= num_noduri; j++) {
            printf("%-15d", matrice_ponderata_min[i][j]);
        }
        printf("\n");
    }
}

void Gasire_drum_minim_cu_Ford(int nod)
{
    int i;
    bool infinite_costs_exists;
    cost_min_curr[1] = 0;
    for(i = 2; i <=num_noduri; i++){
        cost_min_curr[i] = MAXIM;
    }
    while(infinite_costs_exists)
    {
        infinite_costs_exists = false;
        for(i = 1; i <=num_noduri; i++)
        {
            for(int j = 1; j <=num_noduri; j++)
            {
                if(matrice_ponderata_min[i][j] != 0 && i != j)
                {
                    if(cost_min_curr[j] - cost_min_curr[i]  > matrice_ponderata_min[i][j]) 
                    {
                        cost_min_curr[j] = cost_min_curr[i] + matrice_ponderata_min[i][j];
                        infinite_costs_exists = true;
                    }
                }
            }
        }
    }
    
    printf("Drumul minim este:\n%d\n",cost_min_curr[nod]);
    Afisare_drum_minim_Ford();
    printf("\n\n");

}



void Afisare_drum_minim_Ford()
{
    int k = 0;//pentru a tine contorul vectoruui afisare
    //int t = 0;//pentru a tine urma numarului de muchii din vectorul b
    int l = nod;//pentru a pastra originea nodului de plecare(originea) pentru a afisa graful
    for(int i = num_muchii - 1; i >= 0; i--)
    {
        if(arce[i].to == l)
        {
            if(cost_min_curr[arce[i].to] - cost_min_curr[arce[i].from] == matrice_ponderata_min[arce[i].from][arce[i].to])
            {
                afisare[k] = arce[i].to;
                k++;
                l = arce[i].from;
            }
        }
    }    
    
    afisare[k] = 1;
    printf("Drumul este: ");
    for (int i = k; i >= 0; i--)
    {
        printf("%d ", afisare[i]);
    }
    printf("\n\n");

}

void Gasire_drum_maxim_cu_Ford(int nod)
{
    int i;
    bool infinite_costs_exists;
    cost_max_curr[1] = 0;
    for(i = 2; i <=num_noduri; i++){
        cost_max_curr[i] = MINIM;
    }
    while(infinite_costs_exists){
        infinite_costs_exists = false;
    for(i = 1; i <=num_noduri; i++) {
        for(int j = 1; j <=num_noduri; j++){
            if(matrice_ponderata_max[i][j] != 0 && i != j){
                //printf("Salut\n");
                if(cost_max_curr[j] - cost_max_curr[i]  < matrice_ponderata_max[i][j]) 
                    {
                        cost_max_curr[j] = cost_max_curr[i] + matrice_ponderata_max[i][j];
                        infinite_costs_exists = true;
                    }
                }
            }
        }
    }
    printf("Drumul maxim este:\n%d\n",cost_max_curr[nod]);
    Afisare_drum_maxim_Ford();
    printf("\n\n");
}
void Afisare_drum_maxim_Ford()
{
    int k = 0;//pentru a tine contorul vectoruui afisare
    //int t = 0;//pentru a tine urma numarului de muchii din vectorul b
    int l = nod;//pentru a pastra originea nodului de plecare(originea) pentru a afisa graful
    for(int i = num_muchii - 1; i >= 0; i--)
    {
        if(arce[i].to == l)
        {
            if(cost_max_curr[arce[i].to] - cost_max_curr[arce[i].from] == matrice_ponderata_max[arce[i].from][arce[i].to])
            {
                afisare[k] = arce[i].to;
                k++;
                l = arce[i].from;
            }
        }    
    }
        afisare[k] = 1;
        printf("Drumul este: ");
        for (int i = k; i >= 0; i--)
        {
            printf("%d ", afisare[i]);
        }
        printf("\n\n");
}

void  Gasire_drum_minim_cu_Bellman_Kalaba(int momeala)
{
    // if(matrice_ponderata[1][momeala] == Maxim);
    for (int i = 1; i <= num_noduri; i++)
    {
        for (int j = 1; j <= num_noduri; j++)
        {
            if(matrice_ponderata_min[i][j] == 0)
                matrice_ponderata_min[i][j] = MAXIM;
        }
        matrice_ponderata_min[i][i] = 0;
    }
    for (int i = 1; i <= num_noduri; i++)
    {
        for (int j = 1; j <= num_noduri; j++)
        {
          bellman_matr_min[i][j] = matrice_ponderata_min[i][j];
        }
    }

    //creare V1
    int n = num_noduri;
    for (int i = num_noduri + 1; i <= num_noduri + 1; i++)
    {
        for (int j = 1; j <= num_noduri; j++)
        {
            bellman_matr_min[i][j] = matrice_ponderata_min[j][num_noduri];
        }
    }

    n = 1;                      //counter pentru stocare
    int p = num_noduri + 2;     //counter pentru matrice bellman caseta
    int c = num_noduri + 1;     //counter bellman randuri
    int identice = 1;

    while(identice)
    {
        identice = 0;
        for (int i = 1; i <= num_noduri; i++) 
        {
    n = 1;
            for (int j = 1; j <= num_noduri; j++) 
            {
                stocare_min[n] = bellman_matr_min[i][j] + bellman_matr_min[c][n];
                n++;
            }
                bellman_matr_min[p][i] =  Gasire_element_min();
        }
        for(int h = 1; h <= num_noduri; h++)
        {
            if(bellman_matr_min[p][h] == bellman_matr_min[p - 1][h])
                identice = 0;
            else
            {
                identice = 1;
                break;
            } 
        }
    c++;
    p++;
    }
printf("Salut\n");

    printf("DUPA   Matricea Bellman Kalaba:\n");
    for (int i = 1; i <= c; i++) 
    {
        for (int j = 1; j <= num_noduri; j++) 
        {
            printf("%-10d", bellman_matr_min[i][j]);
        }
        printf("\n");
    }

    printf("Dumul minim este %d\n", bellman_matr_min[c][momeala]);

    for (int i = 1; i <= num_noduri; i++)
    {
        if(i == momeala)
        {
            for (int j = 1; j <= num_noduri; j++)
            {
                if(bellman_matr_min[c][i] - bellman_matr_min[i][j] == bellman_matr_min[c][j] && i != j)
                {
                    printf("%d ",i);
                    momeala = j;
                    break;
                }
            }
        }
    }
    
    printf("%d ",num_noduri);
    
}

int Gasire_element_min(){
    int min = stocare_min[1];
    for(int i = 2; i <= num_noduri; i++){
        if(min > stocare_min[i]){
            min = stocare_min[i];
        }
    }
    return min;
}

void  Gasire_drum_maxim_cu_Bellman_Kalaba(int momeala)
{
    // if(matrice_ponderata[1][momeala] == Maxim);

    //  for (int i = 1; i <= num_noduri; i++)
    // {
    //     for (int j = 1; j <= num_noduri; j++)
    //     {
    //         if(matrice_ponderata_max[i][j] == 0)
    //             matrice_ponderata_max[i][j] = MINIM;
    //     }
    //     matrice_ponderata_max[i][i] = 0;
    // }
 

    for (int i = 1; i <= num_noduri; i++)
    {
        for (int j = 1; j <= num_noduri; j++)
        {
          bellman_matr_max[i][j] = matrice_ponderata_max[i][j];
        }
    }

    //creare V1
    int n = num_noduri;
    for (int i = num_noduri + 1; i <= num_noduri + 1; i++)
    {
        for (int j = 1; j <= num_noduri; j++)
        {
            bellman_matr_max[i][j] = matrice_ponderata_max[j][num_noduri]; // coloana transpusa
        }
    }

    n = 1;                      //counter pentru stocare
    int p = num_noduri + 2;     //counter pentru matrice bellman caseta
    int c = num_noduri + 1;     //counter bellman randuri
    int identice = 1;
        
    while(identice)
    {
        identice = 0;
        for (int i = 1; i <= num_noduri; i++) 
        {
    n = 1;
            for (int j = 1; j <= num_noduri; j++) 
            {
                stocare_max[n] = bellman_matr_max[i][j] + bellman_matr_max[c][n];
                n++;
            }
               bellman_matr_max[p][i] = Gasire_element_max();
        }

        for(int h = 1; h <= num_noduri; h++)
        {
            if(bellman_matr_max[p][h] == bellman_matr_max[p - 1][h])
                identice = 0;
            else
            {
                identice = 1;
                break;
            } 
        }
    c++;
    p++;
    }

    printf("Matricea Bellman Kalaba DUPA :\n");
    for (int i = 1; i <= c; i++) 
    {
        for (int j = 1; j <= num_noduri; j++) 
        {
            printf("%-15d", bellman_matr_max[i][j]);
        }
        printf("\n");
    }

    printf("Dumul maxim este %d\n", bellman_matr_max[c][momeala]);

    for (int i = 1; i <= num_noduri; i++)
    {
        if(i == momeala)
        {
            for (int j = 1; j <= num_noduri; j++)
            {
                if(bellman_matr_max[c][i] - bellman_matr_max[i][j] == bellman_matr_max[c][j] && i != j)
                {
                    printf("%d ",i);
                    momeala = j;
                    break;
                }
            }
        }
    }
    
    printf("%d ",num_noduri);
    
}

int Gasire_element_max()
{
    int max = stocare_max[1];
    for(int i = 2; i <= num_noduri; i++){
        if(max < stocare_max[i]){
            max = stocare_max[i];
        }
    }
    return max;
}

void Corectare_pondere(int din, int in)
{
    int pondere_noua;
    printf("Introdu ponderea noua: ");
    scanf("%d",&pondere_noua);
    matrice_ponderata_max[din][in] = pondere_noua;
    matrice_ponderata_min[din][in] = pondere_noua;
}


void Eliberere()
{
     for (int i = 1; i <= MAX_NODURI; i++)
     {
        stocare_min[i] = 0;
        stocare_max[i] = 0;
        cost_max_curr[i] = 0;
        cost_max_curr[i] = 0;
    }
}

void Afisarea_optiunilor() {
    printf("\nAlegeti o optiune:\n");
    printf("1. Citire graf de la tastatura\n");
    printf("2. Afisare matrice ponderata\n");
    printf("3. Gasire drum minim cu Ford\n");
    //printf("4. Afisare drum minim Ford\n");
    printf("5. Gasire drum maxim cu Ford\n");
    //printf("6. Afisare drum maxim Ford\n");
    printf("7. Gasire drum minim cu Bellman-Kalaba\n");
    printf("8. Gasire drum maxim cu Bellman-Kalaba\n");
    printf("9. Corectare pondere\n");
    printf("0. Iesire\n");
}












//AM INCERCAT SA PRINTEAZ SUCCESIUNEA VARFURILOR VARFUrilor        no mers
/*
    //afisare[0] = nod;
    int k = 1;
//      for (int i = nod; i >= 1; i--) {
//     for (int j = nod - 1; j >= 1; j--) {
//         if (cost_min_curr[i] == l) {
//             if (cost_min_curr[i] - cost_min_curr[j] == matrice_ponderata[j][i]) {
//             printf(" \ni = %d \ncost_min_curr[i] = %d\tcost_min_curr[j] = %d\n",i,cost_min_curr[i],cost_min_curr[j] );
//             afisare[k] = i;
//             printf("-> %d ",i);
//             k++;
//             l = cost_min_curr[j];
//         }
//         }
//     }
// }*/

//alta varianta care nu merge
/*

    int k = 0,j;
    int l = nod;
        j = nod - 1;
    for (int i = nod; i >= 1; i--) {
            if (i == l) {
                for (int j = nod; j >= 1; j--) {
                if (cost_min_curr[i] - cost_min_curr[j] == matrice_ponderata[j][i]) {
                printf("k = %d\n",k);
                afisare[k] = i;
                k++;
                l = j;
                break;
                }
                }
            }
        
   }
   //printf("k = %d\n",k);
   afisare[k] = 1;
   printf("Drumul este: ");
      for (int i = k; i >= 0; i--)
            printf("%d ", afisare[i]);
*/












/*#define MAX_NODURI 100

typedef struct {
    int u, v, cost;
} Muchie;

Muchie muchii[MAX_NODURI];
int distanta[MAX_NODURI];
int predecesor[MAX_NODURI];

void BellmanFord(int noduri, int muchii_count, int start) {
    for (int i = 0; i < noduri; ++i) {
        distanta[i] = INT_MAX;
        predecesor[i] = -1;
    }
    distanta[start] = 0;

    for (int i = 1; i < noduri; ++i) {
        for (int j = 0; j < muchii_count; ++j) {
            int u = muchii[j].u;
            int v = muchii[j].v;
            int cost = muchii[j].cost;

            if (distanta[u] + cost < distanta[v]) {
                distanta[v] = distanta[u] + cost;
                predecesor[v] = u;
            }
        }
    }

    for (int i = 0; i < muchii_count; ++i) {
        int u = muchii[i].u;
        int v = muchii[i].v;
        int cost = muchii[i].cost;
        if (distanta[u] + cost < distanta[v]) {
            printf("Graful contine un ciclu negativ\n");
            return;
        }
    }
}
*/

