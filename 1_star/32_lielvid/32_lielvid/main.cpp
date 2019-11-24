#include <iostream>

using namespace std;

int main()
{
    FILE *infile = fopen("lielvid.dat", "r+");
    uint32_t n, sum, x;
    fscanf(infile,"%d",&n);

    sum = 0;
    for(int i = 0 ; i < n; i++)
    {
        fscanf(infile,"%d",&x);
        sum += x;
    }

    float avg = sum / n;
    fclose(infile);

    infile = fopen("lielvid.dat", "r+");
    fscanf(infile,"%d",&n);
    uint32_t rez = 0;
    for(int i = 0 ; i < n; i++)
    {
        fscanf(infile,"%d",&x);
        if(x > avg)
            rez++;
    }

    // output
    FILE *outfile = fopen("lielvid.rez", "w+");
    fprintf(outfile, "%d\n",rez);
    fclose(outfile);
    return 0;
}
