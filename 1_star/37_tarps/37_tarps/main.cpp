#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    FILE *infile = fopen("tarps.dat", "r");
    uint32_t n, m, rez;
    fscanf(infile, "%d %d", &m , &n);
    fclose(infile);

    rez = 0;

    uint32_t maz = min(n,m);
    rez = (maz - 1) * 2;

    if (m >n)
        rez++;



    FILE *outfile = fopen("tarps.rez", "w");

    fprintf(outfile, "%d",rez);
    fclose(outfile);
    return 0;
}
