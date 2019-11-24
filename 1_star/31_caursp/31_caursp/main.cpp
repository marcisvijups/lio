#include <iostream>

using namespace std;

static void solver(int32_t hours, int32_t minutes)
{

    //int32_t hh = hours;
    //int32_t mm = minutes;

    hours = 12 - hours;
    if(minutes > 0)
    {
        if (hours >1)
            hours--;
        else
            hours = 0;
    }

    if(hours == 12 && minutes == 0)
    {
        hours = 0;
    }


    minutes = (60 - minutes) % 60;


    FILE *outfile = fopen("caursp.rez", "w+");

    //fprintf(outfile, "%02d:%02d -> %02d:%02d\n",hh, mm,hours, minutes);
    fprintf(outfile,"%02d:%02d\n",hours,minutes);
    //fprintf(outfile,"00:00\n");
    fclose(outfile);
}


int main()
{
    FILE *infile = fopen("caursp.dat","r+");
    int32_t hours, minutes;
    char c;
    fscanf(infile,"%d%c%d", &hours, &c, &minutes);
    fclose(infile);

/*
    for (int i = 0; i<12; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            solver(i,j);
        }
    }
*/
    solver(hours,minutes);


}
