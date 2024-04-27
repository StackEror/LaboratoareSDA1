#include <stdio.h>
#include <stdlib.h>
#define MAX_NODURI 10

int num_noduri = 0;
int num_muchii = 0;
int de_la_nod, la_nod;
int matrice_adiacenta[MAX_NODURI][MAX_NODURI];
int graf_acoperire[MAX_NODURI][MAX_NODURI];
int h, q, v1, flag, i;
int k = 1;
int FA[20];
int Lista[10];

void Citire_graf();
void Afisarea_matriciei_adiacenta();
void Afisarea_optiunilor();
void Gasire_graf_de_acoperire();
void Lista_de_adiacenta();

int main() {
    int optiune;
    while(1) {
        Afisarea_optiunilor();
        scanf("%d", &optiune);
        switch (optiune) {
            case 1:
                Citire_graf();
                break;
            case 2:
                Afisarea_matriciei_adiacenta();
                break;
            case 3:
                h=k+1;
                Gasire_graf_de_acoperire();
                break;
            case 4:
                Lista_de_adiacenta();
                break;
            case 5:
                break;
            case 6:
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
    for (int i = 1; i <= num_muchii; i++) {
        printf("Introduceti muchia %d:  ", i);
        scanf("%d %d", &de_la_nod, &la_nod);
        if (de_la_nod > num_noduri || la_nod > num_noduri || de_la_nod <= 0 || la_nod <= 0) { 
            printf("Muchie invalida!\n"); 
            i--; 
        } 
        else{
            matrice_adiacenta[de_la_nod][la_nod] = 1;
            matrice_adiacenta[la_nod][de_la_nod] = 1;
        }
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
            if(graf_acoperire[i][j] ==  1){
                printf("%d - ",j);
            }
        }
        printf("0");
    }
}

void Gasire_graf_de_acoperire(){

    printf("Introduceti varful initial: ");
    scanf("%d", &v1);
    FA[k] = v1;
    
    do{
    i = FA[k];
    Lista[k] = i;
    for (int j = 1; j <= num_noduri; j++){
       if(matrice_adiacenta[i][j] == 1){
           flag = 0;
           for(q = 1; q <= num_noduri; q++){
               if(FA[q] == j){
                   flag = 1;
               } 
           }
           if(flag == 0){
               graf_acoperire[i][j] = matrice_adiacenta[i][j];
             
               FA[h] = j;
               h++;
           }
        }
    }
    k++;
    }
    while(k <= num_noduri);
        printf("\nElementele matricei graf_acoperire sunt: \n");
        for (int i = 1; i <= num_noduri; i++){
            for (int j = 1; j <= num_noduri; j++){
            printf(" %d ", graf_acoperire[i][j]);
            }
            printf("\n");
        }
            printf("Graful parcurs\n");
        for (int i = 1; i <= num_noduri; i++){
                    printf("%d ", Lista[i]);
                printf("\n");
}

}

void Afisarea_optiunilor() {
    printf("\nAlegeti o optiune:\n");
    printf("1. Citire graf de la tastatura\n");
    printf("2. Afisare matrice de adiacenta\n");
    printf("3. Gasire graf de acoperire\n");
    printf("4. Afisare lista de adiacenta a grafului de acoperire\n");
    printf("0. Iesire\n");
}



































/*FA firul de asteptare ,queue
   if(matrice_adiacenta[i][j] == 1){            daca este vrun varf cae nu a fost pus in FA se pune acum
           flag = 0;                            se presupune ca varful nu a fost atins, introdus in lista
           for(q = 1; q <= num_noduri; q++){    ia fiecare nod din FA care este deja
            if(FA[q] == j){                     si il verifica cu acela din matricea de adiacenta cand este == 1,
                   flag = 1;                    daca deja a fost introdus flag == 1 
            if(flag == 0){                      daca nu flag = 0
graf_acoperire[i][j] = matrice_adiacenta[i][j]; daca nu a fost intodus pana acum in lista varful 
                                                se introduce in graf iar apoi,
               FA[h] = j;                       se introduce si in lista pentru a nul parcurge din nou
               h++;                             se incrementeaza  h pentru a PUNE urmatorul element in lista
    }
    k++;   s incrementeaza k pentru a SCOATE urmatorul element din lista
   */