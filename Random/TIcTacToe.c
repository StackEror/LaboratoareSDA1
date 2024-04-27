#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#define FIRST_PLAYER  'X'
#define SECOND_PLAYER 'O'
void draw_board();
bool is_cell_free(int cell);
int char_to_int(char choice);
void place_token(int cell);
void change_player();
bool check_game_over(); 
bool is_row_win();
bool is_col_win();
bool is_diag_win();
bool is_full();

char g_board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};
char g_player = FIRST_PLAYER;

int main()
{
    bool is_game_over = false;
    char choice;
    int cell;

    do{
        draw_board();
        printf("%c Alege celula: \n",g_player);
        choice = getch();

        cell = char_to_int(choice) - 1;

        if(is_cell_free(cell)) //daca celula este libera plasam
        {
            place_token(cell);
            draw_board();
            
            is_game_over = check_game_over(); 
            
            change_player();
        }

    

    }while(!is_game_over);

    printf("Sfarsitul jocului\n");

    return 0;
}

bool check_game_over()
{
    bool is_over;

    return is_over = is_row_win() || is_col_win()  || is_diag_win() || is_full();
    
    
}
bool is_row_win()
{
    int i;

    for(i = 0; i < 3; i++)
    {
        if( g_board[i][0] == g_board[i][1] &&
            g_board[i][1] == g_board[i][2])
            {
                printf("%c a castigat pe randul %d\n",g_player, i + 1);
                return true;
            }
    }

    return false;
}

bool is_col_win()
{
    int i;

    for(i = 0; i < 3; i++)
    {
        if( g_board[0][i] == g_board[1][i] &&
            g_board[1][i] == g_board[2][i])
            {
                printf("%c a castigat pe coloana %d\n",g_player, i + 1);
                return true;
            }
    }

    return false;
}

bool is_diag_win()
{
    int i;

    if( g_board[0][0] == g_board[1][1] &&
        g_board[1][1] == g_board[2][2])
    {
        printf("%c a castigat pe diagonala principala\n",g_player);
        return true;
    }

    if( g_board[0][2] == g_board[1][1] &&
        g_board[1][1] == g_board[2][0])
    {
        printf("%c a castigat pe diagonala secundara\n",g_player);
        return true;
    }
        


    return false;
}

bool is_full()
{
    int i,j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(g_board[i][j] != FIRST_PLAYER && g_board[i][j] != SECOND_PLAYER)
                return false;
        }
    }
    return true;
}

bool is_cell_free(int cell)
{
    int row = cell / 3;
    int col = cell % 3;
    bool is_free  = g_board[row][col] != FIRST_PLAYER && g_board[row][col] != SECOND_PLAYER;

    return is_free;
}


void place_token(int cell)
{
    int row = cell / 3;
    int col = cell % 3;
    g_board[row][col] = g_player;
}

int char_to_int(char choice)
{
    return choice - 48;   
}


void change_player()
{
    g_player = (g_player == FIRST_PLAYER) ? SECOND_PLAYER : FIRST_PLAYER;
}




void draw_board()
{
    system("cls");

    printf("\n");

    printf("   |   |   \n");
    printf(" %c | %c | %c \n",g_board[0][0],g_board[0][1],g_board[0][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",g_board[1][0],g_board[1][1],g_board[1][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",g_board[2][0],g_board[2][1],g_board[2][2]);
    printf("   |   |   \n");

    printf("\n");
}








