#include "BinaryTreeLib.h"

static const char alfabet[] = "abc";
// "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
unsigned int number_of_nodes = 0;

int get_depth_of_tree(Fam_Tree *root)
{
    if (root == NULL) 
        return -1;
    int stanga = get_depth_of_tree(root->left);
    int dreapta = get_depth_of_tree(root->right);
    return (stanga > dreapta) ? stanga + 1 : dreapta + 1;
}

Fam_Tree *insert_node_in_tree(Fam_Tree *root, int node_value) {    
    if (!root) {
        root = (Fam_Tree*)calloc(1,sizeof(Fam_Tree));
        
        int len = (rand() % 5) + 1;
        root->name = calloc((len + 1),sizeof(char));
        for (int k = 0; k < len; k++) {
            root->name[k] = alfabet[rand() % (sizeof(alfabet) - 1)];
        }
        root->name[len] = '\0';
        //root->age = (rand() % 100) + 1;
        root->age = node_value;
        number_of_nodes++;
        return root;
    }
    
    int balance = get_depth_of_tree(root->left) - get_depth_of_tree(root->right);
    
    if (balance <= 0)
        root->left = insert_node_in_tree(root->left, node_value);
     else 
        root->right = insert_node_in_tree(root->right, node_value);

    return root;
}

int get_depth_of_a_tree_node_by_number(Fam_Tree *root,int value)
{
     if(root == NULL) 
        return -1;

    int dist = -1;

    if((root->age == value) ||
        (dist = get_depth_of_a_tree_node_by_number(root->left,value)) >= 0 ||
        (dist = get_depth_of_a_tree_node_by_number(root->right,value)) >= 0)
        return dist + 1;

    return dist;   
}

int get_depth_of_a_tree_node_by_name(Fam_Tree *root,char * string_for_search)
{
     if(root == NULL) 
        return -1;

    int dist = -1;

    if((strcmp(root->name,string_for_search) == 0) ||
        (dist = get_depth_of_a_tree_node_by_name(root->left,string_for_search)) >= 0 ||
        (dist = get_depth_of_a_tree_node_by_name(root->right,string_for_search)) >= 0)
        return dist + 1;

    return dist;   
}

void do_job()
{
    int option;
    Fam_Tree * root = NULL;
    srand(time(0));
    while(option != 0){
        
        show_menu();
        scanf("%d",&option);
        getchar();
        int node_value;
        int selection_for_case_7 = 0;
        char string_for_search[30];
        int value_to_find_depth;
        int value_to_find_height;
        int value_to_search;
        

        switch(option)
        {
            case 1:
            if(root == NULL)
            {
                printf("Introdu radacina(varsta celui mai mare membru):\n");
            }
            else
            {
                printf("Introdu valoarea nodului(varsta unui membru):\n");
            }
                scanf("%d",&node_value);
                root = insert_node_in_tree(root,node_value);
                printf("1.camp    2.camp:\n");
                inorder(root);
                printf("\n");
            break;

            case 2:
                printf("Arborele este:\n");
                inorder(root);
                printf("\n");
            break;

            case 3:
                printf("Parcurgerea in inordine a arborelui este:\n");
                inorder(root);
                printf("\n");
            break;

            case 4:
                printf("Parcurgerea in postordine a arborelui este:\n");
                postorder(root);
                printf("\n");
            break;

            case 5:
                printf("Parcurgerea in preordine a arborelui este:\n");
                preorder(root);
                printf("\n");
            break;

            case 6:
                printf("Adancimea arborelui este: %d\n", get_depth_of_tree(root));
            break;
            case 7:
            printf("1.Pentru a cauta numar(varsta)\n");
            printf("2.Pentru a cauta string(numele)\n");
            scanf("%d",&selection_for_case_7);
            getchar();

            if(selection_for_case_7 == 1)
            {
                printf("Introdu numar:\n");
                scanf("%d",&value_to_search);
                if(search_a_node_from_tree_by_number(root,value_to_search))
                    printf("Nodul a fost gasit\n");
                else
                    printf("Nodul nu exista in arbore\n");
            }
            else
            {
                printf("Introdu string:\n");
                strcpy(string_for_search,get_string(string_for_search));
                if(search_a_node_from_tree_by_name(root,string_for_search))
                    printf("Nodul a fost gasit\n");
                else
                    printf("Nodul nu exista in arbore\n");
            }
            break;

            case 8:
                printf("1.Numar\n");
                printf("2.String\n");
                scanf("%d",&selection_for_case_7);
                getchar();

                if(selection_for_case_7 == 1)
                {
                    printf("Introdu valoarea nodului:\n");
                    scanf("%d",&value_to_find_depth);
                    printf("Adancimea nodului '%d' este %d\n",value_to_find_depth,get_depth_of_a_tree_node_by_number(root,value_to_find_depth));
                }
                else
                {
                    printf("Introdu valoarea nodului:\n");
                    strcpy(string_for_search,get_string(string_for_search));
                    printf("Adancimea nodului '%s' este %d\n",string_for_search,get_depth_of_a_tree_node_by_name(root,string_for_search));
                }
            break;

            case 9:
                printf("1.Numar(varsta)\n");
                printf("2.String(nume)\n");
                scanf("%d",&selection_for_case_7);
                getchar();
                if(selection_for_case_7 == 1)
                {
                    printf("Introdu nodul:\n");
                    scanf("%d",&value_to_find_height);
                    printf("Inaltimea nodului '%d' este %d\n",value_to_find_height,height_of_a_node_by_number(root,value_to_find_height));
                }
                else
                {
                    printf("Introdu string:\n");
                    strcpy(string_for_search,get_string(string_for_search));
                    printf("Inaltimea nodului '%s' este %d\n",string_for_search,height_of_a_node_by_name(root,string_for_search));
                }
            break;

            case 10:
                printf("Frunzele arborelui sunt:\n");
                show_all_leafs(root);
                printf("\n");
            break;

            case 11:
                clean_tree(root);
            break;

            case 12:
                delete_all_nodes_from_tree(&root);
            break;

            case 13:
                printf("Aborele are %d noduri\n",total_number_of_nodes());
            break;
            case 0:
                delete_all_nodes_from_tree(&root);
                exit(0);
            break;
            default:
                printf("Hai ca poti!\n");
            }
    }

    delete_all_nodes_from_tree(&root);

}



int height_of_a_node_by_number(Fam_Tree * root,int value)
{
    if(root == NULL)
        return -1;

    return get_depth_of_tree(root) - get_depth_of_a_tree_node_by_number(root,value);
}

int height_of_a_node_by_name(Fam_Tree * root,char * string_for_search)
{
    if(root == NULL)
        return -1;

    return get_depth_of_tree(root) - get_depth_of_a_tree_node_by_name(root,string_for_search);
}

void inorder(Fam_Tree *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf(" %d\t", root->age);
        printf(" %s\n", root->name);
		inorder(root->right);
    }
}

void postorder(Fam_Tree *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf(" %d\t", root->age);
        printf(" %s\n", root->name);
    }
}

void preorder(Fam_Tree *root)
{
	if (root != NULL)
	{
		printf(" %d\t", root->age);
        printf(" %s\n", root->name);
		preorder(root->left);
		preorder(root->right);
    }
}


bool search_a_node_from_tree_by_number(Fam_Tree *root,int value) {
    if (root == NULL) {
        return false;
    }
    
    if (root->age == value) {
        return true; 
    }
    
    bool found_in_left_subtree = search_a_node_from_tree_by_number(root->left, value);
    bool found_in_right_subtree = search_a_node_from_tree_by_number(root->right, value);
    
    if (found_in_left_subtree || found_in_right_subtree) {
        return true;
    }
    
    return false;
}

bool search_a_node_from_tree_by_name(Fam_Tree *root,char * string_for_search) {
    if (root == NULL) {
        return false;
    }
    
    if (strcmp(root->name,string_for_search) == 0) {
        return true; 
    }
    
    bool found_in_left_subtree = search_a_node_from_tree_by_name(root->left,string_for_search);
    bool found_in_right_subtree = search_a_node_from_tree_by_name(root->right,string_for_search);
    
    if (found_in_left_subtree || found_in_right_subtree) {
        return true;
    }
    
    return false;
}

int total_number_of_nodes()
{
    return number_of_nodes;
}

char * get_string(char * str)
{
    fgets(str, 30, stdin);
    int str_length = 0;
    str_length = strlen(str);
    if(str_length > 0 && str[str_length - 1] == '\n')
    {
        str[str_length - 1] = '\0';
    }
    return str;
}

void delete_all_nodes_from_tree(Fam_Tree ** current_node)
{
	if(*current_node)
	{
		delete_all_nodes_from_tree(&(*current_node)->left);
		delete_all_nodes_from_tree(&(*current_node)->right);
		free(&(*current_node)->name);
        free(&(*current_node));
	}
    number_of_nodes = 0;
    *current_node = NULL;
}

void show_all_leafs(Fam_Tree * root)
{
    if(!root)
        return;

    if(!root->left && !root->right)
    {
        printf("%d ",root->age);
        printf("%s \n",root->name);
        return;
    }

    if(root->left)
        show_all_leafs(root->left);
    if(root->right)
            show_all_leafs(root->right);
}

void clean_tree(Fam_Tree * root)
{
    if (root != NULL)
	{
		clean_tree(root->left);
		root->age = 0;
        root->name = NULL;                                              
		clean_tree(root->right);
    }
}

void show_menu()
{
    printf("1. Introdu un nod in arbore     8.  Adancime nod dupa camp \n");
    printf("2. Afiseaza elementele          9.  Calculeaza inaltime nod\n");
    printf("3. Inordine                     10. Afiseaza toate frunzele\n");
	printf("4. Postordine                   11. Curata elementele arborelui\n");
	printf("5. Preordine                    12. Elibereaza memoria arborelui\n");
    printf("6. Adancime arbore              13. Numarul total de noduri\n");
    printf("7. Cauta nod dupa un camp\n");
    printf("0. Iesi din program\n");
}



