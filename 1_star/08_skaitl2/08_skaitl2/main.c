/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 18, 2016, 1:31 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * f = fopen ("skaitl2.in","r+");
    int sk,cip;
    fscanf(f, "%d %d",&sk,&cip);
    fclose(f);
    int dal = 0;
    int found = 0;
    while(!found)
    {

        sk++;
        dal = sk;

        while (dal/10 > 0 || dal%10 > 0)
        {

            if (dal % 10 == cip)
                found = 1 ;
            dal/=10;
        };

    }


    f = fopen ("skaitl2.out","w+");
    fprintf(f,"%d",sk );
    fclose(f);
    return 0;
}
