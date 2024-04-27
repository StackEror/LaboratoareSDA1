#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define size_char 50

struct carte
{
    char *denumire_carte;
    int pagini;
    int editie;
};
typedef struct carte Coperta;

int cauta_pozitie_pagina(int pagina_de_cautat,FILE *file,int carti,Coperta *bun);
int count_rand(FILE *file);
int main()
{
    FILE *file;
    file = fopen("C:\\Semestru2 SDA\\Laborator1\\carturar.txt", "r");
    if(file == NULL)
    {
        printf("Nu sa putut deschide fisierul\n");
        return(-1);
    }
    int pagina_de_cautat;
    int pozitie;

    int carti = count_rand(file);
    Coperta bun[carti];
    rewind(file);
    printf("In fisierul de stocare sunt %d carti\n",carti);
    for (int i = 0; i < carti; i++) {
       bun[i].denumire_carte = (char*)malloc(size_char * sizeof(char));
    }
    do{
    printf("Introdu paginile cartii de cautat, pentru a iesi tastati 0:\n");
    scanf("%d",&pagina_de_cautat);
    pozitie = cauta_pozitie_pagina(pagina_de_cautat,file,carti,bun);

    if(pozitie != -1){
        printf("Elementul '%d' a fost gasit la pozitia  %d\n",pagina_de_cautat,pozitie );
    }
    else {
        printf("Elementul '%d' nu a fost gasit in office\n",pagina_de_cautat );
    }

    rewind(file);

       // printf("Salut");
    for(int i = 0; i < carti; i++){
        fscanf(file, "%s %d %d",bun[i].denumire_carte,&bun[i].pagini,&bun[i].editie);
    }
    for(int i = 0; i < carti; i++){
        printf("%s %d %d\n",bun[i].denumire_carte,bun[i].pagini,bun[i].editie);
    }
      
        }while(pagina_de_cautat != 0);

    for (int i = 0; i < carti; i++)
    {
        free(bun[i].denumire_carte);
    }
    fclose(file);
    return 0;
}


int count_rand(FILE *file){

        int current_line = 1;
        char c;
        do{
            c = fgetc(file);
        
        if(c == '\n') current_line++;

        }while(c != EOF);
        return current_line;
}

int cauta_pozitie_pagina(int pagina_de_cautat,FILE *file,int carti,Coperta *bun){
        for(int i = 0; i < carti; i++){
            fscanf(file, "%s %d %d",bun[i].denumire_carte,&bun[i].pagini,&bun[i].editie);
            if(bun[i].pagini == pagina_de_cautat ){
                return i + 1;
            }
        }
         return -1;
}



/*
carte1 256 2002
carte1 300 1900
carte3 100 2012
carte4 256 2003
carte5 234 2001
carte6 678 1999
carte7 432 1800
carte8 198 2500
carte9 362 1500
*/


//FUNCTII ADAOS LA LABORATOR 2 DE ADAUGARE PRET AN SFARSIT
/*
void adaugare_pret_sfarsit(Car_for_sale **bloc,int * len)
{
    int add_len;
    printf("len %d\n",(*len));
    printf("Introdu cate elemente noi vrei\n");
    scanf("%d",&add_len);
    getchar();
    (*len)+=add_len;            
    printf("len %d\n",(*len));
         
    *bloc = (Car_for_sale*)realloc(*bloc,(*len) * sizeof(Car_for_sale));

    printf("Introdu valorile pentru masinile noi\n");
    for(int i = (*len) - add_len; i < *len; i++){
        scanf("%d",&(*bloc)[i].pret);
    }
    system("cls");
    printf("\nElementele finale\n");
    for(int i = 0; i <(*len); i++){
        printf("masina %d : ",i + 1);
        printf("%d\n",(*bloc)[i].pret);
    }
    printf("\n");
    // for(int i = 0; i < (*len); i++)
    // {
    //     free((*bloc)[i].denumire_masina);
        
    // }
    // free((*bloc));
}

void adaugare_anul_sfarsit(Car_for_sale **bloc,int * len)
{
    int add_len;
    printf("len %d\n",(*len));
    printf("Introdu cate elemente noi vrei\n");
    scanf("%d",&add_len);
    getchar();
    (*len)+=add_len;            
    printf("len %d\n",(*len));

    *bloc = (Car_for_sale*)realloc(*bloc,(*len) * sizeof(Car_for_sale));

    printf("Introdu preturile pentru masinile noi\n");
    for(int i = (*len) - add_len; i < *len; i++){
        scanf("%d",&(*bloc)[i].pret);
    }
    system("cls");
    printf("\nElementele finale\n");
    for(int i = 0; i <(*len); i++){
        printf("masina %d : ",i + 1);
        printf("%d\n",(*bloc)[i].pret);
    }
    printf("\n");
    // for(int i = 0; i < (*len); i++)
    // {
    //     free((*bloc)[i].denumire_masina);
        
    // }
    // free((*bloc));
}*/



/*void sort_str(Car_for_sale *bloc,int len)
{
    printf("len %d\n",len);
    char temp[100];
    for(int i = 0; i < len - 1; i++)
    {
        int j_min = i;                          
        for(int j = i + 1; j < len; j++){       
            if(j != i && strcmp(bloc[j].denumire_masina,bloc[j_min].denumire_masina) < 0){

                j_min = j;
                
                if(j_min != i)
                {//printf("Salut\n");
                    strcpy(temp,bloc[i].denumire_masina);
                    strcpy(bloc[i].denumire_masina,bloc[j_min].denumire_masina);
                    strcpy(bloc[j_min].denumire_masina,temp);
                }
            }
        }
    }
    
    printf("\nSirul aranjat este:\n");
        for (int i = 0; i < len; i++) {
        printf("%s\n", bloc[i].denumire_masina);
        }

}*/


//PROBLEMA CARE NU MERGE
/*void adaugare_n_elemente_inceput(Car_for_sale **bloc,int * len)
{

    int add_len;
    printf("len %d\n",(*len));
    printf("Introdu cate elemente noi vrei\n");
    scanf("%d",&add_len);
    getchar();
    (*len)+=add_len; 
    printf("len %d\n",(*len));
    
    Car_for_sale *new_bloc = realloc((*len) * sizeof(Car_for_sale));
    
    for (int i = 0; i < add_len; i++) {
        new_bloc[i].denumire_masina = malloc(size_char * sizeof(char));
        fgets(new_bloc[i].denumire_masina, size_char, stdin);
        int len_sir = strlen(new_bloc[i].denumire_masina);
        if (len_sir > 0 && new_bloc[i].denumire_masina[len_sir - 1] == '\n') {
            new_bloc[i].denumire_masina[len_sir - 1] = '\0';
        }
    }
    
        for(int i = (*len) - 1; i >= add_len; i--){
            strcpy((*bloc[i]).denumire_masina,(*bloc[i - add_len]).denumire_masina);
                printf("Salut");
        }
        

    printf("Introdu valorile pentru masinile noi\n");
    for(int i = 0; i < add_len; i++){
        (*bloc[i]).denumire_masina = (char*)malloc(size_char * sizeof(char));

        fgets((*bloc[i]).denumire_masina, size_char, stdin);
        int len_str = strlen((*bloc[i]).denumire_masina);
        if(len_str > 0 && (*bloc[i]).denumire_masina[len_str - 1] == '\n')
        {
            (*bloc[i]).denumire_masina[len_str - 1] = '\0';
        }
    }
    printf("\nElementele finale\n");
    for(int i = 0; i <(*len); i++){
        printf("%s ",(*bloc[i]).denumire_masina);
    }

    for(int i = 0; i < (*len); i++)
    {
        free((*bloc[i]).denumire_masina);
        
    }
    free(bloc);
}*/

//PENTRU A ADAUGA N ELEMENTE DE INT
/*
void adaugare_n_elemente_inceput(Car_for_sale *bloc,int * len)
{

    int add_len;
    printf("len %d\n",(*len));
    printf("Introdu cate elemente noi vrei\n");
    scanf("%d",&add_len);
    getchar();
    (*len)+=add_len; 
    printf("len %d\n",(*len));
    
    bloc = realloc(bloc,(*len) * sizeof(Car_for_sale));
    
        for (int i = *len - 1; i >= 0; i--) {
            (bloc)[i + add_len] = (bloc)[i];
}
    
    printf("Introdu valorile pentru masinile noi\n");
    for (int i = 0; i < add_len; i++) {
        scanf("%d",&bloc[i].anul);
    }
    
        
    printf("\nElementele finale\n");
    for(int i = 0; i <(*len); i++){
        printf("%d ",bloc[i].anul);
    }

    free(bloc);
}
*/


