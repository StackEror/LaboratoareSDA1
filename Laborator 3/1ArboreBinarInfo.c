/*  1. Depth traversal are 3 types:  data == root
        root->left->right  = PREORDER TRAVERSAL
        left ->root->right = INORDER   TRAVERSAL
        left->right->root  = POST ORDER TRAVERSAL
    2. Level order breadth  */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <queue.h>
typedef struct Arbore_binar BST;
struct Arbore_binar
{
    int data;
    BST *left;
    BST *right;
};
BST * root;
BST *  Insert(BST* root, int data);
BST* Create_new_node(int data);
// bool Search(BST* root, int data);
bool Is_BST_or_no(BST* root);
bool Is_subtree_lesser(BST* root,int value);
bool Is_subtree_greater(BST* root,int value);
// bool IsBstUtil(BST *root,int MinValue, int MaxValue);
void Level_order_traversal(BST *root);
void Preorder(BST *root);
int main()
{
    root = NULL;//arborele este gol
    root = Insert(root,20);//1 apeleaza
    root = Insert(root,13);
    root = Insert(root,3);
    root = Insert(root,25);
    root = Insert(root,10);
    root = Insert(root,30);
    root = Insert(root,19);
    root = Insert(root,17);
    root = Insert(root,29);
    if(Is_BST_or_no(root) == true) 
        printf("Da este arbore binar\n");
    else
        printf("Nu este arbore binar\n");
    Preorder(root);
    printf("\nHeight = %d",Find_height_of_node(root));

    // int number;
    /*printf("Introdu un numar\n");
    scanf("%d", &number);
    if(Search(root, number) == true) printf("Number gasit\n");
    else printf("Numar negasit\n");*/

}

BST * Insert(BST* root, int data)
{
    if(root == NULL){ //1 arborele este gol
        root = Create_new_node(data);// 1deoarece root == NULL se va crea un nou nod
    }
    else if(data <= root->data){
        root->left =Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;
}
BST *Create_new_node(int data)
{
    BST *new_node = (BST*)malloc(sizeof(BST));// 1 se va crea o adresa in(heap)random; Ex:200
    if(new_node != NULL){
    new_node -> data = data;// 1 punem data in nodul 200
    new_node -> left = NULL;//1 nu pointeaza la nimic
    new_node -> right = NULL;//1 nu pointeaza la nimic
    }
    else printf("Error malloc\n");
    return new_node;// va returna adresa blocului creat
}

// bool Search(BST* root, int data)
// {
//     if(root == NULL) return false;
//     else if(root->data == data) return true;
//     else if(data <= root->data) return Search(root->left, data);
//     else return Search(root->right,data);
// }
// void Print_tree(BST * root)
// {

// }


void Level_order_traversal(BST *root)
{
    if(root == NULL) return;
}
void Preorder(BST *root)
{
    if(root == NULL) return;
    Preorder(root->right);
    printf("%d  ",root->data);
    Preorder(root->left);
}

bool Is_BST_or_no(BST* root)
{
    if(root == NULL) return true;
        if(Is_subtree_lesser(root->left,root->data) 
            && Is_subtree_greater(root->right,root->data)
            && Is_BST_or_no(root->left)
            && Is_BST_or_no(root->right))
        return true;
     else 
        return false;
}
bool Is_subtree_lesser(BST* root,int value){
    if(root == NULL) return true;
    if(root->data <= value
        && Is_subtree_lesser(root->left,value)
        && Is_subtree_lesser(root->right,value))
        return true;
    else 
        return false;
}
bool Is_subtree_greater(BST* root,int value){
    if(root == NULL) return true;
    if(root->data <= value
        && Is_subtree_greater(root->left,value)
        && Is_subtree_greater(root->right,value))
        return true;
    else 
        return false;
}
// bool IsBstUtil(BST* root,int MinValue, int MaxValue)
// {
//     if(root == NULL) return true;
//     if(root->data < MinValue && root->data > MaxValue 
//      && IsBstUtil(root->left,MinValue,root->data)
//      && IsBstUtil(root->right,root->data,MaxValue))
//         return true;
//      else 
//         return false;
// }
// bool Is_BST_or_no(BST* root)
// {
//     return IsBstUtil(root,INT_MIN,INT_MAX);
// }

int Find_height_of_node(BST * root)
{
    if(root == NULL)
        return -1;  //deoarece acesta este leaf node
    int left_height = Find_height_of_node(root->left);
    int right_height = Find_height_of_node(root->right);
    return(left_height > right_height) ? left_height + 1: right_height + 1;
}





// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// CREAREA ARBORELUI CU RAND
/*

Tree* create_binary_tree_node()
{
    Tree * head =(Tree*)malloc(1 * sizeof(Tree));
    head->left = NULL;
    head->right = NULL;
    return head;
    //Tree * rad = calloc(1,sizeof(Tree));
    //return rad;
}




Tree *Insert(Tree *root, int x) {
    if (root == NULL) 
    {
        root = create_binary_tree_node();
        root -> data = x;
        return root;
    }
    //int adanc = Depth(root->left) - Depth(root->right);
    srand(time(NULL));
    int choice = rand() % 2;
    
    if (choice == left_subtree) {
        root->left = Insert(root->left, x);
    } else if(choice == right_subtree){
        root->right = Insert(root->right, x);
    }
    printf("choice  = %d\n",choice);
    return root;
}*/


    
    
    // printf("Introdu optiona : ");
    // for(int i = 0; i < 8; i++)
    // {
    //     printf("Alege: ");
    //     scanf("%d",&x);
    //     root = Insert(root,x);
    // }
    //printf("size 1 = %d, size 2 =  %d",sizeof(Tree),sizeof(Tree_root));

    // printf("\ndepth = %d\n",Depth(root));
    // printf("adancime = %d\n",adancime(root));



//      Asta din chat :))
/*
int adancime(struct tree *radacina) {
    if (radacina == NULL) 
        return 0;
    int stanga = adancime(radacina->left);
    int dreapta = adancime(radacina->right);
    return (stanga > dreapta) ? stanga + 1 : dreapta + 1;
}

struct tree *introdu(struct tree *radacina, int x) {
    if (!radacina) {
        radacina = (struct tree*)calloc(1,sizeof(struct tree));
        radacina->info = x;
        return radacina;
    }
    
    int adanc = adancime(radacina->left) - adancime(radacina->right);
    
    if (adanc >= 0) {
        radacina->left = introdu(radacina->left, x);
    } else {
        radacina->right = introdu(radacina->right, x);
    }
    
    return radacina;
}*/


//          LABORATORUL LA INCEPUT
/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#define MAX_SIZE 100
static const char alfabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
typedef struct Tree
{
    int data; 
    char *name;
    struct Tree * left;
    struct Tree * right;
}Tree; 
    
Tree * root;

// enum subtree {left_subtree = 0,right_subtree = 1};

void Inorder(Tree * root);
void Postorder(Tree * root);
void Preorder(Tree * root);
bool Search_a_node_from_tree_after_a_field(Tree * root,int value,char * str_for_search);
int Depth(Tree *root);
Tree *Insert(Tree *root, int x);
void Delete_all_nodes_from_tree(Tree * current_node);
void Fa_treaba();
void Show_menu();
int Total_number_of_nodes();
int Depth_of_a_node(Tree *root,int value);
void Show_all_leafs(Tree * root);
void Clean_tree(Tree * root);
int Height_of_a_node(int value);
// void Delete_a_node_from_tree();
int main()
{
    Fa_treaba();
    return 0;
}

unsigned int num_noduri = 0;

int Depth(Tree *root) {
    if (root == NULL) 
        return -1;
    int stanga = Depth(root->left);
    int dreapta = Depth(root->right);
    return (stanga > dreapta) ? stanga + 1 : dreapta + 1;
}

Tree *Insert(Tree *root, int x) {
    if (!root) {
        root = (Tree*)calloc(1,sizeof(Tree));
        srand(time(0));
        int len = (rand() % 13) + 1;
        root->name = calloc((len + 1),sizeof(char));
        for (int k = 0; k < len; k++) {
            root->name[k] = alfabet[rand() % (sizeof(alfabet) - 1)];
        }
        root->name[len] = '\0';
        root->data = x;
        num_noduri++;
        return root;
    }
    
    int adanc = Depth(root->left) - Depth(root->right);
    
    if (adanc <= 0)
        root->left = Insert(root->left, x);
     else 
        root->right = Insert(root->right, x);

    return root;
}

int Total_number_of_nodes()
{
    return num_noduri;
}

int Depth_of_a_node(Tree *root,int value)
{
     if(root == NULL) 
        return -1;

    int dist = -1;

    if((root->data == value) ||
        (dist = Depth_of_a_node(root->left,value)) >= 0 ||
        (dist = Depth_of_a_node(root->right,value)) >= 0)
        return dist + 1;

    return dist;
       
}

void Fa_treaba()
{
    int x;
    int option;
    int value;
    int track;
    int selection;
    char str_for_search[15];
                
    while(1){
        
        Show_menu();
        scanf("%d",&option);
        getchar();

        switch(option)
        {
            case 1:
            if(root == NULL){
                printf("Introdu radacina:\n");
            }
            else{
                printf("Introdu valoarea nodului:\n");
            }
                scanf("%d",&x);
                root = Insert(root,x);
                printf("Arborele este:\n");
                Inorder(root);
                printf("\n");
            break;

            case 2:
                printf("Arborele este:\n");
                Inorder(root);
                printf("\n");
            break;

            case 3:
                printf("Parcurgerea in inordine a arborelui este:\n");
                Inorder(root);
                printf("\n");
            break;

            case 4:
                printf("Parcurgerea in postordine a arborelui este:\n");
                Postorder(root);
                printf("\n");
            break;

            case 5:
                printf("Parcurgerea in preordine a arborelui este:\n");
                Preorder(root);
                printf("\n");
            break;

            case 6:
                printf("Adancimea arborelui este: %d\n", Depth(root));
            break;
            case 7:
            printf("1.Pentru a cauta numar\n");
            printf("2.Pentru a cauta string\n");
            scanf("%d",&selection);
            if(selection == 1)
            {
                printf("Introdu valoarea de cautat:\n");
                scanf("%d",&track);
            }
            else
            {
                printf("Introdu valoarea de cautat:\n");
                scanf("%s",str_for_search);
            }
                if(Search_a_node_from_tree_after_a_field(root,track,str_for_search))
                    printf("Nodul a fost gasit\n");
                else
                    printf("Nodul nu exista in arbore\n");
                selection = -1;
                memset(str_for_search, 0, sizeof(str_for_search));
            break;
            case 8:
                printf("Introdu valoarea nodul:\n");
                scanf("%d",&value);
                printf("Adancimea nodului %d este %d\n",value,Depth_of_a_node(root,value));
            break;
            case 9:
                printf("Introdu nodul:\n");
                scanf("%d",&value);
                printf("Inaltimea nodului %d este %d\n",value,Height_of_a_node(value));
            break;
            case 10:
                printf("Frunzele arborelui sunt:\n");
                Show_all_leafs(root);
                printf("\n");
            break;
            case 11:
                Clean_tree(root);
            break;
            case 12:
                Delete_all_nodes_from_tree(root);
            break;
            case 13:
                printf("Aborele are %d noduri\n",Total_number_of_nodes());
            break;
            case 0:
                exit(0);
            break;
            default:
                printf("Hai ca poti!\n");
            }
    }

    Delete_all_nodes_from_tree(root);

}

int  Height_of_a_node(int value)
{
    if(root == NULL)
        return -1;

    return Depth(root) - Depth_of_a_node(root,value);
}

void Inorder(Tree *root)
{
	if (root != NULL)
	{
		Inorder(root->left);
		printf(" %d\t", root->data);
        printf(" %d\t", root->name);
		Inorder(root->right);
    }
    
    
}

void Preorder(Tree *root)
{
	if (root != NULL)
	{
		printf(" %d\t", root->data);
        printf(" %s\n", root->name);
		Preorder(root->left);
		Preorder(root->right);
    }
}

void Postorder(Tree *root)
{
	if (root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		printf(" %d\t", root->data);
        printf(" %s\n", root->name);
    }
}
bool Search_a_node_from_tree_after_a_field(Tree *root, int value,char * str_for_search) {
    if (root == NULL) {
        return false;
    }
    
    if (root->data == value || strcmp(root->name,str_for_search) == 0) {
        return true; 
    }
    
    bool found_in_left_subtree = Search_a_node_from_tree_after_a_field(root->left, value,str_for_search);
    bool found_in_right_subtree = Search_a_node_from_tree_after_a_field(root->right, value,str_for_search);
    
    if (found_in_left_subtree || found_in_right_subtree) {
        return true;
    }
    
    return false;
}



void Delete_all_nodes_from_tree(Tree * current_node)
{
	if(current_node)
	{
		Delete_all_nodes_from_tree(current_node->left);
		Delete_all_nodes_from_tree(current_node->right);
		free(root->name);
        free(current_node);
	}
    num_noduri = 0;
    root = NULL;
}

void Show_all_leafs(Tree * root)
{
    if(!root)
        return;

    if(!root->left && !root->right)
    {
        printf("%d ",root->data);
        printf("%s \n",root->name);
        return;
    }

    if(root->left)
        Show_all_leafs(root->left);
    if(root->right)
            Show_all_leafs(root->right);
}

void Clean_tree(Tree * root)
{
    if (root != NULL)
	{
		Clean_tree(root->left);
		root->data = 0;
        root->name = NULL;
		Clean_tree(root->right);
    }
}

void Show_menu()
{
    printf("1. Introdu un nod in arbore     8.  Adancime nod \n");
    printf("2. Afiseaza elementele          9.  Calculeaza inaltime nod\n");
    printf("3. Inordine                     10. Afiseaza toate frunzele\n");
	printf("4. Postordine                   11. Curata elementele arborelui\n");
	printf("5. Preordine                    12. Elibereaza memoria arborelui\n");
    printf("6. Adancime arbore              13. Numarul total de noduri\n");
    printf("7. Cauta nod dupa un camp\n");
    // printf("Calculeaza adancime nod\n");
    // printf("Calculeaza inaltime nod\n");
    // printf("Afiseaza toate frunzele\n");
    // printf("Curatirea elementelor arborelui\n");
    // printf("Elibereaza memoria arborelui\n");
    printf("0. Iesi din program\n");
}



// Binary_Tree * create_node();

// Binary_Tree * create_node()
// {
//     Binary_Tree * node = calloc(1,sizeof(Binary_Tree));
//     return node;
// }
// "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

*/



