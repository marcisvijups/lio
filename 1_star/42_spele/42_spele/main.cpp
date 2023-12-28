#include <iostream>
#include <stdlib.h>
using namespace std;





int main()
{
    FILE* infile = fopen("spele.dat","r");

    int n = 0;
    int punkti1, punkti2, punkti3;
    punkti1 = 0;punkti2 =0;punkti3 =0;
    int karts1, karts2, karts3;
    fscanf(infile,"%d\n",&n);

    for (int i = 0; i < n; ++i)
    {
		fscanf(infile, "%d %d %d\n",&karts1, &karts2, &karts3);

		// vai ir atskiriigi?
		if(karts1 != karts2 && karts2 != karts3 && karts1 != karts3)
		{
			if(karts1 > karts2 && karts1 > karts3)
			{
				// pirmais sanjem punktu
				punkti1++;
			}
			else if(karts2 > karts1 && karts2 > karts3)
			{
				// otrajam ir vislielaakaa kaarts
				punkti2++;
			}
			else
				punkti3++;
		}
		else if (karts1 == karts2 && karts3 != karts1)
			punkti3++;
		else if(karts1 == karts3 && karts2 != karts1)
			punkti2++;
		else if(karts2 == karts3 && karts1 != karts3)
			punkti1++;

    }
    fclose(infile);


    FILE* outfile = fopen("spele.rez","w+");
    fprintf(outfile, "%d %d %d\n",punkti1, punkti2, punkti3);
    fclose(outfile);
    return 0;
}
