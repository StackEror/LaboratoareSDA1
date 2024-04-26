#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
struct Capra {
    int numar_populatie;
    char *nume_tara;
    struct Capra * next;
};
typedef struct Capra Stat;
Stat* head;
int alegere;
int nr_elemente;
int valoarea1;
char **word_array;
static const char alfabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
void Initiere();
char* init_string();
void Print();
void Delete(int position);
void Insert_end();
void Insert_begin();
void Insert_specific_position(int n);
int  Search_position_number(int nr_de_cautat);
int  Search_position_string(char *str_de_cautat);
void Reverse_linked_list(Stat** root);
void Sort_list();
void Clean_list();
void Free_memory();

int main()
{
    int optiune;
    int pozitie;
    int nr_de_cautat;
    char str_de_cautat[50];
    head = NULL;
    srand(time(NULL));
    Initiere();
    Print();
    while(1){
    printf("Afiseaza elementele                         1\n");
    printf("Afla pozitia unui element                   2\n");
    printf("Elibereaza memoria                          3\n");
    printf("Sorteaza elementele dupa un camp            4\n");
    printf("Insereaza un element la sfarsit             5\n");
    printf("Insereaza un element la inceput             6\n");
    printf("Insereaza un element pe o pozitie           7\n");
    printf("Sterge un element de pe o pozitie tastati   8\n");
    printf("Inversarea ordinei elementelor tastati      9\n");
    printf("Curata lista                                10\n");
    printf("Iesi din program                            0\n");
    scanf("%d",&optiune);
    getchar();
    switch(optiune)
    {
        case 1:
            Print();
        break;
        case 2:
            printf("Pentru numarul popolatiei tastati 1\n");
            printf("Pentru denumirea tarii tastati 2\n");
            scanf("%d",&alegere);
            getchar();
            switch(alegere)
            {
                case 1:
                    printf("Introdu elementul de cautare a pozitiei (numar)\n");
                    scanf("%d",&nr_de_cautat);
                    getchar();
                    pozitie = Search_position_number(nr_de_cautat);
                    if(pozitie != -1)   printf("Elementul '%d' se afla la pozitia %d\n",nr_de_cautat,pozitie);
                    else                printf("Elementul '%d' nu a fost gasit in tablou\n",nr_de_cautat);
                break;
                
                case 2:
                    printf("Introdu elementul de cautare (cuvant)\n");
                    fgets(str_de_cautat, 50, stdin);
                    int lungime_sir = strlen(str_de_cautat);
                    if(lungime_sir > 0 && str_de_cautat[lungime_sir - 1] == '\n')
                    {
                        str_de_cautat[lungime_sir - 1] = '\0';
                    }
                    pozitie = Search_position_string(str_de_cautat);
                    if(pozitie != -1)   printf("Elementul '%s' se afla la pozitia %d\n",str_de_cautat,pozitie);
                    else                printf("Elementul '%s' nu a fost gasit in tablou\n",str_de_cautat);
                break;
            }
        break;
        case 3:
            Free_memory();
        break;
        case 4:
            printf("Pentru a sorta numarul populatiei tastati 1\n");
            printf("Pentru a sorta denumirile tarilor tastati 2\n");
            scanf("%d",&alegere);
            Sort_list();
        break;
        case 5:
            nr_elemente++;
            Insert_end();
        break;
        case 6:
            nr_elemente++; 
            Insert_begin();
        break;
        case 7:
            printf("Introdu pozitia:");
            scanf("%d",&pozitie);
            getchar();
            nr_elemente++;
            if(pozitie > nr_elemente || pozitie <=0) {
                printf("Hai ca poti!\n");
                break;
            }
            Insert_specific_position(pozitie);
        break;
        case 8:
            printf("Introdu pozitia:");
            scanf("%d",&pozitie);
            getchar();
            if(pozitie > nr_elemente || pozitie <=0) {
                printf("Hai ca poti!\n");
                break;
            }
            nr_elemente--;
            Delete(pozitie);
        break;
        case 9:
            Reverse_linked_list(&head);
        break;
        case 10:
            Clean_list();
        break;
        case 0:
            exit(0);
        break;
        default:
        printf("Hai ca poti!\n");
        }
    }
    Stat * curr = head;
    while(curr != NULL){
        Stat * temp = curr;
        free(temp->nume_tara);
        curr = curr -> next;
        free(temp);
    }
    head = NULL;
    return 0;
}

char* init_string() {
    char temp[50];
    printf("Introdu valoarea 2 (Numele tarii)\n");
    fgets(temp, 50, stdin);
    int lungime_sir = strlen(temp);
    if(lungime_sir > 0 && temp[lungime_sir - 1] == '\n')
    {
        temp[lungime_sir - 1] = '\0';
    }
    
    char* numele = malloc(sizeof(char) * lungime_sir);
    strcpy(numele, temp);
    return numele;
}

void Initiere()
{
    head = NULL;
    printf("Introdu numarul de elemente pentru a crea o lista: ");
    scanf("%d",&nr_elemente);
    getchar();
    int len = (rand() % 13) + 1;
    // printf("Introdu lungimea stringurilor\n");
    //scanf("%d",&len);
    // getchar();
    for(int i = 0; i < nr_elemente; i++){
        Stat* temp = (Stat*)malloc(sizeof(Stat));
        printf("Introdu valoarea: %d\n", i + 1);
        temp->numar_populatie = (rand() % 10) + 1;
        temp->nume_tara = (char*)malloc((len + 1) * sizeof(char));
        for (int k = 0; k < len; k++) {
            temp->nume_tara[k] = alfabet[rand() % (sizeof(alfabet) - 1)];
        }
        temp->nume_tara[len] = '\0';
        
    if(head == NULL)
    {
        temp -> next = NULL;// NULL = nu exista
        head = temp;
    }
    
    else
    {
    temp->next = NULL;
    Stat * temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1 -> next;
        }
    temp1->next = temp;
        }
    }
}

void Print()
{
    printf("Numarul populatiei\tDenumirea tarii\n");
    Stat* temp = head;
    while(temp != NULL)
    {
        printf("%-23d%-20s\n",temp -> numar_populatie,temp -> nume_tara);
        temp = temp -> next;
    }
    printf("\n\n");
}

void Delete(int position)
{
    Stat * temp1 = head;
    if(position == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i = 0; i < position - 2; i++)
        temp1 = temp1->next;

    Stat * temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    Print();
    printf("\n");
}

void Insert_end()
{
    Stat* temp = (Stat*)malloc(sizeof(Stat));
    printf("Introdu valorile nodului: \n");
    printf("Introdu valoarea 1 (Numar populatie)\n");
    scanf("%d",&valoarea1);
    getchar();
    if(head == NULL)
    {
        temp->numar_populatie = valoarea1;
        temp->nume_tara = init_string();
        temp->next = head;
        head = temp;
    }
    else{
    temp -> numar_populatie = valoarea1;
    temp->nume_tara = init_string();
    temp->next = NULL;
    Stat * temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1 -> next;
    }
    temp1->next = temp;
    }
    Print();
    printf("\n");
}

void Insert_begin()
{
    printf("Introdu valorile nodului:\n");
    printf("Introdu valoarea 1 (Numar populatie)\n");
    scanf("%d",&valoarea1);
    getchar();
    Stat* temp = (Stat*)malloc(sizeof(Stat));
    temp -> numar_populatie = valoarea1;
    temp -> nume_tara = init_string();
    temp -> next = head;
    head = temp;
    Print();
    printf("\n");
}

void Insert_specific_position(int n)
{
    printf("Introdu valorile nodului: \n");
    printf("Introdu valoarea 1 (Numar populatie)\n");
    scanf("%d",&valoarea1);
    getchar();
    Stat* temp1 = (Stat*)malloc(sizeof(Stat));
    temp1->numar_populatie = valoarea1;
    temp1 -> nume_tara = init_string();
    temp1->next = NULL;
    if(n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Stat *temp2  = head;
    for(int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    Print();
    printf("\n");
}
int Search_position_number(int nr_de_cautat)
{
    Stat* temp = head;
    for(int i = 0; temp != NULL; i++){
        if(temp->numar_populatie == nr_de_cautat)
        {
            return i + 1;
        }
        temp = temp -> next;
    }
    return -1;
}
int Search_position_string(char *str_de_cautat)
{
    Stat* temp = head;
    for(int i = 0; temp != NULL; i++){
        if(strcmp(temp->nume_tara,str_de_cautat) == 0)
        {
            return i + 1;
        }
        temp = temp -> next;
    }
    return -1;
}
void Reverse_linked_list(Stat** root)
{
    Stat * prev = NULL;
    Stat * curr = *root;
    while(curr != NULL){
        Stat * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *root = prev;
    Print();
    printf("\n");
}

void List_to_array()
{
    Stat *ptr = head;
    Stat *prev = NULL;
    int i = 0;
    word_array = malloc(sizeof(char*) * nr_elemente);
    while(ptr != NULL)
    {
        prev = ptr;
        word_array[i++] =ptr->nume_tara;
        ptr = ptr->next;
    }
}

void Sort_list()
{
    Stat *end, *r,*p,*q,*temp;
    if(alegere == 1){
    for(end = NULL; end != head->next; end = p){
        
        for(r = p = head; p-> next!=end; r=p, p=p->next){
            q = p -> next;
            if(p -> numar_populatie > q -> numar_populatie)
            {
                p->next = q->next;
                q->next = p;
                if(p != head)
                {
                    r->next = q;
                }
                else
                {
                    head = q;
                } 
                    temp = p;
                    p = q;
                    q = temp;
            }
        }
    }
    }
    else if(alegere == 2){
        List_to_array();
        int i, j;
    for (i = 0; i <= nr_elemente - 1; i++){

            int min_index = i; 
        for (j = i + 1; j <= nr_elemente - 1; j++){

           if(strcmp(word_array[min_index],word_array[j]) > 0){
                    min_index = j; 
                }
            }
        if (min_index != i) {
            char * temp_string = word_array[i];
            word_array[i] = word_array[min_index];
            word_array[min_index] = temp_string;
        }
        }
    Stat *ptr = head; 
    i = 0;
    while(ptr != NULL){
        ptr->nume_tara = word_array[i++];
        ptr = ptr->next;   
    }
}
    Print();
}

void Free_memory()
{
    Stat * curr = head;
    while(curr != NULL){
        Stat * temp = curr;
        curr = curr -> next;
        free(temp);
    }
    head = NULL;
}

void Clean_list()
{
    Stat * curr = head;
    while(curr != NULL){
        curr->numar_populatie = 0;
        curr -> nume_tara = NULL;
        curr = curr -> next;
    }
    Print();
}