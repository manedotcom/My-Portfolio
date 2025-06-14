#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>


int main() {
    printf("***WELCOME TO MINESWEEPER***\n\n");

    srand(time(0)); // Seed the random number generator

    int rows, columns, Bombs;

    // Get valid row size
    printf("Please Enter the Number of Rows: ");
    scanf("%d", &rows);
    while (rows < 9 || rows > 20) {
        textcolor(12);
        printf("The Number of Rows must be between 9 and 20.\n");
        textcolor(7);
        printf("Please Enter the Number of Rows: ");
        scanf("%d", &rows);
    }

    // Get valid column size
    printf("Please Enter the Number of Columns: ");
    scanf("%d", &columns);
    while (columns < 9 || columns > 20) {
        textcolor(12);
        printf("The Number of Columns must be between 9 and 20.\n");
        textcolor(7);
        printf("Please Enter the Number of Columns: ");
        scanf("%d", &columns);
    }

    // Get valid number of bombs
    printf("Please Enter the Number of Bombs: ");
    scanf("%d", &Bombs);
    while (Bombs < 10 || Bombs > 35) {
        textcolor(12);
        printf("The Number of Bombs must be between 10 and 35.\n");
        textcolor(7);
        printf("Please Enter the Number of Bombs: ");
        scanf("%d", &Bombs);
    }

    printf("\nNb of Rows: %d. Nb of Columns: %d. Nb of Bombs: %d.\n", rows, columns, Bombs);
    printf("\nStarting...\n");


typedef struct square {
        int num;
        bool aff;
        bool marked;
    } square;


    square board[rows][columns];

    // Initialize board with 0s
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j].num = 0;
            board[i][j].aff = false; //affiché
            board[i][j].marked = false;
        }
    }

    // Track bomb positions
    int ran1, ran2;
    int placed_bombs = 0;

    while (placed_bombs < Bombs) {
        ran1 = rand() % rows;  // Generate random row
        ran2 = rand() % columns; // Generate random column

        // If the spot is already occupied by a bomb, retry
        if (board[ran1][ran2].num == -1) {
            continue;
        }

        // Place bomb
        board[ran1][ran2].num = -1;
        placed_bombs++;
    }

    // Count bombs in the 3×3 neighborhood
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (board[i][j].num != -1) { // Only update if it's not a bomb
                // Check all surrounding cells (3×3 grid)
                for (int u = i - 1; u <= i + 1; u++) {
                    for (int v = j - 1; v <= j + 1; v++) {
                        // Ensure (u, v) is within bounds and is a bomb
                        if (u >= 0 && u < rows && v >= 0 && v < columns && board[u][v].num == -1) {
                            board[i][j].num++;
                        }
                    }
                }
            }
        }
    }

    int ran3 = rand() % rows;  // Generate random row
    int ran4 = rand() % columns; // Generate random column

    for (int u = ran3 - 2; u <= ran3 + 2; u++) {
        for (int v = ran4 - 2; v <= ran4 + 2; v++) {
            // Ensure (u, v) is within bounds and is a bomb
            if (u >= 0 && u < rows && v >= 0 && v < columns && board[u][v].num!=-1) {
                board[u][v].aff = true;
                //board[u][v].marked = true;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (board[i][j].aff && board[i][j].num == 0) { // Only displayed squares
                    // Check all surrounding cells (3×3 grid) if they are zeros
                    for (int u = i - 1; u <= i + 1; u++) {
                        for (int v = j - 1; v <= j + 1; v++) {
                            if (u >= 0 && u < rows && v >= 0 && v < columns && board[u][v].num == 0) {
                                //board[u][v].aff=true;
                                for (int w = i - 1; w <= i + 1; w++) {
                                    for (int z = j - 1; z <= j + 1; z++) {
                                        if (w >= 0 && w < rows && z >= 0 && z < columns) {
                                            board[w][z].aff=true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


    int x,y;

/*
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (board[i][j].aff) { // Only displayed squares
                // Check all surrounding cells (3×3 grid) if they are zeros
                for (int u = i - 1; u <= i + 1; u++) {
                    for (int v = j - 1; v <= j + 1; v++) {
                        if (u >= 0 && u < rows && v >= 0 && v < columns && board[u][v].num == 0) {
                            x=u;
                            y=v;
                            goto etiq;
                        }
                    }
                }
            }
        }
    }*/

    system("cls");
    printf("\nDisplaying Board:\n");
    for (int i = 0; i < rows; i++) {
        printf("%-2d |", i+1);
        for (int j = 0; j < columns; j++) {
            if (board[i][j].aff == false) {
                printf(" O "); // B for Bomb
            } else {
                if (board[i][j].marked){printf(" / ");}
                else {
                    if (board[i][j].num == 0){printf("   ");}
                    else {
                        textcolor(board[i][j].num);
                        printf(" %d ", board[i][j].num);
                        textcolor(7);
                    }
                }
            }
        }
        printf("\n");
    }
    printf("%-2s  ", " ");
    for (int i=1; i<columns+1;i++){printf("---");}
    printf("\n%-2s  ", " ");
    for (int i=1; i<columns+1;i++){
        if (i<10){printf(" %d ",i);}
        else {printf(" %d",i);}
    }

    bool mode=true; //true: reveal, false: mark
    bool lost=false;
    int marks=0;
    int not_marked=0;
    printf("\nEnter the coordinates of a square to mark it as a bomb or to reveal it.\n");
    printf("You can switch modes by entering '0'.\n");
    printf("It is on mode 'revealing' by default.");
    while(!lost){
        if (mode){
            textcolor(13);
            printf("\n'Reveal'\n");
            textcolor(7);
        } else {textcolor(14);printf("\n'Mark'\n");textcolor(7);}
        printf("Enter the row (from 1 to %d): ", rows);
        scanf("%d", &x);
        while (x<0 || x>rows){
            textcolor(12);
            printf("Row must be from 1 to %d!\n", rows);
            textcolor(7);
            printf("Enter the row (from 1 to %d): ", rows);
            scanf("%d", &x);
        }
        if (x==0){mode=!mode;continue;}

        printf("Enter the column (from 1 to %d): ", columns);
        scanf("%d", &y);
        while (y<0 || y>columns){
            textcolor(12);
            printf("Column must be from 1 to %d!\n", columns);
            textcolor(7);
            printf("Enter the column (from 1 to %d): ", columns);
            scanf("%d", &y);
        }
        if (y==0){mode=!mode;continue;}

        x--;
        y--;
        //board[x][y].aff=true;
        if (mode){ // reveal mode
            if (board[x][y].aff){
                    etiq:
                for (int u = x - 1; u <= x + 1; u++) {
                    for (int v = y - 1; v <= y + 1; v++) {
                        if (u >= 0 && u < rows && v >= 0 && v < columns && !board[u][v].marked) {
                            if(board[u][v].num==-1){lost=true; goto end_of_game;}
                            else {board[u][v].aff=true;}
                        }
                    }
                }
            }
            board[x][y].aff=true;
            if (board[x][y].marked){board[x][y].marked=false;}
            if(board[x][y].num==-1){
                end_of_game :
                textcolor(12);
                printf("YOU LOST :( ");
                textcolor(7);
                printf("Better luck next time.");
                lost=true;
                break;
            }
        } else { // mark mode
            board[x][y].aff=true;
            if (!board[x][y].marked){board[x][y].marked=true; marks++;} // it's not already marked
            else {board[x][y].marked=false; board[x][y].aff=false; marks--;} // already marked
        }


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (board[i][j].aff && board[i][j].num == 0) { // Only displayed squares
                    // Check all surrounding cells (3×3 grid) if they are zeros
                    for (int u = i - 1; u <= i + 1; u++) {
                        for (int v = j - 1; v <= j + 1; v++) {
                            if (u >= 0 && u < rows && v >= 0 && v < columns && board[u][v].num == 0) {
                                //board[u][v].aff=true;
                                for (int w = i - 1; w <= i + 1; w++) {
                                    for (int z = j - 1; z <= j + 1; z++) {
                                        if (w >= 0 && w < rows && z >= 0 && z < columns) {
                                            board[w][z].aff=true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
/*
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (board[i][j].aff) { // Only displayed squares
                    // Check all surrounding cells (3×3 grid) if they are zeros
                    for (int u = i - 1; u <= i + 1; u++) {
                        for (int v = j - 1; v <= j + 1; v++) {
                            if (u >= 0 && u < rows && v >= 0 && v < columns && board[u][v].num == 0) {
                                x=u;
                                y=v;
                                goto etiq;
                            }
                        }
                    }
                }
            }
        }*/

        system("cls");
        printf("\nDisplaying Board:\n");
        for (int i = 0; i < rows; i++) {
            printf("%-2d |", i+1);
            for (int j = 0; j < columns; j++) {
                if (board[i][j].aff == false) {
                    printf(" O "); // B for Bomb
                } else {
                    if (board[i][j].marked){printf(" / ");}
                    else {
                        if (board[i][j].num == 0){printf("   ");}
                        else {
                            textcolor(board[i][j].num);
                            printf(" %d ", board[i][j].num);
                            textcolor(7);
                        }
                    }
                }
            }
            printf("\n");
        }
        printf("%-2s  ", " ");
        for (int i=1; i<columns+1;i++){printf("---");}
        printf("\n%-2s  ", " ");
        for (int i=1; i<columns+1;i++){
            if (i<10){printf(" %d ",i);}
            else {printf(" %d",i);}
        }

        not_marked=0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if(board[i][j].marked == false){not_marked++;}
            }
        }

        if (marks==Bombs && not_marked==(rows*columns - Bombs)){
            textcolor(10);
            printf("\nYOU WIN!!!\n");
            textcolor(7);
            break;}
    }

    return 0;
}

void textcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
