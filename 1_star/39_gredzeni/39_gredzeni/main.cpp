#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <inttypes.h>
#include <stdbool.h>


using namespace std;

int main()
{
    FILE *infile = fopen("gredzeni.dat","r+");
    int32_t diametrs, d1ieks, d1ar, d2ieks, d2ar;
    fscanf(infile, "%d\n%d %d\n%d %d\n",&diametrs, &d1ieks, &d1ar, & d2ieks, &d2ar);
    fclose(infile);


    FILE *outfile = fopen("gredzeni.rez","w+");



	// var salikt vienu rinki otram blakus
	if ((d2ar + d1ar) <= diametrs)
	{
		fprintf(outfile, "ABUS\n");
		return 0;
	}
	// vai var vienu rinki ielikt otrā un lielākais mazāks par kopējo?
	else if ((d1ar <= diametrs && d1ieks >= d2ar) ||
			d2ar <= diametrs && d2ieks >= d1ar)
	{
		fprintf(outfile,"ABUS\n");
		return 0;
	}
	// abus vienlaiciigi nevarees izgriezt, bet vai var izgriezt abus pa "vienam"
	else if(diametrs >= d1ar && diametrs >= d2ar)
	{
		fprintf(outfile,"VIENU\n");
		return 0;
	}
	// vismaz vienu nevar vispaar izgriezt... vai vismaz pirmo var?
	else if(diametrs >= d1ar)
	{
		fprintf(outfile,"PIRMO\n");
		return 0;
	}
	// pirmo noteikti nevar izgriezt, vai vismaz otro var izgriezt?
	else if (diametrs >= d2ar)
	{
		fprintf(outfile,"OTRO\n");
		return 0;
	}
	else
	{
		// nevinu nevar izgriezt :(
		fprintf(outfile,"NEVIENU\n");
		return 0;
	}


    //fprintf(outfile, "%d\n%d %d\n%d %d\n", diametrs, d1ieks, d1ar, d2ieks, d2ar);
    fclose(outfile);
    return 0;
}
