#include "BST.h"

static const char alfabet[] = "abc";
// "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
unsigned int number_of_nodes = 0;

Debt * create_tree_node(int node_value)
{
    Debt * node = (Debt*)calloc(1,sizeof(Debt));
    node->name = get_rand_string();
    node->age = (rand() % 100) + 1;
    node->key = node_value;
    node->sum_to_give = (rand() % 10000) + 1000;
    return node;
}

Debt *insert_node_in_tree(Debt **root, int node_value)
{
    Debt * node = *root; 
    if (*root == NULL)
    {
        node = create_tree_node(node_value);
        return node;
    }
    if (node_value < node->key)
        node->left = insert_node_in_tree(&node->left, node_value);
     else 
        node->right = insert_node_in_tree(&node->right, node_value);

    return node;
}
Debt* delete_node_from_tree(Debt *root, int val_to_del)
{
    if (root == NULL)
        return NULL;

    if (val_to_del < root->key)
        root->left = delete_node_from_tree (root->left, val_to_del);

    else if (val_to_del > root->key)
        root->right = delete_node_from_tree (root->right, val_to_del);

    else
    {
        // frunza
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // 1 copil
        else if (root->left == NULL || root->right == NULL)
        {
            Debt *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        // 2 copii
        else if (root->left != NULL && root->right != NULL)
        {
            Debt *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left; //pleaca pana la cel mai kic element din subarborele drept (primul mai mare ca radacina)
            }
            root->key = temp->key;  //atriubuie elementului de sters elementul (primul mai mare ca radacina)
            root->right = delete_node_from_tree(root->right, root->key);//elimina (primul mai mare ca radacina) de jos
        }
    }
    return root;
}

void do_job()
{
    int option;
    Debt * root = NULL;
    Debt ** tree_nodes;
    Debt * new_root = NULL;
    srand(time(0));
    while(option != 0)
    {
        show_menu();
        scanf("%d",&option);
        getchar();
        int node_value;
        int value_to_search;
        int nr_of_tree_nodes = 0;
        int nr_of_nodes;
        int node_depth = 0;
        int value_to_delete;
        bool node_found;
    
        switch(option)
        {
            case 1:
            if(root == NULL)
            {
                // printf("Introdu radacina:\n");
            }
            else
            {
                // printf("Introdu valoarea nodului:\n");
            }
                // scanf("%d",&node_value);
                node_value = (rand() % 100) + 1;
                root = insert_node_in_tree(&root,node_value);
                printf("Arborele este:\n");
                print_tree_inorder(root);
                printf("\n");
            break;

            case 2:
                printf("Arborele este:\n");
                print_tree_inorder(root);
                printf("\n");
            break;

            case 3:
                printf("Parcurgerea in inordine a arborelui este:\n");
                print_tree_inorder(root);
                printf("\n");
            break;

            case 4:
                printf("Parcurgerea in postordine a arborelui este:\n");
                print_tree_postorder(root);
                printf("\n");
            break;

            case 5:
                printf("Parcurgerea in preordine a arborelui este:\n");
                print_tree_preorder(root);
                printf("\n");
            break;

            case 6:
                printf("Parcuregerea DFS:\n");
                DFS(root);
                printf("\n");
            break;
            case 7:
                printf("Parcurgerea BFS:\n");
                BFS(root);
                printf("\n");
            break;

            case 8:
                printf("Introdu numar(key) pentu a cauta datoria:\n");
                scanf("%d",&value_to_search);

                node_found = search_a_node_from_tree_by_number(root,value_to_search);

                if(node_found == false)
                    printf("Nodul '%d' nu exista in arbore\n",value_to_search);
                else
                    printf("Nodul '%d' a fost gasit la adancimea %d\n",value_to_search,
                    get_depth_of_a_tree_node_by_number(root,value_to_search));
            break;

            case 9:
                delete_all_nodes_from_tree(&root);
            break;

            case 10:
                number_of_nodes = 0;
                nr_of_tree_nodes = total_number_of_nodes(root);
                tree_nodes = create_array_to_store_tree(root,&nr_of_nodes);
                delete_all_nodes_from_tree(&root);
                new_root = create_balance_tree(0,nr_of_tree_nodes - 1,tree_nodes);
                root = new_root;
                printf("Arborele balansat este\n");
                print_tree_postorder(root);
                printf("\n");
            break;

            case 11:
                number_of_nodes = 0;    
                printf("Numarul de noduri in arbore este %d\n",total_number_of_nodes(root));
            break;

            case 12:
                printf("Introdu valoarea:\n");  
                scanf("%d",&value_to_search);
                node_depth = get_depth_of_a_tree_node_by_number(root,value_to_search);
                if(node_depth == -1)
                    printf("Nodul '%d' nu exista\n",value_to_search);
                else
                    printf("Adancimea lui '%d' este %d\n",value_to_search,node_depth);
            break;

            case 13:
                printf("Arborele pana la oglindire:\n");
                print_tree_inorder(root);
                reflect_tree(&root);
                printf("\n");
                printf("Arborele dupa oglindire:\n");
                print_tree_inorder(root);
                printf("\n");
            break;

            case 14:
                printf("Afisarea grafica a arborelui pe nivele");
                print_level_order(root);
            break;

            case 15:
                printf("Alege un node dde stergere:\n");
                scanf("%d",&value_to_delete);
                delete_node_from_tree(root,value_to_delete);
                printf("Inorder\n");
                print_tree_inorder(root);
                printf("\n");
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


void reflect_tree(Debt ** tree)
{
  if(!*tree) 
    return;

    reflect_tree(&(*tree)->left);
    reflect_tree(&(*tree)->right);
    swap((*tree)->left, (*tree)->right);
}

Debt ** create_array_to_store_tree(Debt * root,int * nr_of_nodes)
{
    number_of_nodes = 0;
    *nr_of_nodes = total_number_of_nodes(root);
    Debt ** tree_nodes = (Debt**)calloc(*nr_of_nodes,sizeof(Debt*));
    int i = 0;
    return get_tree_to_array(root,tree_nodes,&i);
}

Debt ** get_tree_to_array(Debt * root,Debt ** tree_nodes,int * i)
{
    if(root == NULL)
        return tree_nodes;

    tree_nodes = get_tree_to_array(root->left,tree_nodes,i);
    tree_nodes[*i] = root;
    (*i)++;
    tree_nodes = get_tree_to_array(root->right,tree_nodes,i);

    return tree_nodes;
}

Debt * create_balance_tree(int start,int end,Debt ** tree_nodes)
{
    if(start > end)
        return NULL;

    int mid = (start + end) / 2;
    Debt * root = tree_nodes[mid];
    root->left = create_balance_tree(start,mid - 1,tree_nodes);
    root->right = create_balance_tree(mid + 1,end,tree_nodes);
    
    return root;
}

void print_tree_inorder(Debt *root)
{
	if (root != NULL)
	{
		print_tree_inorder(root->left);
		printf(" %d ", root->key);
		print_tree_inorder(root->right);
    }
}

void print_tree_postorder(Debt *root)
{
	if (root != NULL)
	{
		print_tree_postorder(root->left);
		print_tree_postorder(root->right);
		printf(" %d ", root->key);
    }
}

void print_tree_preorder(Debt *root)
{
	if (root != NULL)
	{
		printf(" %d ", root->key);
		print_tree_preorder(root->left);
		print_tree_preorder(root->right);
    }
}

void DFS(Debt * root)
{
    if (root != NULL)
	{
		printf(" %d ", root->key);
		print_tree_preorder(root->left);
		print_tree_preorder(root->right);
    }
}

void BFS(Debt * root)
{
    if(root == NULL)
    {
        printf("Radacina nu exista\n");
        return;
    }
    Head_refr * queue = (Head_refr*)malloc(sizeof(Head_refr));
    queue->front = NULL;
    queue->rear = NULL;
    add_to_queue(queue,root);
    while(queue->front)
    {
        Debt * node = remove_from_queue(queue);
        printf(" %d ",node->key);
        if(node->left)
        {
            add_to_queue(queue,node->left);
        }
        if(node->right)
        {
            add_to_queue(queue,node->right);
        }
    }

    free(queue);
    printf("\n");
}



void print_current_level(Debt * root,int current_level)
{
    if(root == NULL)
        return;

    if(current_level == 1)
    {
        printf(" %d ",root->key);
    }
    else if(current_level > 1)
    {
        print_current_level(root->left,current_level - 1);
        print_current_level(root->right,current_level - 1);
    }
}

void print_level_order(Debt * root)
{
    printf("\n");
    int height_of_tree = height(root);
    int i;
    int times_tab = height_of_tree;
    printf("\t\t\t");
    for(i = 1; i <= height_of_tree; i++)
    {
        print_current_level(root,i);
        printf("\n");
    }
}
int height(Debt * root)
{
    if(root == NULL)
        return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        if(lheight > rheight)
        {
            return(lheight + 1);    
        }
        else{
            return (rheight + 1);
        }
    
    }
}

Queue * create_new_queue_node(Debt * node)
{
    Queue * new_node = calloc(1,sizeof(Queue));
    new_node->tree_node = node;
    return new_node;
}
void add_to_queue(Head_refr * queue,Debt * node)
{
    Queue * temp_node = create_new_queue_node(node);
    if(queue->rear == NULL)
    {
        queue->front = temp_node;   //inceputul listei
        queue->rear = temp_node;    //sfarsitul listei
        return;
    }
    queue->rear->next = temp_node;
    queue->rear = temp_node;
}
Debt * remove_from_queue(Head_refr * queue)
{
    if(queue->front == NULL)
        return NULL;

    Queue * temp = queue->front;        //nodul sa scos din lista
    Debt * data = temp->tree_node;
    queue->front = queue->front->next;

    if(queue->front == NULL)
    {
        queue->rear = NULL;
        queue = NULL;
    }
    free(temp);
    return data;
}

bool search_a_node_from_tree_by_number(Debt *root,int value) {
    if (root == NULL)
    {
        return false;
    }
    
    if (root->key == value)
    {
        system("cls");
        printf("age_of_victim = %d\nname_of_victim = %s\nkey = %d\ndebt_to_give = %.2f\n",
        root->age,
        root->name,
        root->key,
        root->sum_to_give);
        return true; 
    }

    if(value < root->key)
    {
       return search_a_node_from_tree_by_number(root->left, value);
    }
    else
    {
       return search_a_node_from_tree_by_number(root->right, value);
    }
}

int get_depth_of_a_tree_node_by_number(Debt *root,int value)
{
     if(root == NULL) 
        return -1;

    int dist = -1;

    if((root->key == value) ||
        (dist = get_depth_of_a_tree_node_by_number(root->left,value)) >= 0 ||
        (dist = get_depth_of_a_tree_node_by_number(root->right,value)) >= 0)
        return dist + 1;

    return dist;   
}

int total_number_of_nodes(Debt * root)
{
    if(root)
    {
        number_of_nodes++;
        total_number_of_nodes(root->left);
        total_number_of_nodes(root->right);
    }
    return number_of_nodes;
}

char * get_rand_string()
{
    int len = (rand() % 5) + 1;
    char * string =(char*)calloc(len + 1,sizeof(char));
    for (int i = 0; i < len; i++)
    {
        string[i] = alfabet[rand() % (sizeof(alfabet) - 1)];
    }
    string[len] = '\0';
    return string;
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

void delete_all_nodes_from_tree(Debt ** current_node)
{
	if(*current_node)
	{
		delete_all_nodes_from_tree(&(*current_node)->left);
		delete_all_nodes_from_tree(&(*current_node)->right);
		free(&(*current_node)->name);
        free(&(*current_node));
	}
    *current_node = NULL;
}

void show_menu()
{
    printf("1. Introdu un nod in arbore     9.  Elibereaza memoria arborelui\n");
    printf("2. Afiseaza elementele          10. Balanseaza arborele\n");
    printf("3. Inordine                     11. Afiseaza numarul de noduri\n");
	printf("4. Postordine                   12. Gaseste adancimea unui nod\n");
	printf("5. Preordine                    13. Oglindeste un arbore\n");
    printf("6. DFS                          14. Printeaza arbore pe nivele\n");
    printf("7. BFS                          15. Sterge un nod din arbore dupa key\n" );
    printf("8. Cauta nod dupa key           0. Iesi din program\n");
}
