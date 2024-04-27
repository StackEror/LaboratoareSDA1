#include <stdio.h>
#define min(a,b) a > b ? b : a
void print_results(int w, int d, int s,int a);
void read_input_file(FILE * input1);

int main()
{
    FILE *input1 =  fopen("C:\\Users\\chicu\\OneDrive\\Desktop\\level1_2.in.txt","r");
    if(input1 == NULL)
    {
        printf("eroare\n");
    }

    read_input_file(input1);
    fclose(input1);
    return 0;
}
void print_results(int w, int d, int s,int a)
{
    printf("Number of W = %d\n",w);
    printf("Number of D = %d\n",d);
    printf("Number of S = %d\n",s);
    printf("Number of A = %d\n",a);

}
void read_input_file(FILE * input1)
{
    FILE * output1 = fopen("C:\\Users\\chicu\\OneDrive\\Desktop\\output2.txt","w");


    int nr_of_paths = 0;
    char direction;
    int store_W = 0;
    int store_D = 0;
    int store_S = 0;
    int store_A = 0;
    int height = 0;
    int width = 0;
    fscanf(input1,"%d",&nr_of_paths);
    while(fscanf(input1,"%c",&direction) != EOF)
    {   

        
        // height = 1;
        // width = 1;
        // if(direction == 'W' || direction == 'S')
        // {
        //     store_W = 0;
        //     store_D = 1;
        //     store_S = 0;
        //     store_A = 1;
        // }
        // if(direction == 'D' || direction == 'A')
        // {
        //     store_W = 1;
        //     store_D = 0;
        //     store_S = 1;
        //     store_A = 0;
        // }
            // direction = fgetc(input1);
            store_W = 0;
            store_D = 0;
            store_S = 0;
            store_A = 0;
            while (direction != '\n')
            {
                fscanf(input1,"%c",&direction);
                // direction = fgetc(input1);
                if(direction == 'W')
                {
                    store_W++;
                }
                if(direction == 'D')
                {
                    store_D++;
                }
                if(direction == 'S')
                {
                    store_S++;
                }
                if(direction == 'A')
                {
                    store_A++;
                }
                if(direction == '\n')
                {
                    // if(store_A != 0 || store_D == 0)
                    // {
                    //     width = store_D;
                    // }
                    // else if(store_A == 0 || store_D != 0)
                    // {
                    //     width = store_D;
                    // }
                    // else
                    // {
                    // }

                    // if(store_W != 0 || store_S == 0)
                    // {
                    //     height = store_W;
                    // }
                    // else if(store_W == 0 || store_S != 0)
                    // {
                    //     height = store_S;
                    // }
                    // else
                    // {
                    // }

                      
                    
                width = min(store_A,store_D);
                height = min(store_W,store_S);
                    // printf("%d %d\n",width,height);
                    fprintf(output1,"%d %d\n",width,height);
                    
                    break;
                    
                }
            }            
        
        

        
        // fprintf(output1,"%d %d %d %d\n",store_W,store_D,store_S,store_A);
        // printf("%d %d %d %d\n",store_W,store_D,store_S,store_A);
        // fflush(output1);

    }

    //print_results(store_W,store_D,store_S,store_A);
}