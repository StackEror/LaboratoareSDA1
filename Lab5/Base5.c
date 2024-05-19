#include "Lab5.h"


int main()
{
    srand(time(NULL));
    ull * array = NULL;
    int option;
    ull nr_of_elem = 0;
    
    while(option != 0)
    {
        show_menu();
        scanf("%d",&option);
        getchar();
        char fib[3][99999];
        double time_ms = 0;
        double time1 = 0;
        double time2 = 0;
        ull target = 0;
        int valid_search = 0;
        ull fibo_target = 0;
    
        switch(option)
        {
            case CREATE_ARRAY:
                printf("Introdu numarul de elemente din array:\n");
                scanf("%llu",&nr_of_elem);
                array = create_array_with_random_values(nr_of_elem);
            break;

            case 2:
                printf("Tabloul este:\n");
                print_array(array,nr_of_elem);
                printf("\n");
            break;

            case 3:
                printf("Tabloul sortat cu quick sort\n");
                time1 = clock();
                    quick_sort(array,0,nr_of_elem - 1);
                time2 = clock();
                // time_ms = (clock() - time1) / CLOCKS_PER_SEC;

                time_ms = (time2 - time1) / 1000;
                printf("\nTimpul de exeutie este %lf\n",time_ms);
            break;

            case 4:
                printf("Tabloul sortat cu selction sort\n");
                time1 = clock();
                    selection_sort(array,nr_of_elem);
                time2 = clock();

                time_ms = (time2 - time1) / 1000;
                printf("\nTimpul de exeutie este %lf\n",time_ms);
            break;

            case 5:
                free(array);
                array = NULL;
            break;

            case 6:
                printf("Introdu un numar de cautat\n");
                scanf("%d",&valid_search);
                time1 = clock();
                valid_search = linear_search(array,nr_of_elem,target);
                time2 = clock();

                if(valid_search != -1)
                    printf("Numarul %d a fost gasit\n",valid_search);
                else    
                    printf("Numarul %d nu a fost gasit\n",valid_search);

                time_ms = (time2 - time1) / 1000;
                printf("\nTimpul de exeutie este %lf\n",time_ms);
                

            break;

            case 7:
                printf("Introdu un numar de cautat\n");
                scanf("%d",&valid_search);
                time1 = clock();
                    valid_search = binary_search(array,0,nr_of_elem - 1,target);
                time2 = clock();

                if(valid_search != -1)
                    printf("Numarul %d a fost gasit\n",valid_search);
                else    
                    printf("Numarul %d nu a fost gasit\n",valid_search);

                time_ms = (time2 - time1) / 1000;
                printf("\nTimpul de exeutie este %lf\n",time_ms);
            break;

            case 8:
                
                strcpy(fib[0], "0");
                strcpy(fib[1], "1");
                int i;
                printf("Introdu care numar fibonaci sa afli\n");
                scanf("%d",&fibo_target);
                time1 = clock();
                    for (i = 2; i < fibo_target; i++) 
                    {
                        str_add(fib[2], fib[1], fib[0]);
                        strcpy(fib[0], fib[1]);
                        strcpy(fib[1], fib[2]);
                    }
                time2 = clock();

                printf("Fib(%d) = %s.\n", i, str_add(fib[2], fib[1], fib[0]));
                time_ms = (time2 - time1) / 1000;
                printf("\nTimpul de exeutie este %lf\n",time_ms);
            break;

            case 0:
                exit(0);
            break;

            default:
                printf("Hai ca poti!\n");
        }   
    }
    
    free(array);
    return 0;
}