#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define swap(x, y) { void* tmp = x; x = y; y = tmp; }

typedef struct Debt
{
    int age; 
    char *name;
    float sum_to_give;
    int key;
    struct Debt * left;
    struct Debt * right;
}Debt; 


typedef struct Binary_Tree
{
    Debt * root;
}Binary_Tree;

typedef struct Queue
{
    Debt * tree_node;
    struct Queue * next;
}Queue;

typedef struct Head_refr
{
    Queue * front, *rear;
}Head_refr;

void do_job();

Debt * create_tree_node(int node_value);
Debt *insert_node_in_tree(Debt **root, int node_value);

char * get_rand_string();
char * get_string(char * str);

void print_tree_inorder(Debt * root);
void print_tree_postorder(Debt * root);
void print_tree_preorder(Debt * root);
void DFS(Debt * root);
void BFS(Debt * root);

Queue * create_new_queue_node(Debt * node);
void add_to_queue(Head_refr * q_head,Debt * node);
Debt * remove_from_queue(Head_refr * q_head);

Debt ** get_tree_to_array(Debt * root,Debt ** tree_nodes,int * i);
Debt ** create_array_to_store_tree(Debt * root,int * nr_of_nodes);
Debt * create_balance_tree(int start,int end,Debt ** tree_nodes);

int total_number_of_nodes(Debt * root);

int get_depth_of_a_tree_node_by_number(Debt *root,int value);
bool search_a_node_from_tree_by_number(Debt * root,int value);

void reflect_tree(Debt ** root);
void delete_all_nodes_from_tree(Debt ** current_node);
void show_menu();

void print_level_order(Debt * root);
void print_current_level(Debt * root,int current_level);
int height(Debt * root);