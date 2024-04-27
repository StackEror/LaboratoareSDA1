#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define min(a,b) a > b ? b : a

// (...) inseamna ca avem lista de argumente variabile (variadice)
// (...) este un token numit "ellipsis" definit pentru a deini un numar variabil de argumente in macrouri
//__VA_ARGS__ este o extensie a standardului folosita pentu definirea macrourilor variadice
//

#define PRINT_SOME(...) printf(__VA_ARGS__);


int main()
{
	//PRINT_SOME("%d %d %d",10,20,30);
	// int c;
	// // srand(time(NULL));
	// // for(int i = 0; i < 10; i++)
	// // {
	// // 	c = rand() % 2; 
	// // 	printf("%d ",c);
	// // }
	// clock_t ms1,ms2;

	// ms1 = clock();

	// for(int i = 0; i < 9999999; i++)
	// {
	// 	// if(i == i) break;
	// 	int a;
	// 	a+=a;
	// }
	// ms2 = clock();
	// double timp = ms2 - ms1;
	// printf("Timpul de executie este %lf",timp);

	// int d;
	// int c;

	// scanf("%d %d",&d, &c);

	int h;
	int a = 10;
	int b = 7;
	h = (a < b) ? b : a;
	printf("Minimul este %d",h);

	


	return 0;
}

/*#include <stdio.h>

// Macro pentru afișarea unei liste de elemente
#define PRINT_LIST(...) \
    do { \
        printf("Elemente: "); \
        printf(__VA_ARGS__); \
        printf("\n"); \
    } while(0)

int main() {
    // Utilizare a macro-ului pentru afișarea unei liste de elemente
    PRINT_LIST("%d %d %d", 10, 20, 30);
    PRINT_LIST("%c %c %c", 'a', 'b', 'c');
    
    return 0;
}*/