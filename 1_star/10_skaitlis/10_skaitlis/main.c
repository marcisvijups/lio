/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 25, 2016, 5:09 PM
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int n,m;
    FILE *file = fopen("skaitlis.in","r+");
    fscanf(file,"%d %d", &n, &m);
    fclose(file);
    
    int k = n+1;
    while (k % m != 0)
        k++;
    
    file = fopen("skaitlis.out","w+");
    fprintf(file,"%d",k);
    fclose(file);
    
    return (EXIT_SUCCESS);
}

