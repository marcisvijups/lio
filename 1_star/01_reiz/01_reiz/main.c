/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on April 28, 2016, 3:45 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE* f = fopen("reiz.in", "r+");
    int n = 0;
    fscanf(f,"%d",&n);
    fclose(f);

    f = fopen("reiz.out","w+");
    fprintf(f,"%d",n*2);
    fclose(f);
    return 0;
}
