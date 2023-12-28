#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkwin(int grid[])
{
//check rows
    if((grid[1] == grid[2]) && (grid[2] == grid[3]) && (grid[3] != 0))
        return 1;

    if((grid[4] == grid[5]) && (grid[5] == grid[6]) && (grid[5] != 0))
        return 1;

    if((grid[7] == grid[8]) && (grid[8] == grid[9]) && (grid[8] != 0))
        return 1;
//check columns
    if((grid[1] == grid[4]) && (grid[4] == grid[7]) && (grid[4] != 0))
        return 1;

    if((grid[2] == grid[5]) && (grid[5] == grid[8]) && (grid[5] != 0))
        return 1;

    if((grid[3] == grid[6]) && (grid[6] == grid[9]) && (grid[6] != 0))
        return 1;

//check diagonals
    if((grid[1] == grid[5]) && (grid[1] == grid[9]) && (grid[1] != 0))
        return 1;

    if((grid[3] == grid[5]) && (grid[3] == grid[7]) && (grid[3] != 0))
        return 1;

    return 0;
}


int main()
{
    char protocol[30];
    FILE *inFile = fopen("desas.in","r+");
    int gar = 0;
    fscanf(inFile,"%s",protocol);
    gar = strlen(protocol);
    fclose(inFile);




    FILE *outFile = fopen("desas.out","w+");
    //check for invalid protocol length
    if(gar > 9)
    {
        fprintf(outFile,"NEKOREKTS");
        fclose(outFile);
        return 0;
    }

    // Validation against incorrect symbols
    int i,j;
    char c;
    int mas[10] ={0};
    for(i = 0 ; i < gar; i++)
    {
        c = protocol[i];
        if ((c-48 < 1)|| (c-48 > 9))
        {
            fprintf(outFile,"NEKOREKTS");
            fclose(outFile);
            return 0;
        }
        else
        {
            mas[i] = c-48;
        }
    }

    //check for repetitive moves
    for(i = 0 ; i < gar-1; i++)
    {

        for(j = i+1; j < gar; j++)
        {
            if(mas[i]==mas[j])
            {
                fprintf(outFile,"NEKOREKTS");
                fclose(outFile);
                return 0;
            }
        }
    }

    //check if there is a winner ? And if they kept playing after someone won?

    int win1 = 0;
    int win2 = 0;
    int p1move = 1;
    int grid[10] = { 0 };
    int move = 0;

    for (i = 0 ; i < gar; i++)
    {

        move = mas[i];
        if(p1move)
        {
            grid[move] = 1;
            win1 = checkwin(grid);
            p1move = 0;
        }
        else
        {
            grid[move] = -1;
            win2 = checkwin(grid);
            p1move = 1;
        }

        // check if they kept playing after someone won
        // (should also eliminate the case where there are 2 winners)
        if((win1 || win2)&& i<gar-1)
        {
            fprintf(outFile,"NEKOREKTS");
            fclose(outFile);
            return 0;
        }


    }
    //check for unfinished game
    if((!win1 && !win2)&&gar < 9)
    {
        fprintf(outFile,"NEKOREKTS");
        fclose(outFile);
        return 0;
    }
    else
    {
    //check for draw
        if((!win1 && !win2)&&gar == 9)
        {
            fprintf(outFile,"NEVIENS");
            fclose(outFile);
            return 0;
        }
        else
        {
            if(win1)
            {
                fprintf(outFile,"PIRMAIS");
                fclose(outFile);
                return 0;
            }
            else
            {
                if(win2)
                {
                    fprintf(outFile,"OTRAIS");
                    fclose(outFile);
                    return 0;
                }
            }
        }
    }


    // TODO : I don't think we can even get here  ?
    // rework logic to avoid repetitive return statements.
    fclose(outFile);
    return 0;
}

