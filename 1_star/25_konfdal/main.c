#include <stdio.h>

int carCount(int n , int k, int m)
{
    int atl = n % (m + k);
    int rez = (n / (m + k)) * 2;

    if (atl == 0)
        return rez;

    if (atl <= k)
        rez = rez + 1;
    else
        rez = rez  +2;
    return rez;
}

int main(void)
{
    int n, k, m, rez;
    FILE *infile = fopen("konfdal.dat", "r+");
    fscanf(infile,"%d %d %d", &n , &k, &m);
    fclose(infile);


    FILE *outfile = fopen("konfdal.rez", "w+");
    fprintf(outfile, "%d", carCount(n,k,m));
    return 0;
}
