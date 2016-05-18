/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 18, 2016, 1:34 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f = fopen("summa.in","r+");
    int mas[10] = {0};
    int n;
    fscanf(f,"%d",&n);
    fclose(f);

    int len = 0;
    int cip,cipsum =0;

    while(n/10 || n%10)
    {
        //logic
        cip = n%10;
        n/=10;
        len++;
        cipsum +=cip;
    }

    int i;

    for (i = 0; i< len; i++)
    {
        mas[i] = cipsum;
    }

    int x ;

    for (i = len-1 ; i>0 ; i--)
    {
        x = mas[i];
        if (x>= 10)
        {
            x = x/ 10 ;
            mas[i] = mas[i]%10;
            mas[i-1]+=x;
        }

    }



    f = fopen("summa.out","w+");
    for(i = 0 ; i < len ;i++ )
    {
        fprintf(f,"%d",mas[i]);
    }
    fclose(f);
    return 0;
}
