#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *infile = fopen("vidsk.dat","r+");
    int n, i, j;
    int mas[10009] = {0};
    fscanf(infile, "%d \n", &n);
    for (i = 0 ; i < n; i++)
    {
        fscanf(infile, "%d", &mas[i]);
    }

    int a;
    for (i = 0 ; i < n; i++ )
    {
        for (j = i ; j < n; j++)
        {
            if(mas[i]<mas[j])
            {
                a = mas[i];
                mas[i] = mas[j];
                mas[j] = a;
            }
        }
    }

    fclose(infile);

    FILE *outfile = fopen("vidsk.rez","w+");
    fprintf(outfile, "%d ", mas[n/2]);

    fclose(outfile);
    return 0;
}
