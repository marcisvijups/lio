/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 18, 2016, 12:31 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int n,i,cipsum, cipreiz,gar,x,y,cip;
    FILE * f = fopen("sumreiz.in","r+");
    fscanf(f,"%lu",&n);
    fclose(f);
    x = n;
    i = 0;

    while(i<x)
    {
        gar = 0;
        i++;
        y = n;
        cipsum = 0;
        cipreiz =1 ;
        while (y)
        {
            cip = y % 10;
            y = y/ 10 ;
            gar++ ;
            cipsum = cipsum + cip;
            cipreiz = cipreiz  * cip;
        }
        n = n + cipsum + cipreiz;
    }
    f = fopen("sumreiz.out","w+");
    fprintf(f,"%lu",n);
    fclose(f);
    return 0;
}

