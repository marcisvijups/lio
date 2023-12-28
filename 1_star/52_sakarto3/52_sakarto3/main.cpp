#include <iostream>
#include <stdio.h>
#include <inttypes.h>

using namespace std;

int main()
{
	FILE* infile = fopen("sakarto3.dat", "r+");
	int32_t sk1, sk2, sk3;
	fscanf(infile,"%d %d %d\n", &sk1, &sk2, &sk3);
    fclose(infile);



    FILE* outfile = fopen("sakarto3.rez", "w+");
	if (sk1 <= sk2 && sk1 <= sk3)
	{
		if(sk2 <= sk3)
		{
			fprintf(outfile, "%d %d %d\n",sk1, sk2, sk3);
		}
		else
		{
			fprintf(outfile, "%d %d %d\n",sk1, sk3, sk2);
		}
	}
	else if (sk2 <= sk1 && sk2 <= sk3)
	{
		if(sk1 <= sk3)
		{
			fprintf(outfile, "%d %d %d\n",sk2, sk1, sk3);
		}
		else
		{
			fprintf(outfile, "%d %d %d\n",sk2, sk3, sk1);
		}
	}
	else
	{
		if(sk1 <= sk2)
		{
			fprintf(outfile, "%d %d %d\n",sk3, sk1, sk2);
		}
		else
		{
			fprintf(outfile, "%d %d %d\n",sk3, sk2, sk1);
		}
	}
    fclose(outfile);
    return 0;
}
