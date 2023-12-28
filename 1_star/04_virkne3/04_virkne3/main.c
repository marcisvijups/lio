/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 25, 2016, 1:46 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    FILE *inputFile, *outputFile;
    inputFile = fopen("virkne3.in","r+");
    outputFile = fopen("virkne3.out","w+");
    char buf[255];
    fscanf(inputFile,"%s",&buf);
    fclose(inputFile);
    char c;
    int i = 0;
    while( buf[i]!='\0')
    {
        c = buf[i];
        while (c == buf[i] && buf[i]!='\0')
            i++;
        
        fprintf(outputFile,"%c",c);
    }
    fclose(outputFile);
    return 0;
}

