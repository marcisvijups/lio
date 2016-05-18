/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 18, 2016, 1:22 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f = fopen("nauda.in","r+");
    int m,s,p,jm,jp;
    fscanf(f,"%d %d %d",&m ,&s, &p);
    fclose(f);


    m = m* 20 * 12;
    s = s* 12;
    jp = p+ s + m;
    jm = 0;
    while(jp>=100)
    {
        jm++;
        jp-=100;
    }
    f = fopen("nauda.out","w+");
    fprintf(f,"%d %d",jm ,jp);
    fclose(f);
    return 0 ;
}
