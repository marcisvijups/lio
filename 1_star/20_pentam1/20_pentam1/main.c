#include <stdio.h>
#include <stdlib.h>


void drawA(char mas[][9], int x, int y)
{
    mas[y][x] = 'x';
    mas[y+1][x] = 'x';
    mas[y+2][x] = 'x';
    mas[y+2][x+1] = 'x';
    mas[y+2][x+2] = 'x';

}

void drawB(char mas[][9], int x, int y)
{
    mas[y][x] = 'x';
    mas[y][x+1] = 'x';
    mas[y+1][x] = 'x';
    mas[y+1][x+1] = 'x';
    mas[y+2][x] = 'x';
}

void drawC(char mas[][9], int x, int y)
{
    mas[y][x] = 'x';
    mas[y-1][x] = 'x';
    mas[y][x-1] = 'x';
    mas[y][x-2] = 'x';
    mas[y][x-3]= 'x';
}

int main()
{
    FILE *f = fopen("pentam1.in","r+");
    char mas[9][9];
    int n,i,j,x,y;
    char c;
    fscanf(f,"%d\n",&n);

    for(i = 1; i<= 8; i++)
    {
        for(j = 1; j<= 8; j++)
        {
            mas[i][j]='0';
        }
    }

    for(i = 0 ; i < n ; i++)
    {
        fscanf(f,"%c %d %d\n",&c, &x, &y);
        switch (c)
        {
        case 'A':
            drawA(mas,x,8-y+1);
            break;
        case 'B':
            drawB(mas,x,8-y+1);
            break;
        case 'C':
            drawC(mas,x,8-y+1);
            break;
        default:
            printf("Did not recognize shape(Not A, B or C )! \n");
        }

    }
    fclose(f);


    int rez = 0;
    f = fopen("pentam1.out","w+");
    //count the symbols
    for(i = 1; i<= 8; i++)
    {
        for(j = 1; j<= 8; j++)
        {
            //fprintf(f,"%c ",mas[i][j]);
            if(mas[i][j]=='x')
                rez++;
        }
   // fprintf(f,"\n");
    }
    fprintf(f,"%d",rez);
    fclose(f);

    return 0;
}
