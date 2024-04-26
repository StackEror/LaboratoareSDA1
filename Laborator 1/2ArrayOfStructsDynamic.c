#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define size_char 20
static int number = 0;
int lungime_sir = 0;
struct masina
{
    char *denumire_masina;
    int pret;
    int anul;
};
typedef struct masina Car_for_sale;
int cauta_pozitie_denumire(Car_for_sale * bloc,int len, char * denumire_cautata);
int cauta_pozitie_pret(Car_for_sale * bloc,int pret_de_cautat,int len);
int cauta_pozitie_anul(Car_for_sale * bloc,int an_de_cautat,int len);
void elibereaza_memorie_tablou(Car_for_sale *bloc,int len);
void sort_str(Car_for_sale **bloc,int len, int number);
static int myCompare(const void* a, const void* b);
void adaugare_n_elemente_sfarsit(Car_for_sale **bloc,int * len);
void adaugare_n_elemente_inceput(Car_for_sale **bloc,int * len);
void afisare_elemente(Car_for_sale *bloc,int len);
void inserare_la_pozitie(Car_for_sale **bloc, int *len);
void stergere_element(Car_for_sale **bloc, int *len);
int main()
{
    int len;//cate elemente(masini) in struct
    int pozitie;//pozitia elementelor in tablou
    char *denumire_cautata;//elementul pe care sa il cautam in array
    int choice;//alegerea din meniu
    int choice_2;//alegerea din submeniu
    int pret;
    int an;//pentru a elimina ultimul  \n
    printf("Introdu cate masini vrei\n");
    scanf("%d",&len);
    getchar();

    Car_for_sale* bloc = (Car_for_sale*)malloc(len * sizeof(Car_for_sale));

    //FARE INTRODUCERE DE LA TASTaURA
    for (int i = 0; i < len; i++)
    {
        bloc[i].denumire_masina = (char*)malloc(size_char * sizeof(char));
    }
    strcpy(bloc[0].denumire_masina, "tesla");
    strcpy(bloc[1].denumire_masina, "lada");
    strcpy(bloc[2].denumire_masina, "nissan");
    strcpy(bloc[3].denumire_masina, "volkswagen");
    strcpy(bloc[4].denumire_masina, "merc");
    strcpy(bloc[5].denumire_masina, "bmw");
    bloc[0].pret = 30999;
    bloc[1].pret = 10000;
    bloc[2].pret = 216786;
    bloc[3].pret = 3450;
    bloc[4].pret = 13500;
    bloc[5].pret = 3000;
    bloc[0].anul = 1900;
    bloc[1].anul = 2019;
    bloc[2].anul = 2001;
    bloc[3].anul = 2007;
    bloc[4].anul = 2009;
    bloc[5].anul = 1850;

        //INTRODUCERE DE LA TASTATURA
    /*printf("Introdu valorile de masini \n");
    for(int i = 0; i < len; i++)
    {
       // printf("masina %d\n",i + 1);
        printf("Denumire %d: ",i + 1);
        bloc[i].denumire_masina = (char*)malloc(size_char * sizeof(char));
        fgets(bloc[i].denumire_masina, size_char, stdin);
        lungime_sir = strlen(bloc[i].denumire_masina);
        if(lungime_sir > 0 && bloc[i].denumire_masina[lungime_sir - 1] == '\n')
        {
            bloc[i].denumire_masina[lungime_sir - 1] = '\0';
        }
        printf("Pret %d: ",i + 1);
        scanf("%d",&bloc[i].pret);
        printf("Anul %d: ",i + 1);
        scanf("%d",&bloc[i].anul);
        getchar();
        //printf("\n");
    }*/
 while(1){
    printf("Pentru cautarea unui element dupa o valoarea tastati        1\n");
    printf("Pentru a afisa la consola toate elementele                  2\n");
    printf("Pentru sortarea elementelor dupa un camp a structurii       3\n");
    printf("Pentru inserarea de n elemente noi la capatul tabloului     4\n");
    printf("Pentru inserarea de n elemente noi la inceputul tabloului   5\n");
    printf("Pentru insearea unui element la o pozitie X                 6\n");
    printf("Pentru stergerea unui element de pe o pozitie X             7\n");
    printf("Pentru eliberarea memoriei tabloului si incheiere program   8\n");
    printf("Pentru a iesi din meniu tastati                             0\n");
    scanf("%d",&choice); 
    getchar();  
    system("cls");
       
   switch(choice)
    {
        case 1:
        printf("AI NUMA 3 MASINI MAI MULTE NAM DE UNDE \n");
        printf("Pentru caracteristica denumirii tastati     1\n");
        printf("Pentru caracteristica pretului tastati      2\n");
        printf("Pentru caracteristica anului tastati        3\n");
        scanf("%d",&choice_2);
        // if(choice_2 < 1 || choice_2 > 3){ 
        //     printf("NU ASA\n");
        //     break;
        //     }
        getchar();
        switch(choice_2)
        {
            case 1:
            printf("Introdu elementul pentru a afla pozitia lui\n");
            denumire_cautata = (char*)malloc(size_char * sizeof(char));
            fgets(denumire_cautata, size_char, stdin);
            lungime_sir = strlen(denumire_cautata);
            if(lungime_sir > 0 && denumire_cautata[lungime_sir - 1] == '\n')
            {
                denumire_cautata[lungime_sir - 1] = '\0';
            }

            pozitie = cauta_pozitie_denumire(bloc,len,denumire_cautata);

            if(pozitie != -1)   printf("Elementul '%s' se afla la pozitia %d\n",denumire_cautata,pozitie);
            else                printf("Elementul '%s' nu a fost gasit in tablou\n",denumire_cautata);
            break;

            case 2:
            printf("Introdu pretul pentru a afla pozitia lui\n");
            scanf("%d",&pret);

            pozitie = cauta_pozitie_pret(bloc,pret,len);
            if(pozitie != -1)   printf("Elementul '%d' se afla la pozitia %d\n",pret,pozitie);
            else                printf("Elementul '%d' nu a fost gasit in tablou\n",pret);
            break;

            case 3:

            printf("Introdu anul pentru a afla pozitia lui\n");
            scanf("%d",&an);

            pozitie = cauta_pozitie_anul(bloc,an,len);

            if(pozitie != -1)   printf("Elementul '%d' se afla la pozitia %d\n",an,pozitie);
            else                printf("Elementul '%d' nu a fost gasit in tablou\n",an);
            break;

            default:
            printf("NU STII A NUMARA\n");
            exit(0);
        }
        break;

        case 2:
        afisare_elemente(bloc, len);
        break;

        case 3:
        printf("Pentru a sorta denumirile tastati   1\n");
        printf("Pentru a sorta preturile tastati    2\n");
        printf("Pentru a sorta anul tastati         3\n");
        scanf("%d",&number);
        if(number < 1 || number > 3){ 
            printf("NU ASA\n");
            break;
            }
        getchar();
        
        sort_str(&bloc,len,number);
        break;

        case 4:
        adaugare_n_elemente_sfarsit(&bloc, &len);
        break;

        case 5:
        adaugare_n_elemente_inceput(&bloc,&len);
        break;

        case 6:
        inserare_la_pozitie(&bloc, &len);
        break;

        case 7:
        stergere_element(&bloc,&len);
        break;

        case 8:
        elibereaza_memorie_tablou(bloc,len);
        break;

        case 0:
        exit(0);
        break;

        default:
        exit(0);
    }
}
    for(int i = 0; i < len; i++)
    {
        free(bloc[i].denumire_masina);
    }
    free(bloc);
    return 0;
}
int cauta_pozitie_denumire(Car_for_sale * bloc,int len, char * denumire_cautata)
{  
    for(int i = 0; i < len; i++)
    {
        if(strcmp(bloc[i].denumire_masina,denumire_cautata) == 0)
        {
            system("cls");
            return i + 1;
        }
    }
    return -1;
    system("cls");
}

int cauta_pozitie_pret(Car_for_sale * bloc,int pret_de_cautat,int len)
{
    for(int i = 0; i < len; i++)
    {
        if(bloc[i].pret == pret_de_cautat)
        {
            system("cls");
            return i + 1;
        }
    }
    return -1;
    system("cls");
}
int cauta_pozitie_anul(Car_for_sale * bloc,int an_de_cautat,int len)
{
    for(int i = 0; i < len; i++)
    {
        if(bloc[i].anul == an_de_cautat)
        {
            system("cls");
            return i + 1;
        }
    }
    return -1;
    system("cls");
}

void elibereaza_memorie_tablou(Car_for_sale *bloc,int len)
{
    
    //ELIBERARE DENUMIRE
    for(int i = 0; i < len; i++){
        if(bloc[i].denumire_masina !=0)
            free(bloc[i].denumire_masina);
    }
    free(bloc);
    exit(0);
}

static int myCompare(const void* a, const void* b) 
{   
    
     Car_for_sale *car1 = (Car_for_sale*)a;
     Car_for_sale *car2 = (Car_for_sale*)b;
    if(number == 1){
        return strcmp(car1->denumire_masina, car2->denumire_masina);
    }
    if(number == 2){
        return car1->pret - car2->pret;
    }
    else if(number == 3){
        return car1->anul - car2->anul;
    }
    return 0;
} 

void sort_str(Car_for_sale **bloc,int len, int number)
{
    /*if(bloc == 0){
        for (int i = 0; i < len; i++)
    {
        bloc[i].denumire_masina = (char*)malloc(size_char * sizeof(char));
    }
    }*/
	qsort(*bloc, len, sizeof(Car_for_sale), myCompare); 
     //printf("\nlen === %d\n",len);

    // system("cls");
    if(number == 1){
        printf("Denumirile sortate\n");
        for (int i = 0; i < len; i++) {
        printf("masina %d : ",i + 1);
        printf("%s\n", (*bloc)[i].denumire_masina);
        }
        printf("\n");
    }
    if(number == 2){
        printf("Preturile sortate\n");
        for (int i = 0; i < len; i++) {
        printf("masina %d : ",i + 1);
        printf("%d\n", (*bloc)[i].pret);
        }
        printf("\n");
    }
    else if(number == 3){
        printf("Anii sortati\n");
        for (int i = 0; i < len; i++) {
        printf("masina %d : ",i + 1);
        printf("%d\n", (*bloc)[i].anul);
        }
        printf("\n");
    }

    // for (int i = 0; i < len; i++) {
    // free(bloc[i].denumire_masina);}
}

void adaugare_n_elemente_sfarsit(Car_for_sale **bloc,int * len)
{
    int add_len;
    //printf("len %d\n",(*len));
    printf("Introdu cate elemente noi vrei\n");
    scanf("%d",&add_len);
    getchar();
    (*len)+=add_len;            
    //printf("len %d\n",(*len));

    *bloc = (Car_for_sale*)realloc(*bloc,(*len) * sizeof(Car_for_sale));

    printf("Introdu valorile de masini \n");
    for(int i = (*len) - add_len; i < *len; i++)
    {
       printf("masina %d\n",i + 1);
        printf("Denumire %d: ",i + 1);
        (*bloc)[i].denumire_masina = (char*)malloc(size_char * sizeof(char));
        fgets((*bloc)[i].denumire_masina, size_char, stdin);
        lungime_sir = strlen((*bloc)[i].denumire_masina);
        if(lungime_sir > 0 && (*bloc)[i].denumire_masina[lungime_sir - 1] == '\n')
        {
            (*bloc)[i].denumire_masina[lungime_sir - 1] = '\0';
        }
        printf("Pret %d: ",i + 1);
        scanf("%d",&(*bloc)[i].pret);
        printf("Anul %d: ",i + 1);
        scanf("%d",&(*bloc)[i].anul);
        //printf("\n");
        getchar();
    }
        
    //getchar();
     for(int i = 0; i <*len; i++){
        printf("Masina : %-5dDenumire:  %-15s",i + 1,(*bloc)[i].denumire_masina);
        printf("Pret :%-15d",(*bloc)[i].anul);
        printf("Anul :%-15d\n",(*bloc)[i].pret);
        // printf("\n"); 
    }
    printf("\n");
    // for(int i = 0; i < (*len); i++)
    // {
    //     free((*bloc)[i].denumire_masina);
        
    // }
    // free((*(*bloc)));
}

void adaugare_n_elemente_inceput(Car_for_sale **bloc, int *len) {
    int add_len;
    printf("Introdu cate elemente noi vrei\n");
    scanf("%d", &add_len);
    getchar();
    *len += add_len;

    Car_for_sale *new_bloc = malloc((*len) * sizeof(Car_for_sale));

    printf("Introdu valorile de masini \n");
    for(int i = 0; i < add_len; i++)
    {
       printf("masina %d\n",i + 1);
        printf("Denumire %d: ",i + 1);
        new_bloc[i].denumire_masina = (char*)malloc(size_char * sizeof(char));
        fgets(new_bloc[i].denumire_masina, size_char, stdin);
        lungime_sir = strlen(new_bloc[i].denumire_masina);
        if(lungime_sir > 0 && new_bloc[i].denumire_masina[lungime_sir - 1] == '\n')
        {
            new_bloc[i].denumire_masina[lungime_sir - 1] = '\0';
        }
        printf("Pret %d: ",i + 1);
        scanf("%d",&new_bloc[i].pret);
        printf("Anul %d: ",i + 1);
        scanf("%d",&new_bloc[i].anul);
        //printf("\n");
        getchar();
    }
    
    //getchar();
    for (int i = add_len; i < *len; i++) {
        new_bloc[i] = (*bloc)[i - add_len];
    }
    system("cls");
    for(int i = 0; i <*len; i++){
        printf("Masina : %-5dDenumire:  %-15s",i + 1,new_bloc[i].denumire_masina);
        printf("Pret :%-15d",new_bloc[i].anul);
        printf("Anul :%-15d\n",new_bloc[i].pret);
        // printf("\n"); 
    }
    printf("\n");
    // free(*bloc);
    *bloc = new_bloc;
}
void afisare_elemente(Car_for_sale *bloc,int len)
{
    system("cls");
     for(int i = 0; i <len; i++){
        printf("Masina : %-5dDenumire:  %-15s",i + 1,bloc[i].denumire_masina);
        printf("Pret :%-15d",bloc[i].anul);
        printf("Anul :%-15d\n",bloc[i].pret);
    }
}
void inserare_la_pozitie(Car_for_sale **bloc, int *len) {
    Car_for_sale nou;
    nou.denumire_masina = (char *)malloc(size_char * sizeof(char));
    int pozitie = 0;
    printf("Intodu pozitia la care sa introduci elementul\n");
    scanf("%d",&pozitie);
    getchar();
    if(pozitie <= 0 || pozitie > *len){
        printf("Bai, invata a numara\n");
        return;
    }

    printf("Introdu denumirea masinii: ");
    fgets(nou.denumire_masina, size_char, stdin);
    int lungime_sir = strlen(nou.denumire_masina);
    if (lungime_sir > 0 && nou.denumire_masina[lungime_sir - 1] == '\n') {
        nou.denumire_masina[lungime_sir - 1] = '\0';
    }
    printf("Introdu pretul pentru masina noua: ");
    scanf("%d",&nou.anul);

    printf("Introdu anul pentru masina noua: ");
    scanf("%d",&nou.pret);
    getchar();
    
    *bloc = (Car_for_sale *)realloc(*bloc, (*len + 1) * sizeof(Car_for_sale));

    for (int i = *len; i > pozitie - 1; i--) {
        (*bloc)[i] = (*bloc)[i - 1];
    }
    (*bloc)[pozitie - 1] = nou;
    system("cls");
    for(int i = 0; i <*len; i++){
        printf("Masina : %-5dDenumire:  %-15s",i + 1,(*bloc)[i].denumire_masina);
        printf("Pret :%-15d",(*bloc)[i].anul);
        printf("Anul :%-15d\n",(*bloc)[i].pret);
    }
    printf("\n");
    (*len)++;
}
void stergere_element(Car_for_sale **bloc, int *len)
{
    int pozitie = 0;
    printf("Intodu pozitia pentru stergere\n");
    scanf("%d",&pozitie);
    getchar();
    if(pozitie <= 0 || pozitie > *len){
        printf("Bai, invata a numara\n");
        return;
    }
    for (int i = pozitie - 1; i < *len - 1 ; i++) {
        (*bloc)[i] = (*bloc)[i + 1];
    }
    (*len)--;
    system("cls");
    for(int i = 0; i <*len; i++){
        printf("Masina : %-5dDenumire:  %-15s",i + 1,(*bloc)[i].denumire_masina);
        printf("Pret :%-15d",(*bloc)[i].anul);
        printf("Anul :%-15d\n",(*bloc)[i].pret);
    }
    printf("\n");
}

