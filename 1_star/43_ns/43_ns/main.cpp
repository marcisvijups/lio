#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    FILE* infile = fopen("ns.dat","r");
    char mas[10][10] = {0};

    for(int i = 0 ; i < 8; ++i)
    {
		fscanf(infile,"%s\n",&mas[i][0]);
    }
    fclose(infile);

	uint16_t sum = 0;
	for(uint32_t i = 0 ; i < (uint32_t)strlen(&mas[0][0]);++i)
    {
		sum = 0;
		int j =0;
		for(j = 0 ; j < 8; ++j)
		{
			sum += (mas[j][i] - '0');
		}
		mas[8][i] = (char)((45-sum) + '0');
    }



    FILE* outfile = fopen("ns.rez", "w");
    fprintf(outfile, "%s\n",&mas[8][0]);
    fclose(outfile);
    return 0;
}
