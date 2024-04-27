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
