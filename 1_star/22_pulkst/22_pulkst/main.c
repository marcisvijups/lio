#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *inFile = fopen("pulkst.dat","r+");
    char mas[6];
    fscanf(inFile,"%s",mas);
    mas[2]=mas[3];
    mas[3]=mas[4];
    mas[4]='\0';
    fclose(inFile);

    FILE *outFile = fopen("pulkst.rez","w+");
    int x = atoi(mas);
    int hh,h,mm,m,i,j,found,rez;
    int mas3[4];
    rez = x;
    int xx = x;
    int mas2[5] = {0};
    mas2[0] = ((x/1000) %10);
    mas2[1] = ((x/100) %10);
    mas2[2] = ((x/10) %10);
    mas2[3] = (x %10);
    int days = 0;

    while(days < 2)
    {
    if (x >= 2359)
    {
        x = 0;
        days++;
    }

    x++;
    hh = ((x/1000) %10);
    h = ((x/100) %10);
    mm = ((x/10) %10);
    m = (x %10);

    found = 0;

    if(mm*10+m > 59)
        continue;



    mas3[0]=hh;
    mas3[1]=h;
    mas3[2]=mm;
    mas3[3]=m;


    for(i = 0; i < 4; i++)
    {

        for(j = 0; j < 4; j++)
        {
            if(mas2[i]==mas3[j])
            {
                mas2[i] = -666;
                mas3[j] = -999;
                found++;
            }
        }

    }
    if (found==4)
    {
        rez = x;
        break;
    }

    mas2[0] = ((xx/1000) %10);
    mas2[1] = ((xx/100) %10);
    mas2[2] = ((xx/10) %10);
    mas2[3] = (xx %10);


    }

    fprintf(outFile,"%d%d:%d%d",(rez/1000%10),(rez/100%10),(rez/10%10),rez%10);
    fclose(outFile);

    return 0;
}
