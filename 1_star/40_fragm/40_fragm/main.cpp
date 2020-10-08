#include <iostream>
#include <stdio.h>
#include <inttypes.h>

using namespace std;

int main()
{
    FILE* infile = fopen("fragm.dat","r");
	uint32_t n = 0;
	fscanf(infile,"%d\n", &n);
	uint8_t mas[100005] = {0};
	uint8_t currchar = 0;
	uint32_t sum = 0;
	uint32_t rez = 1;
	for (uint32_t i = 0; i < n ; ++i)
	{
		fscanf(infile,"%c\n",&mas[i]);

		// vai pasreizeejaa virkne turpinaas
		if (currchar == mas[i])
		{
			// ja
			sum++;
		}
		else
		{
			// jauna virkne saakas
			currchar = mas[i];
			sum = 1;

		}
		if(sum>rez)
		{
			// jauna garaakaa virkne atrasta
			rez = sum;
		}
	}
    fclose(infile);






    FILE* outfile = fopen("fragm.rez","w+");
    uint8_t temp_char = mas[0];
	if (mas[0] != mas[n-1] || rez == n)
	{
		// nav jeegas neko griezt..
		fprintf(outfile,"%d\n",rez);
	}
	else
	{
		// griežšana ir tikai deriiga ja pirmais simbols ir vienaads ar peedeejo (un visa virkne nav vienaadi simboli)
		temp_char = mas[0];
		sum = 0;
		int i = 0;
		while(mas[i] == temp_char)
		{
			sum++;
			i++;
		}
		i = n-1;
		while(mas[i] == temp_char)
		{
			sum++;
			i--;
		}

		if(sum > rez)
		{
			// bija jeega kko griezt
			rez = sum;
		}
		fprintf(outfile,"%d\n",rez);
	}
    fclose(outfile);
    return 0;
}
