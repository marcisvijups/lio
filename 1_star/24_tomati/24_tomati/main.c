#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* inFile = fopen("tomati.dat","r+");
    int n, s, d, min, count;
    fscanf(inFile,"%d %d %d", &n, &s, &d);
	fclose(inFile);

	count = 1;

	// kura puse ir mazaaka  ?
	if( n - s < s - 1)
		min = n - s; // pa labi no sarkanaa tomaata
	else
		min = s - 1 ; // pa kreisi no sarkanaa tomaata

	// vairaak kaa viens tomaats ?
	if (n > 1)
	{
	// vai visi tomaati NEnogatavosies mazaakajaa pusee ?
		if (min >= d)
			count+= d * 2;
		else
			count+= d + min;
	}



	FILE * outFile = fopen("tomati.rez", "w+");
	fprintf(outFile, "%d\n",count);
	fclose(outFile);

    return 0;
}
