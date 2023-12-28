/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 25, 2016, 6:23 PM
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    FILE *inFile = fopen("lacisi.in","r+");
    FILE *outFile = fopen("lacisi.out","w+");
    int n;
    char* line;
    int mas[370] = {0};
    int raksts = 0;
    int rakstusk = 0;
    char c;
    int found = 0;
    fscanf(inFile,"%d",&n);
    int i =0;
    for(i = 0; i < n; i++)
    {
        fscanf(inFile,"%s",line);
        raksts = 0;
        c = *(line+37);
        raksts = (c-48)*1000;
        c = *(line+38);
        raksts =raksts + (c-48)*100;
        c = *(line+39);
        raksts = raksts + (c-48)*10;
        c = *(line+40);
        raksts = raksts + (c-48);
       
        
        int j = 0;
        for ( j = 0; j<=rakstusk;j++)
        {
            if(mas[j]==raksts)
            {
                found = 1;
                break;
            }
        
        }
        if(!found)
        {
            mas[rakstusk] = raksts;
            rakstusk++;
            
        }
        found = 0;
        
    }
    fprintf(outFile,"%d",rakstusk);
    fclose(inFile);
    fclose(outFile);
    return (EXIT_SUCCESS);
}

