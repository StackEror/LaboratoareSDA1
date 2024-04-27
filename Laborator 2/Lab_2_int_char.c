#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
struct Nod {
    int numar;
    char ch;
    struct Nod * next;
};
typedef struct Nod Ramos;
Ramos* head;
int alegere;
void Initiere(int x,char y);
void Print();
void Delete(int position);
void Insert_end(int x,char y);
void Insert_begin(int x,char y);
void Insert_specific_position(int x,char y,int n);
int  Search_position_number(int nr_de_cautat);
int  Search_position_char(char ch_de_cautat);
void Reverse_linked_list(Ramos** root);
void Sort_list();
void Clean_list();
void Free_memory();

int main()
{
    int nr_elemente;
    int valoarea1;
    char valoarea2;
    int optiune;
    int pozitie;
    int nr_de_cautat;
    char ch_de_cautat;
    head = NULL;
    srand(time(NULL));

    printf("Introdu numarul de elemente pentru a crea o lista: ");
    scanf("%d",&nr_elemente);
    for(int i = 0; i < nr_elemente; i++)
    {
        printf("Introdu valorile nodului: %d\n", i + 1);
        printf("Introdu valoarea 1 (numar)\n");
        //scanf("%d",&valoarea1);
        valoarea1 = (rand() % 100) + 1;
        // getchar();
        // printf("Introdu valoarea 2 (caracter)\n");
        // scanf("%c",&valoarea2);
        // getchar();
        Initiere(valoarea1,valoarea2);
    }
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
            printf("Introdu 1 pentru a cauta un numar sau 2 pentru un caracter\n");
            scanf("%d",&alegere);
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
                    printf("Introdu elementul de cautare (caracter)\n");
                    scanf("%c",&ch_de_cautat);
                    getchar();
                    pozitie = Search_position_char(ch_de_cautat);
                    if(pozitie != -1)   printf("Elementul '%c' se afla la pozitia %d\n",ch_de_cautat,pozitie);
                    else                printf("Elementul '%c' nu a fost gasit in tablou\n",ch_de_cautat);
                break;
            }
        break;
        case 3:
            Free_memory();
        break;
        case 4:
            printf("Introdu 1 pentru a sorta numere sau 2 pentru caractere\n");
            scanf("%d",&alegere);
            Sort_list();
        break;
        case 5:
            printf("Introdu numar:");
            scanf("%d",&valoarea1);
            getchar();
            printf("Introdu caracter:");
            scanf("%c",&valoarea2);
            getchar();
            Insert_end(valoarea1,valoarea2);
        break;
        case 6:
            printf("Introdu numar:");
            scanf("%d",&valoarea1);
            getchar();
            printf("Introdu caracter:");
            scanf("%c",&valoarea2);
            getchar();
            Insert_begin(valoarea1,valoarea2);
        break;
        case 7:
            printf("Introdu pozitia:");
            scanf("%d",&pozitie);
            getchar();
            if(pozitie > nr_elemente || pozitie <=0) {
                printf("Hai ca poti!\n");
                break;
            }
            printf("Introdu numar:");
            scanf("%d",&valoarea1);
            getchar();
            printf("Introdu caracter:");
            scanf("%c",&valoarea2);
            getchar();
            Insert_specific_position(valoarea1,valoarea2,pozitie);
        break;
        case 8:
            printf("Introdu pozitia:");
            scanf("%d",&pozitie);
            if(pozitie > nr_elemente || pozitie <=0) {
                printf("Hai ca poti!\n");
                break;
            }
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
    Ramos * curr = head;
    while(curr != NULL){
        Ramos * temp = curr;
        curr = curr -> next;
        free(temp);
    }
    head = NULL;
    return 0;
}

void Initiere(int x,char y)
{
    Ramos* temp = (Ramos*)malloc(sizeof(Ramos));
    if(head == NULL)
    {
        temp -> numar = x;
        temp -> ch = y;
        temp -> next = head;
        head = temp;
        return;
    }
    temp -> numar = x;
    temp -> ch = y;
    temp->next = NULL;
    Ramos * temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1 -> next;
    }
    temp1->next = temp;
}

void Print()
{
    printf("Primul camp\n");
    Ramos* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp -> numar);
        temp = temp -> next;
    }
    printf("\n");
    // printf("Al doilea camp\n");
    // temp = head;
    // while(temp != NULL)
    // {
    //     printf("%c ",temp -> ch);
    //     temp = temp -> next;
    // }
    printf("\n");
}

void Delete(int position)
{
    Ramos * temp1 = head;
    if(position == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i = 0; i < position -2; i++)
        temp1 = temp1->next;

    Ramos * temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    Print();
    printf("\n");
}

void Insert_end(int x,char y)
{
    Ramos* temp = (Ramos*)malloc(sizeof(Ramos));
    if(head == NULL)
    {
        temp->numar = x;
        temp->ch = y;
        temp->next = head;
        head = temp;
        return;
    }
    temp -> numar = x;
    temp->ch = y;
    temp->next = NULL;
    Ramos * temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1 -> next;
    }
    temp1->next = temp;
    Print();
    printf("\n");
}

void Insert_begin(int x, char y)
{
    Ramos* temp = (Ramos*)malloc(sizeof(Ramos));
    temp -> numar = x;
    temp -> ch = y;
    temp -> next = head;
    head = temp;
    Print();
    printf("\n");
}

void Insert_specific_position(int x, char y, int n)
{
    Ramos* temp1 = (Ramos*)malloc(sizeof(Ramos));
    temp1->numar = x;
    temp1 -> ch = y;
    temp1->next = NULL;
    if(n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Ramos *temp2  = head;
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
    Ramos* temp = head;
    for(int i = 0; temp != NULL; i++){
        if(temp->numar == nr_de_cautat)
        {
            return i + 1;
        }
        temp = temp -> next;
    }
    return -1;
}
int Search_position_char(char ch_de_cautat)
{
    Ramos* temp = head;
    for(int i = 0; temp != NULL; i++){
        if(temp->ch == ch_de_cautat)
        {
            return i + 1;
        }
        temp = temp -> next;
    }
    return -1;
}
void Reverse_linked_list(Ramos** root)
{
    Ramos * prev = NULL;
    Ramos * curr = *root;

    while(curr != NULL){
        Ramos * next = curr->next;
        curr->next = prev;//reverse arrow
        prev = curr;
        curr = next;
    }
    *root = prev;
    Print();
    printf("\n");
}

void Sort_list()
{
    Ramos *end, *r,*p,*q,*temp;

    if(alegere == 1){
    for(end = NULL; end != head->next; end = p){
        
        for(r = p = head; p-> next!=end; r=p, p=p->next){
            q = p -> next;
            if(p -> numar > q -> numar)
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
    Print();
    }
    else if(alegere == 2){
        for(end = NULL; end != head->next; end = p){
        
            for(r= p = head; p-> next!=end; r=p, p=p->next){
            q=p->next;
            if(p->ch > q->ch)
            {
                p->next = q->next;
                q->next = p;
                if(p != head)
                {
                    r->next =q;
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
    Print();
    }
    else{
        printf("Esti bun!\n");
        return;
    }
    printf("\n");
}
void Free_memory()
{
    Ramos * curr = head;
    while(curr != NULL){
        Ramos * temp = curr;
        curr = curr -> next;
        free(temp);
    }
    head = NULL;
}

void Clean_list()
{
    Ramos * curr = head;
    while(curr != NULL){
        curr->numar = 0;
        curr -> ch = 0x30;
        curr = curr -> next;
    }
}

/*Ramos* swap(Ramos* ptr1, Ramos* ptr2)
{
    Ramos* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}


int Sort_list(Ramos** head, int count)
{
    
    Ramos** temp_head;
    int i, j, swapped;
 
    for (i = 0; i <= count; i++) {
 
        temp_head = head;
        swapped = 0;
 
        for (j = 0; j < count - j; j++) {
 
            Ramos* p1 = *temp_head;//primul element din lista
            Ramos* p2 = p1->next;//al doilea element din lista
 
            if (p1->ch > p2->ch) {

                *temp_head = swap(p1, p2);
                swapped = 1;
            }
 
            temp_head = &(*temp_head)->next;
        }
 
        if (swapped == 0)
        printf("hhhhhhhhhhhhh\n");
            break;
    }
}*/

/*
void Sort_list_after_ch()
{
    Ramos  *end, *p,*q;
    int temp;

    for(end = NULL; end != head->next; end = p)
    {
        for(p = head; p-> next!=end; p=p->next)
        {
            q =p->next;
            if(p->numar > q->numar)
            {
                temp = p->numar;
                p->numar = q->numar;
                q->numar= temp;
            }
        }
    }
    
    Print();
}

void Sort_list_after_links()
{
    Ramos *end, *r,*p,*q,*temp;

    for(end = NULL; end != head->next; end = p)
    {
        for(r= p = head; p-> next!=end; r=p, p=p->next)
        {
            q=p->next;
            if(p->numar > q->numar)
            {
                p->next = q->next;
                q->next = p;
                if(p != head)
                    r->next =q;
                else
                    head = q;

                    temp = p;
                    p = q;
                    q = temp;
            }
        }

    }
}*/