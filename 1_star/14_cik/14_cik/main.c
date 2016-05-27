/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 26, 2016, 2:25 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) 
{
    FILE *inFile = fopen("cik.in","r+");
    FILE *outFile = fopen("cik.out","w+");
    int x,y; 
    
    fscanf(inFile,"%d %d",&x,&y);
    fclose(inFile);
    
    int rez = x;
    do
    {
        x++;
        if (x%10 == y)
            break;
        if (((x/10)%10 == y)&& (x>=10))
            break;
        if (((x/100)%10 == y)&& (x>=100))
            break;
        if (((x/1000)%10 == y)&& (x>=1000))
            break;
        if (((x/10000)%10 == y)&& (x>=10000))
            break;
        if (((x/100000)%10 == y)&& (x>=100000))
            break;
        if (((x/1000000)%10 == y)&& (x>=1000000))
            break;
        if (((x/10000000)%10 == y)&& (x>=10000000))
            break;
        if (((x/100000000)%10 == y)&& (x>=100000000))
            break;
        if (((x/1000000000)%10 == y)&& (x>=1000000000))
            break;
    }while(1);
    fprintf(outFile,"%d",x-rez);
    fclose(outFile);
    return (EXIT_SUCCESS);
}

