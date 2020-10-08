#include <iostream>
#include <stdio.h>



using namespace std;

int main()
{
	FILE* infile = fopen("kaulins.dat", "r");
	uint64_t  n;
	int p = 0;
	fscanf(infile,"%d %lld\n",&p, &n);
	fclose(infile);

	n = n % 4;

	FILE* outfile = fopen("kaulins.rez", "w+");
	if(n == 1 || n == 3)
	{
		for(int i = 1 ; i < 7; ++i)
		{
			if((p != i) && (i != 7-p))
				fprintf(outfile,"%d",i);
		}
	}
	else if(n == 2)
	{
		fprintf(outfile,"%d",7-p);
	}
	else
	{
		fprintf(outfile,"%d",p);
	}





	fprintf(outfile, "\n");
	fclose(outfile);

    return 0;
}
