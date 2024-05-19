#include "Lab5.h"

int linear_search(ull arr[], int nr_of_elem, int taret_nr)
{
    for (int i = 0; i < nr_of_elem; i++)
    {
        if (arr[i] == taret_nr)
            return i;
    }
    return -1;
}

int binary_search(ull arr[], int start, int end, int target)
{
    if (end >= start) 
    {
        int mid = start + (end - start) / 2;
       
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binary_search(arr, start, mid - 1, target);

        return binary_search(arr, mid + 1, end, target);
    }

    return -1;
}


ull * create_array_with_random_values(ull nr_of_elem)
{
    ull * arr = (ull*)malloc(nr_of_elem * sizeof(ull));
    for(ull i = 0; i < nr_of_elem; i++)
    {
        /*arr[i] = (rand() % ULLONG_MAX) + 1;*/
        arr[i] = rand();
    }
    printf("\n");
    return arr;
}

    //SELECTION SORT
ull get_index_max(ull a[], ull length)
{
    ull index_max, max;

    index_max = 0;
    max = a[0];
    
    for (ull i = 1; i < length; i++) 
    {
        if(a[i] > max)
        {
        max = a[i];
        index_max = i;
        }
    }

    return index_max;
}

void selection_sort(ull a[],ull length)
{                                     
    ull index_max,temp;

    for (ull i = 0; i < length - 1; i++)
    {
        index_max = get_index_max(a,length - i);
        
        temp = a[index_max];
        a[index_max] = a[length - 1 - i];
        a[length - 1 - i] = temp;
    }
    
}

    //QUICK SORT
void swap(ull *a, ull *b)
{
    ull temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

ull partition(ull a[], ull start, ull end)
{
    ull part_index = start; 
    ull pivot = a[end];
    ull i = start;
    
    for(i = start; i <= end - 1; i++)
    {
        if(a[i] <= pivot)
        {
            swap(&a[i],&a[part_index]);
            part_index++;   
        }                 
    } 
        swap(&a[end],&a[part_index]);      
        return part_index;
}

void quick_sort(ull a[], ull start, ull end)
{
    ull piv_index;
    if(start < end)
    {
        piv_index = partition(a,start,end);
        quick_sort(a,start,piv_index - 1);
        quick_sort(a,piv_index + 1,end);
    }     
}

void print_array(ull * array,ull nr_of_elem)
{
    for(ull i = 0; i < nr_of_elem; i++)
    {
        printf("%llu ",array[i]);
    }
}

char *str_revese_inplace(char *string) 
{
  char *left = string;
  char *right = string + strlen(string);
  while (right > left) 
  {
    right--;
    char temp = *right;
    *right = *left;
    *left = temp;
    left++;
  }
  return string;
}

char *str_add(char *final_sum, const char *str_first_nr, const char *string_second_nr) 
{
  const char *ptr_first_nr = str_first_nr + strlen(str_first_nr);
  const char *ptr_second_nr = string_second_nr + strlen(string_second_nr);
  char *temp_ptr_sum = final_sum;
  int reminder = 0;
  while (ptr_first_nr > str_first_nr || ptr_second_nr > string_second_nr || reminder) 
  {
    int sum = reminder;
    if (ptr_first_nr > str_first_nr) 
        sum += *(--ptr_first_nr) - '0';
    if (ptr_second_nr > string_second_nr) 
        sum += *(--ptr_second_nr) - '0';

    *temp_ptr_sum++ = sum % 10 + '0';
    reminder = sum / 10;
  }

  *temp_ptr_sum = '\0';
  return str_revese_inplace(final_sum);
}


void show_menu()
{
    printf("1. Initializare tabloul cu numere aleatoare\n");
    printf("2. Afiseaza tabloul\n");
    printf("3. Sorteaza rapid\n");
    printf("4. Sorteaza nu rapid\n");
    printf("5. Elibereaza memorie tablou\n");
    printf("6. Cauta un numar cu linear search\n");
    printf("7. Cauta un numar cu binary search\n");
    printf("8. Calculeaza numar fibonaci\n");
    printf("0. Exit\n");
}