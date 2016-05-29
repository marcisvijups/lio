#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *f = fopen("mazsk.in","r+");
    char mas[255];
    fscanf(f,"%s",mas);
    int gar = strlen(mas);
    fclose(f);
    char c;
    int i,j;

// bubble sort
    for(i = 0; i < gar; i++)
    {
        for (j = 0; j < gar; j++)
        {
            if(mas[j] > mas[i])
            {
                c = mas[i];
                mas[i] = mas[j];
                mas[j] = c;
            }
        }
    }

    i = 0;
    //find the first nonzero char
    while(mas[i]=='0' && i<gar)
        i++;

    //swap them
    c = mas[i];
    mas[i] = mas[0];
    mas[0] = c;



    f = fopen("mazsk.out","w+");
    fprintf(f,"%s",mas);
    fclose(f);
    return 0;
}
