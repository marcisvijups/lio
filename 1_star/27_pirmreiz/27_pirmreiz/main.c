#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *infile = fopen("pirmreiz.dat", "r+");
    long int n, x, i, j;
    fscanf(infile, "%ld", &n);
    fclose(infile);

    long int mas[10000];
    int a = 0;
    memset(mas, 0, sizeof(mas));

    FILE *outfile = fopen("pirmreiz.rez", "w+");

    x = 1;
    while(x <= n && n > 1)
    {
        x++;
        if (n % x == 0)
        {
            mas[a] = x;
            a++;
            n = n / x;
            x = 1;

        }
    }
    long int z;


    for(i = 0 ; i <= a; i++)
    {
        z = mas[i];
        for(j = i+1; j < a; j++)
        {
            if(mas[j] == z)
                mas[j] = 0;
        }

    }

    for (i = 0; i < a; i++)
    {
        if(mas[i] && mas[i]!= 1)
            fprintf(outfile, "%ld\n",mas[i]);
    }
    fclose(outfile);
    return 0;
}
