#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long long int n, k, m, lapas_sodien, lapas_kopa;

    FILE *inFile = fopen("reklamas.dat","r+");
	fscanf(inFile, "%llu %llu %llu",&n, &k, &m);
    fclose(inFile);

    int dienas = 1;
    lapas_kopa = n;


    while(lapas_kopa < m)
	{
		dienas++;
		lapas_sodien = n + k;
		n = lapas_sodien;
		lapas_kopa = lapas_kopa + lapas_sodien;

	}
	FILE *outFile = fopen("reklamas.rez","w+");
	fprintf(outFile, "%d\n", dienas);
	fclose(outFile);
    return 0;
}
