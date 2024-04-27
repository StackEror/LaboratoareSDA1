#include <stdio.h>
#include <stdlib.h>

#define MAX_NODURI 10
#define MAX_SIZE 10

int num_noduri = 0;
int num_muchii = 0;
int de_la_nod, la_nod;
int matrice_incidenta[MAX_NODURI][MAX_NODURI];
int matrice_adiacenta[MAX_NODURI][MAX_NODURI];

void Citire_graf();
void Afisarea_matriciei_incidenta();
void Afisarea_matriciei_adiacenta();
void Afisarea_optiunilor();
void Lista_de_adiacenta();
void Introducere_nod();
void Stergere_nod(int nod);
void Introducere_muchie(int din, int in);
void Stergere_muchie(int din, int in);

int main() {
    int nod;
    int optiune;
    while(1) {
        Afisarea_optiunilor();
        scanf("%d", &optiune);
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
                Introducere_nod();
                break;
            case 6:
                printf("Introdu nodul de stergere\n");
                scanf("%d",&nod);
                Stergere_nod(nod);
                break;
            case 7:
                printf("Introdu muchia\n");
                scanf("%d %d",&de_la_nod, &la_nod);
                Introducere_muchie(de_la_nod,la_nod);
                break;
            case 8:
                printf("Intru muchia de stergere\n");
                scanf("%d %d",&de_la_nod, &la_nod);
                Stergere_muchie(de_la_nod,la_nod);
                break;
            case 9:
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
        //int de_la_nod, la_nod;
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
        //printf("0");
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

void Introducere_nod()
{
    int i; 
    num_noduri++; 
    printf("Nodul introdus este %d \n", num_noduri); 
    for (i = 1; i <= num_noduri; i++) { 
        matrice_adiacenta[i][num_noduri] = 0; 
        matrice_adiacenta[num_noduri][i] = 0;
        matrice_incidenta[i][num_noduri] = 0; 
        matrice_incidenta[num_noduri][i] = 0; 
    } 
}

void Stergere_nod(int nod)
{
	int i,j;
	if(nod == 0)
	{
		printf("Graful este gol\n");
		return;
	}
	if(nod > num_noduri)
	{
		printf("Acest nod nu exista in graf\n");
		return;
	}
        for(i = 1; i <= num_noduri; i++)
	    {
		    matrice_adiacenta[nod][i] = matrice_adiacenta[nod + 1][i];
	    }
	    for(j = nod; j <=num_noduri; j++)
	    {
            matrice_adiacenta[j][nod] = matrice_adiacenta[j][nod + 1];
            matrice_incidenta[j][nod] = matrice_incidenta[j][nod + 1];
        }
	num_noduri--;
}

void Introducere_muchie(int din, int in)
{
    num_muchii++;
	if(din > num_noduri || din <= 0)
	{
		printf("Sursa nodului nu exista\n");
		return;
	}
	if(in > num_noduri || in <= 0)
	{
		printf("Destinatia nodului nu exista\n");
		return;
	}
	matrice_adiacenta[din][in] = 1;
    if (din == in) {
        matrice_incidenta[num_muchii][in] = 2; 
        }
    else{
    matrice_incidenta[num_muchii][din] = -1;
    matrice_incidenta[num_muchii][in] = 1;
    }
}

void Stergere_muchie(int din, int in)
{
     if(din > num_noduri || in > num_noduri || matrice_adiacenta[din][in] == 0 || din <= 0 || in <= 0)
     {
	printf("Aceasta muchie nu exista\n");
	return;
     }
     matrice_adiacenta[din][in] = 0;
     for(int i = 1; i <= num_muchii; i++){
        if((matrice_incidenta[i][din] = -1) && (matrice_incidenta[i][in] = 1)){
        matrice_incidenta[i][din] = 0;
        matrice_incidenta[i][in] = 0;
        }
     }
}

void Afisarea_optiunilor() {
    printf("\nAlegeti o optiune:\n");
    printf("1. Citire graf de la tastatura\n");
    printf("2. Afisare matrice de incidenta\n");
    printf("3. Afisare matrice de adiacenta\n");
    printf("4. Afisare lista de adiacenta\n");
    printf("5. Introducere un nod\n");
    printf("6. Stergere un nod\n");
    printf("7. Introducere muchie\n");
    printf("8. Stergere muchie\n");
    printf("9. Iesire\n");
}