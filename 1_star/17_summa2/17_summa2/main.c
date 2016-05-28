#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *inFile = fopen("summa2.in","r+");
    char skaitl[102];
    fscanf(inFile,"%s",skaitl);
    int gar = strlen(skaitl);
    int mas[102][102] = {0};
    fclose(inFile);
    int i,j;
    for(i = 0; i<gar;i++)
    {
        for(j = i; j<gar; j++)
        {
            mas[i][j] = skaitl[j]-48; //char to int ASCII
        }
    }


    for(i = 0; i<gar;i++)
    {
        for(j = 0; j<gar; j++)
        {
           mas[gar][i]=mas[gar][i] + mas[j][i];
        }
    }


    int dal = 0;
    for (i = gar-1;i>0;i--)
    {
        dal = mas[gar][i]/10;
        mas[gar][i]=mas[gar][i]%10;
        mas[gar][i-1]=mas[gar][i-1]+dal;
    }

    FILE *outFile = fopen("summa2.out","w+");
   /* for(i = 0; i<=gar;i++)
    {
        for(j = 0; j<=gar; j++)
        {
            fprintf(outFile,"%d ",mas[i][j]);
        }
        fprintf(outFile,"\n");
    }*/
    for (i = 0;i<gar;i++)
    {
        fprintf(outFile,"%d",mas[gar][i]);
    }

    fclose(outFile);

    return 0;
}
