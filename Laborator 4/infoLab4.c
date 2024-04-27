// for(int h = 0; h < total_number_of_nodes(root); h++)
// {
//     //printf(" %d ",tree_nodes[h]->key);
//     free(&(tree_nodes[h]));
// }

// if(tree_nodes[mid]->key < root->key)
// {
//     root->left = create_balance_tree(start,mid - 1,tree_nodes);
// }
// else
// {
//     root->right = create_balance_tree(start,mid - 1,tree_nodes);
// } 

// if(tree_nodes[mid]->key < root->key)
// {
//     root->left = create_balance_tree(mid + 1,end,tree_nodes);
// }
// else
// {
//     root->right = create_balance_tree(mid + 1,end,tree_nodes);
// } 

/*
    Debt * delete_node_from_tree(Debt * root, int value_to_del)
    {
        Debt * temp1;
        Debt * temp2;
        if(root == NULL)
        {
            return NULL;
        }
        else
        {
            if(root->key > value_to_del)
            {
                root->left = delete_node_from_tree(root->left,value_to_del);
            }
            else if(root->key < value_to_del)
            {
                root->right = delete_node_from_tree(root->right,value_to_del);
            }
            else
            {
                if(root->key == value_to_del)
                {
                    if (root->left == root->right)
                    {
                        free(root);
                        return NULL;
                    }
                    else if(root->left == NULL)
                    {
                        temp1 = root->right;
                        free(root);
                        return temp1;
                    }
                    else if (root->right == NULL)
                    {
                        temp1 = root->left;
                        free(root);
                        return temp1;
                    }
                    else
                    {
                        temp1 = root->right;
                        temp2 = root->right;
                        while (temp1->left != NULL)
                            temp1 = temp1->left;
                        temp1->left = root->left;
                        free(root);
                        return temp2;
                    }
                }
            }
        }
        
    }
*/


// printf("9. Elibereaza memoria arborelui\n");
// printf("10.Balanseaza arborele\n");
// printf("11.Afiseaza numarul de noduri\n");
// printf("12.Gaseste adancimea unui nod\n");
// printf("13.Oglindeste un arbore\n");
// printf("14.Printeaza arbore pe nivele\n");
// printf("15. Stere un nod din arbore dupa key\n");
// printf("0. Iesi din program\n");

// times_tab = height_of_tree - i;
// for(int k = 0; k < times_tab; k++)
// {
// }
// printf("Level %d:\n",i);