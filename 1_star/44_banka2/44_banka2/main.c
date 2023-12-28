#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    FILE* infile = fopen("banka2.dat", "r");
    int bankas_vecums = 0;
    int klienta_gadi = 0;
    int darijumu_skaits = 0;
    uint64_t Summa_saakumaa;
	fscanf(infile, "%d %d %lld\n", &bankas_vecums, &klienta_gadi, &Summa_saakumaa);
	fscanf(infile, "%d\n", &darijumu_skaits);
	char c = 0;
	int multiplier = bankas_vecums - klienta_gadi + 1;

	int cnt = 0;
	uint64_t curr_amount = 0;
	int i = 0;
	for( i = 0; i < darijumu_skaits; ++i)
	{
		fscanf(infile,"%c",&c);
		fscanf(infile,"%lld\n",&curr_amount);
		if(c == '-')
		{
			Summa_saakumaa -= curr_amount;
		}
		else
		{
			cnt++;
			if(cnt == multiplier)
			{
				curr_amount = curr_amount * 2;
				cnt = 0;
			}
			Summa_saakumaa += curr_amount;
		}

	}

    fclose(infile);


    FILE* outfile = fopen("banka2.rez", "w");
    fprintf(outfile,"%lld\n", Summa_saakumaa);
    fclose(outfile);

    return 0;
}
