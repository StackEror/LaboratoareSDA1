#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
};

struct tree *introdu(struct tree *, int);
void inordine(struct tree *);
void postordine(struct tree *);
void preordine(struct tree *);
struct tree *sterge(struct tree *, int);
struct tree *cauta(struct tree *);
int inaltime(struct tree*);

int main()
{

	struct tree *radacina;
	int optiune, item, item_nu,nr_noduri=0;
	radacina = NULL;

	do
	{
		do
		{
			printf("\n \t 1. Introdu un nod in arbore  ");
			printf("\n\t 2. Sterge un nod din arbore  ");
			printf("\n\t 3. Parcurgerea in inordine a arborelui");
			printf("\n\t 4. Parcurgerea in postordine a arborelui");
			printf("\n\t 5. Parcurgerea in preordine a arborelui");
			printf("\n\t 6. Cauta si schimba valoarea unui nod ");
			printf("\n\t 7. Numarul total de noduri ");
			printf("\n\t 8. Inaltimea arborelui ");
			printf("\n\t 9. Iesire ");
			printf("\n\t Introdu optiunea : ");
			scanf(" %d", &optiune);
			if (optiune < 1 || optiune>9)
				printf("\n Optiune incorecta.Mai incearca");
		} while (optiune < 1 || optiune>9);
		

switch (optiune)
		{
		case 1:
			printf("\n Introdu un nou nod: ");
			scanf("%d", &item);
			radacina = introdu(radacina, item);
			printf("\n Radacina este %d", radacina->info);
			printf("\n Parcurgerea in inordine a arborelui este : ");
			nr_noduri++;
			inordine(radacina);
			break;
		case 2:
			printf("\n Introdu nodul care doresti sa fie sters : ");
			scanf(" %d", &item_nu);
			radacina = sterge(radacina, item_nu);
			nr_noduri--;
			inordine(radacina);
			break;
		case 3:
			printf("\n Parcurgerea in inordine a arborelui este : ");
			inordine(radacina);
			break;
		case 4:
			printf("\n Parcurgerea in postordine a arborelui este : ");
			postordine(radacina);
			break;
		case 5:
			printf("\n Parcurgerea in preordine a arborelui este : ");
			preordine(radacina);
			break;
		case 6:
			printf("\n Cauta si schimba valoarea unui nod ");
			radacina = cauta(radacina);
			break;
		case 7:
			printf("\n Numarul total de noduri este %d ",nr_noduri);
			inordine(radacina);
			break;
		case 8:
			printf("\n Inaltimea arborelui este %d ", inaltime(radacina));
			inordine(radacina);
			break;
		default:
			printf("\n Sfarsit ");
		}
	} while (optiune != 9);
	return 0;
}

struct tree *introdu(struct tree *radacina, int x)
{
	if (!radacina)
	{
		radacina = (struct tree*)malloc(sizeof(struct tree));
		radacina->info = x;
		radacina->left = NULL;
		radacina->right = NULL;
		return radacina;
	}
	if (radacina->info > x)
		radacina->left = introdu(radacina->left, x);
	else
	{
		if (radacina->info < x)
			radacina->right = introdu(radacina->right, x);
	}
	return radacina;
}


void inordine(struct tree *radacina)
{
	if (radacina != NULL)
	{
		inordine(radacina->left);
		printf(" %d", radacina->info);
		inordine(radacina->right);
	}
	return;
}

void postordine(struct tree *radacina)
{
	if (radacina != NULL)
	{
		postordine(radacina->left);
		postordine(radacina->right);
		printf(" %d", radacina->info);
	}
	return;
}

void preordine(struct tree *radacina)
{
	if (radacina != NULL)
	{
		printf(" %d", radacina->info);
		preordine(radacina->left);
		preordine(radacina->right);
	}
	return;
}
// 	{ 

struct tree *sterge(struct tree *ptr, int x)
{
	struct tree *p1, *p2;
	if (!ptr)
	{
		printf("\n Nodul nu a fost gasit ");
		return ptr;
	}
	else
	{
		if (ptr->info < x)
		{
			ptr->right = sterge(ptr->right, x);
		}
		else if (ptr->info > x)
		{
			ptr->left = sterge(ptr->left, x);
			return ptr;
		}
		else
		{
			if (ptr->info == x)
			{
				if (ptr->left == ptr->right)
				{
					free(ptr);
					return NULL;
				}
				else if (ptr->left == NULL)
				{
					p1 = ptr->right;
					free(ptr);
					return p1;
				}
				else if (ptr->right == NULL)
				{
					p1 = ptr->left;
					free(ptr);
					return p1;
				}
				else
				{
					p1 = ptr->right;
					p2 = ptr->right;
					while (p1->left != NULL)
						p1 = p1->left;
					p1->left = ptr->left;
					free(ptr);
					return p2;
				}
			}
		}
	}
	return(ptr);
}

struct tree *cauta(struct tree *radacina)
{
	int nu, i, inou;
	struct tree *ptr;
	ptr = radacina;
	printf("\n Introdu nodul cautat :");
	scanf(" %d", &nu);
	fflush(stdin);
	while (ptr)
	{
		if (nu > ptr->info)
			ptr = ptr->right;
		else if (nu < ptr->info)
			ptr = ptr->left;
		else
			break;
	}
	if (ptr)
	{
		printf("\n Nodul %d a fost gasit", nu);
		printf("\n Daca doresti sa-i schimbi valoarea tasteaza 1 : ");
		scanf(" %d", &i);
		if (i == 1)
		{
			printf("\n Introdu noua valoare :");
			scanf(" %d", &inou);
			ptr->info = inou;
		}
		else
			printf("\n\t Nu e nimic");
	}
	else
		printf("\n Nodul %d nu exista in arbore", nu);
	return radacina;
}
int inaltime(struct tree* radacina)
{
	if (radacina == NULL)
		return 0;
	else
	{
		int stang = inaltime(radacina->left);
		int drept = inaltime(radacina->right);
		if (stang > drept)
			return (stang+1);
		else 
			return (drept+1);
	}
}




// #define _CRT_SECURE_NO_WARNINGS
// #include<stdio.h>
// #include<conio.h>

// #define MAX 20

// struct muchie
// {
// 	int u;
// 	int v;
// 	int valoare;
// 	struct muchie *adresa;
// }*inceput=NULL;

// 	int parinte[MAX], nr_varfuri, pondere_arbore = 0, nr = 0;
// 	struct muchie arbore[MAX];

// 	void construieste_graf();
// 	void construieste_arbore();
// 	void introdu_arbore(int i, int j, int wt);
// 	void introdu(int i, int j, int wt);
// 	struct muchie *parcurgere();
	
// 	int main()
// 	{
// 		int i;

// 		construieste_graf();
// 		construieste_arbore();
// 		printf("Muchiile arborelui de cost minim:\n");
// 		for(i=1;i<=nr;i++)
// 		{ 
// 			printf("%d->",arbore[i].u); 
// 			printf("%d\n",arbore[i].v);
// 		} 
// 		printf("Valoarea costului minim: %d\n",pondere_arbore);
// 		return 0;
// 	}
// 	void construieste_graf()
// 	{
// 		int i,pondere,nr_max,origine,destinatie;

// 		printf("Introdu numarul de varfuri :");
// 		scanf("%d",&nr_varfuri);
// 		nr_max=nr_varfuri*(nr_varfuri-1)/2;
// 		for(i=0;i<=nr_max;i++)
// 		{ 
// 			printf("Introdu datele despre muchia %d origine->destinatie(0 0 pentru lipsa de date) :", i); 
// 			scanf("%d%d", &origine, &destinatie); 
// 			if ((origine == 0) && (destinatie == 0)) 
// 				break; 
// 			printf("Introdu ponderea acestei muchii :"); 
// 			scanf("%d", &pondere); 
// 			if (origine > nr_varfuri || destinatie > nr_varfuri || origine <= 0 || destinatie <= 0) 
// 			{ 
// 				printf("Muchie inexistenta!"); 
// 				i--; 
// 			}
// 			else 
// 				introdu(origine, destinatie, pondere); 
// 		}
// 		if (i < nr_varfuri - 1) 
// 		{ 
// 			printf("Imposibil de creat arbore de cost minim!"); 
// 			exit(1); 
// 		}
// 		return 0; 
// 	}
// 	void construieste_arbore() 
// 	{
// 		struct muchie *temp; 

// 		int nod1, nod2, radacina_1, radacina_2; 
// 		while (nr < nr_varfuri - 1) 
// 		{
// 			temp = parcurgere(); 
// 			nod1 = temp->u; 
// 			nod2 = temp->v;  
// 			while (nod1 > 0) 
// 			{ 
// 				radacina_1 = nod1; 
// 				nod1 = parinte[nod1]; 
// 			}
// 			while (nod2 > 0) 
// 			{ 
// 				radacina_2 = nod2; 
// 				nod2 = parinte[nod2]; 
// 			}  
// 			if (radacina_1 != radacina_2) 
// 			{
// 				introdu_arbore(temp->u, temp->v, temp->valoare); 
// 				pondere_arbore = pondere_arbore + temp->valoare; 
// 				parinte[radacina_2] = radacina_1;
// 			}
// 		}
// 	}
// 	void introdu_arbore(int i, int j, int pon) 
// 		nr++; 
// 		arbore[nr].u = i; 
// 		arbore[nr].v = j; 
// 		arbore[nr].valoare = pon; 
// 	}
// 	void introdu(int i, int j, int pon) 
// 	{ 
// 		struct muchie *temp, *q;

// 		temp = (struct muchie *)malloc(sizeof(struct muchie)); 
// 		temp->u = i; 
// 		temp->v = j; 
// 		temp->valoare = pon; 
// 		if (inceput == NULL || temp->valoare < inceput->valoare) 
// 		{ 
// 			temp->adresa = inceput; 
// 			inceput = temp; 
// 		} 
// 		else 
// 		{ 
// 			q = inceput; 
// 			while (q->adresa != NULL && q->adresa->valoare <= temp->valoare)
// 				q = q->adresa; 
// 			temp->adresa = q->adresa; 
// 			q->adresa = temp; 
// 			if (q->adresa == NULL)
// 				temp->adresa = NULL; 
// 		} 
// 	}
// 	struct muchie *parcurgere() 
// 	{ 
// 		struct muchie *temp; 

// 		temp = inceput; 
// 		inceput = inceput->adresa;
// 		return temp; 
// 	}
