#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inFile = fopen("reklamas.dat","r+");

    fclose(inFile);

	FILE *outFile = fopen("reklamas.rez","w+");
	fprintf(outFile, "lul\n");
	fclose(outFile);
    return 0;
}
