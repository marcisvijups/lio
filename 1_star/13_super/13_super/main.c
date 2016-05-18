/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 18, 2016, 2:21 PM
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("super.in","r+");
    int gar1 , gar2;
    gar1 = gar2 = 0;
    int mas[5][5] = {0};

    char c;
    while (c != '\n')
    {
        fscanf(f,"%1c",&c);
        if (c != '\n')
        {
            mas[0][gar1] = c;
            mas[0][gar1] -=48;
            gar1++;
        }

    }

    do
    {
        fscanf(f,"%1c",&c);
        if (c != '\n')
        {
            mas[0][gar2] = c;
            mas[0][gar2] -=48;
            gar2++;
        }

    }while (c != '\n');


    fclose(f);
     int i , j ;

    for (i = 0 ; i < gar1-1 ; i++)
    {
        printf("%d",mas[i][0]);
    }


    f = fopen("super.out","w+");
    fclose(f);

    return 0;
}
