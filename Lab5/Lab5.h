#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

enum options {INIT_ARRAY = 1,PRINT_ARRAY = 2,SORT_FAST = 3,SORT_SLOW = 4,
                FREE_ARRAY = 5,LINEAR_SEARCH = 6,BINARY_SEARCH = 7,COMPUTE_FIBONACI = 8,EXIT = 0};
                
typedef unsigned long long ull;
ull * create_array_with_random_values(ull nr_of_elem);
void selection_sort(ull a[],ull length);
ull get_index_max(ull a[], ull length);
void print_array(ull * array,ull nr_of_elem);
void swap(ull *a, ull *b);
ull partition(ull a[], ull start, ull end);
void quick_sort(ull a[], ull start, ull end);
char *str_revese_inplace(char *s);
char *str_add(char *final_sum, const char *str_first_nr, const char *string_second_nr);
int linear_search(ull arr[], int nr_of_elem, int taret_nr);
int binary_search(ull arr[], int start, int end, int target);
void show_menu();