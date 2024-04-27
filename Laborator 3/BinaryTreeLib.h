#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct Fam_Tree
{
    int age; 
    char *name;
    struct Fam_Tree * left;
    struct Fam_Tree * right;
}Fam_Tree; 

typedef struct Binary_Tree{
    Fam_Tree * root;
}Binary_Tree;

int get_depth_of_tree(Fam_Tree *root);
Fam_Tree *insert_node_in_tree(Fam_Tree *root, int node_value);
void do_job();
int get_depth_of_a_tree_node_by_number(Fam_Tree *root,int value);
int get_depth_of_a_tree_node_by_name(Fam_Tree *root,char * string_for_search);
int height_of_a_node_by_number(Fam_Tree * root,int value);
int height_of_a_node_by_name(Fam_Tree * root,char * string_for_search);
void inorder(Fam_Tree * root);
void postorder(Fam_Tree * root);
void preorder(Fam_Tree * root);
bool search_a_node_from_tree_by_number(Fam_Tree * root,int value);
bool search_a_node_from_tree_by_name(Fam_Tree * root,char * string_for_search);
int total_number_of_nodes();
char * get_string(char * str);
void delete_all_nodes_from_tree(Fam_Tree ** current_node);
void show_all_leafs(Fam_Tree * root);
void clean_tree(Fam_Tree * root);
void show_menu();
